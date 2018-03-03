# AnnePro Keyboard Firmware
Understanding how the Anne Pro keyboard works

```shell
$ r2 -a arm -b 16 -m 0x08004000 -i key.r2 <image_from_1.40_key_dfu>
```

The see what the keyboard's bootloader does, you can run:

```shell
$ r2 -a arm -b 16 -m 0x08000000 -i key_bootloader.r2 <key_bootloader_image>
```

## Hardware

The Anne Pro contains 3 MCUs to handle each of the Keyboard, LED and BLE operations.

- Keyboard MCU: STM32L151C8T6
- LED      MCU: STM32L151C8T6
- BLE      MCU: TI CC2541

The USB charging circtuit is a: BQ24075

### GPIOs
For the keyboard MCU GPIO wiring, see `gpios.csv`

## Firmware

### Extracting images from dfu files

### Flashing dfu or raw images


## Layouts

The Anne Pro supports three predefined layouts and a custom one configured via the app.

The main layout (layout 1) resides on the firmware image (after extraction from the dfu binary) starting at offset 0x68b2 and is an array of 70 bytes.
Each byte is the USB HID scan code of a key in this order:

`ESC, 1, 2, 3, ..., Fn, Anne, RightCtrl`

[See this github gist for a full list of key codes](https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2)

### Layout dirty patching

An example would be replacing the Caps key with "`", the caps key can still be accessed using Fn.

```shell
printf '\x35' | dd of=<extracted_key_fw_image> bs=1 seek=26830 count=1 conv=notrunc
```
Where `26830 = 0x68b2 + d29` is the position of the CapsLock key

The patched image can either be repackeged into a DFU format or patched directly to the keyboard at address 0x8004000.

A single byte patch is also possible I guess.

To replace other keys, just find their USB HID codes in the layout array and replace them with the new ones.

## LED/BLE communication 

### Message Header

| 8bit | 8bit | 1bit | 7bit | Size-1 bytes |
|:----:|------|------|------|------|
| Type | Size | ACK  | CMD  | Data |

#### Type

Defines the message type.

#### Size

Defines the message size including the ACK:CMD byte.

#### CMD

Defines a specific command within the type.

#### ACK

The ACK bit is set when a message is a reply.

---
**Note**

For a partial list of what the Type and CMD can be, have a look at [https://github.com/metr1xx/anne-pro-community-app](https://github.com/metr1xx/anne-pro-community-app/blob/master/com/obins/anne/utils/Msgprotocol.java)

---

### Message Data

The rest of the message is the data of size (SIZE - 1)

The data portion can take several formats which depend on the TYPE and CMD chosen

## Sample messages

LED message when the anne is instructed to connect to host 1 in BLE mode:

```
09 35 0b ca 0a   type:9  size:53 cmd:11      ?:202 keys:10
00 ff ff 00 01   key:Esc color:Y
01 00 ff 00 02   key:1   color:G mode:flash
02 ff 00 00 01   key:2   color:R
03 ff 00 00 01   key:3   color:R
04 ff 00 00 01   key:4   color:R
0c 00 ff 00 01   key:+   color:G
2f 00 ff 00 02   key:B   color:G mode:flash
0b ff 00 00 01   key:-   color:R
0a 00 ff 00 01   key:0   color:G
1d 00 ff 00 01   key:A   color:G 

message header 09 35 0b
command header ca 0a
Payload format => key:byte color:3bytes mode:byte
```

Another example would be the message that tells the LED MCU which key has been pressed:

```
09   0b   07  00 00 00 00 00 00 00 00 08 00      fn pressed
Type Size Cmd Data

Data is a 10 byte array where each byte represents the state of 8 keys. Each bit is the state of key.
```

## Dumping messages if you have an STLink

Before being sent to the destination MCU using USART/DMA, the messages are put in 2 buffers of 256 bytes each:
- The BLE message buffer is at `0x200007d4`
- The LED message buffer is at `0x200016a8`

## Generating an HTML listing of the disassembly

To generate a nice html listing you first need to dump the disassembly to a text file. Run the following commands in radare2's prompt

```
[0x08004000]> aar                                   
[0x08004000]> pD 27266 > listing.txt
```

Then you can use the script at `utils/disasm2htm.py` to generate a nice `listing.htm` file. All thanks go to the [MD380 project](https://github.com/travisgoodspeed/md380tools)

```sh
$ python utils/disasm2htm.py listing
```
A current listing can be found at [https://hi-a.github.io/annepro-key/](https://hi-a.github.io/annepro-key/)
