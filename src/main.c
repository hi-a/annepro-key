/*
 * main loop
 *
 */

#include "headers.h"

int16_t EXTl_Counter;
char FLAG_1, VAR1;

void _Keyboard_Init(){

}

int func_0x800577a(){

}

void _Scan_Matrix(0x200017a8){

}

int func_xxxx(int16_t *arr){

    switch(arr[0]){
        case 0:

            if(FLAG_1 == 0){
                arr[0] = 0x92

                if(EXTl_Counter == 0){
                    return 0;

                } else {
                    res = func_0x800577a();

                    if(res == 0){
                        _Scan_Matrix(args);
                        func_0x8007ce6(args);
                        EXTl_Counter = 0;

                        for(int i=0; i<5; i++){
                            if(X == 0){
                               continue;
 
                            } else {
                                EXTl_Counter = 1;
                                arr[0] = 0xb3;
                                return 1;
                            }
                        }

                        if(EXTl_Counter == 0)
                            _MatrixColumns_Set();

                        arr[0] = 0xb3;
                        return 1;
                        
                    } else {
                        return 0;
                    }
                }

            } else {
                if(VAR1 == 2){
                    arr[0] = 0x90;

                    if(EXTl_Counter == 0){
                        return 0;
                    } else {
                        _Scan_Matrix(args);
                        func_0x8007ce6(args);
                        EXTl_Counter = 0;

                        for(int i=0; i<5; i++){
                            if(X == 0){
                               continue;
 
                            } else {
                                EXTl_Counter = 1;
                                arr[0] = 0xb3;
                                return 1;
                            }
                        }

                        if(EXTl_Counter == 0)
                            _MatrixColumns_Set();

                        arr[0] = 0xb3;
                        return 1;
                    } 
                } else {

                    arr[0] = 0x92

                    if(EXTl_Counter == 0){
                        return 0;

                    } else {
                        res = func_0x800577a();

                        if(res == 0){
                            _Scan_Matrix(args);
                            func_0x8007ce6(args);
                            EXTl_Counter = 0;

                            for(int i=0; i<5; i++){
                                if(X == 0){
                                   continue;
     
                                } else {
                                    EXTl_Counter = 1;
                                    arr[0] = 0xb3;
                                    return 1;
                                }
                            }

                            if(EXTl_Counter == 0)
                                _MatrixColumns_Set();

                            arr[0] = 0xb3;
                            return 1;
                            
                        } else {
                            return 0;
                        }
                    }

                }
            }

            break;

        case 0x90:
            if(EXTl_Counter == 0){
                return 0;

            } else {
                _Scan_Matrix(args);
                func_0x8007ce6(args);
                EXTl_Counter = 0;

                for(int i=0; i<5; i++){
                    if(X == 0){
                       continue;

                    } else {
                        EXTl_Counter = 1;
                        arr[0] = 0xb3;
                        return 1;
                    }
                }

                if(EXTl_Counter == 0)
                    _MatrixColumns_Set();

                arr[0] = 0xb3;
                return 1;
            }
            break;

        case 0x92:
            if(EXTl_Counter == 0){
                return 0;

            } else {
                res = func_0x800577a();

                if(res == 0){
                    _Scan_Matrix(args);
                    func_0x8007ce6(args);
                    EXTl_Counter = 0;

                    for(int i=0; i<5; i++){
                        if(X == 0){
                           continue;

                        } else {
                            EXTl_Counter = 1;
                            arr[0] = 0xb3;
                            return 1;
                        }
                    }

                    if(EXTl_Counter == 0)
                        _MatrixColumns_Set();

                    arr[0] = 0xb3;
                    return 1;
                    
                } else {
                    return 0;
                }
            }

            break;

        arr[0] = 0;
        return 3;
    }
}

void main_loop(){
    int16_t arr_0x200018a4[7] = {0};

    func_xxxx(int16_t arr_0x200018a4);
    // ....
}

int main(){

    // initialize peripherals, clocks and gpios
    _Keyboard_Init();

    // keyboard scan loop
    main_loop();

    return 0;
}
