/*
 * main loop
 *
 */

#include "headers.h"

int16_t EXTl_Counter;
char PWR_SaveMode, VAR_782;

void _KBD_Init(){

}

int _BLE_IsMsgPending(){

}

void _Scan_Matrix(0x200017a8){

}

int _KBD_StateUpdate(int16_t *Struct_2_VAR_18a4){

    if((Struct_2_VAR_18a4 == 0 && PWR_SaveMode == 0) || (Struct_2_VAR_18a4 == 0 && PWR_SaveMode != 0 && VAR_782 != 2) || Struct_2_VAR_18a4 == 0x92){
        Struct_2_VAR_18a4 = 0x92

        if(EXTl_Counter == 0){
            return 0;

        } else {
            res = _BLE_IsMsgPending();

            if(res == 0){
                _Scan_Matrix(args);
                _Parse_Matrix(args);
                EXTl_Counter = 0;

                for(int i=0; i<5; i++){
                    if(ROW1_BS == 0){
                       continue;

                    } else {
                        EXTl_Counter = 1;
                        Struct_2_VAR_18a4 = 0xb3;
                        return 1;
                    }
                }

                if(EXTl_Counter == 0)
                    _MatrixColumns_Set();

                Struct_2_VAR_18a4 = 0xb3;
                return 1;
                
            } else {
                return 0;
            }
        }

    } else if((Struct_2_VAR_18a4 == 0 && PWR_SaveMode != 0 && VAR_782 == 2) || Struct_2_VAR_18a4 == 0x90) {
        Struct_2_VAR_18a4 = 0x90;

        if(EXTl_Counter == 0){
            return 0;
        } else {
            _Scan_Matrix(args);
            _Parse_Matrix(args);
            EXTl_Counter = 0;

            for(int i=0; i<5; i++){
                if(ROW1_BS == 0){
                   continue;

                } else {
                    EXTl_Counter = 1;
                    Struct_2_VAR_18a4 = 0xb3;
                    return 1;
                }
            }

            if(EXTl_Counter == 0)
                _MatrixColumns_Set();

            Struct_2_VAR_18a4 = 0xb3;
            return 1;
        } 
    } else {
        Struct_2_VAR_18a4 = 0;
        return 3;
    }
}

void _KBD_PWRManage(Struct_2){
    if(Struct_2_VAR_18bc == 0){
        Struct_2_VAR_18bc = 0x35c;
        if(USB_Plugged_EXTI == 0){
            return 0;
        } else {
            _KBD_USBPlugCheck();
            if(PWR_SaveMode == 0){
                if(VAR_782 == 2){
                    if(PWR_SaveMode == 0){
                        
}

void main_loop(){
    int16_t Struct_2 = {0};

    _KBD_StateUpdate(Struct_2_VAR_18a4);
    // ....
    _KBD_PWRManage(Struct_2_VAR_18bc);
    // ....
}

int main(){

    // initialize peripherals, clocks and gpios
    _KBD_Init();

    // keyboard scan loop
    main_loop();

    return 0;
}
