/*
 * main loop
 *
 */

#include "headers.h"

int16_t EXTl_Counter;
char PWR_SaveMode, VAR_782;

void _Keyboard_Init(){

}

int func_0x800577a(){

}

void _Scan_Matrix(0x200017a8){

}

int func_xxxx(int16_t *Struct_2_VAR_18a4){

    if((Struct_2_VAR_18a4 == 0 && PWR_SaveMode == 0) || (Struct_2_VAR_18a4 == 0 && PWR_SaveMode != 0 && VAR_782 != 2) || Struct_2_VAR_18a4 == 0x92){
        Struct_2_VAR_18a4 = 0x92

        if(EXTl_Counter == 0){
            return 0;

        } else {
            res = func_0x800577a();

            if(res == 0){
                _Scan_Matrix(args);
                _Parse_Matrix(args);
                EXTl_Counter = 0;

                for(int i=0; i<5; i++){
                    if(VAR_1834 == 0){
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
                if(VAR_1834 == 0){
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

void fcn.08008d74(Struct_2){
    if(Struct_2_VAR_18bc == 0){
        Struct_2_VAR_18bc = 0x35c;
        if(USB_Plugged_EXTl == 0){
            return 0;
        } else {
            _PWR_SaveMode_FlagUpdate();
            if(PWR_SaveMode == 0){
                if(VAR_782 == 2){
                    if(PWR_SaveMode == 0){
                        
}

void main_loop(){
    int16_t Struct_2 = {0};

    func_xxxx(Struct_2_VAR_18a4);
    // ....
    fcn.08008d74(Struct_2_VAR_18bc);
    // ....
}

int main(){

    // initialize peripherals, clocks and gpios
    _Keyboard_Init();

    // keyboard scan loop
    main_loop();

    return 0;
}
