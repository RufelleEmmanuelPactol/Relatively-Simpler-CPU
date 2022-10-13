//
// Created by Rufelle on 13/10/2022.
//

#ifndef UNTITLED7_ADVANCE_H
#define UNTITLED7_ADVANCE_H
#include "lib.h"
#include "memory.h"
#include "numsys.h"
#include "basic.h"
#include <cmath>
class Advanced {
    Memory * memory;
    NumSys * numsys;
    Basic * basic;
public:
    Advanced(Memory * local){
        memory = local;
        numsys = new NumSys(memory);
        basic = new Basic (memory);
    }

    void JUMP (int num){
        memory->AR = num;
        memory->PC = num;
        basic->ORG(num);
        //std::cout << "JUMPED! NOW AT " << memory->AR <<std::endl;
    }

    void JNEG (int num){
        if (memory->Z==0){
            return JUMP(num);
        }
        return;
    }

    void JPOS (int num){
        if (memory->Z){
            return JUMP(num);
        }
        return;
    }

    void COMP (){
        int a = numsys->binaryToDecimal(memory->AC);
        int b = numsys->binaryToDecimal(memory->R);
        if (a>b){
            memory->Z = 0;
        }
        else{
            memory->Z = 1;
        }
        return;
    }

    void EQUA (){
        int a = numsys->binaryToDecimal(memory->AC);
        int b = numsys->binaryToDecimal(memory->R);
        if (a==b){
            memory->Z = 0;
        }
        else{
            memory->Z = 1;
        }
        return;
    }

    void SUB (){
        int a = numsys->binaryToDecimal(memory->AC);
        int b = numsys->binaryToDecimal(memory->R);
        if (b>a){
            int temp = a-b;
            temp = abs(temp);
            temp = 256-temp;
            memory->Z = 1;
            int  arr[8];
            numsys->decimalToBinary(temp, arr);
            memory->numToAC(arr);
            return;
        }
        int temp = a-b;
        memory->Z = 0;
        int arr[8];
        numsys->decimalToBinary(temp, arr);
        memory->numToAC(arr);
        return;
    }

    void MULT (){
        int a = numsys->binaryToDecimal(memory->AC);
        int b = numsys->binaryToDecimal(memory->R);
        int temp;
        if (a*b>255){
            temp = (a*b)%255;
            memory->Z = 1;
        }
        else{
            temp = a*b;
        }
        int arr[8];
        numsys->decimalToBinary(temp, arr);
        memory->numToAC(arr);
        return;
    }

    void EXP (){
        int a = numsys->binaryToDecimal(memory->AC);
        int b = numsys->binaryToDecimal(memory->R);
        int temp;
        int num =pow(a, b);
        if (num>255){
            temp = num % 255;
            memory->Z = 1;
        }
        temp = num;
        int arr[8];
        numsys->decimalToBinary(temp, arr);
        memory->numToAC(arr);
    }

    void NOT (){
        if (memory->Z==1){
            memory->Z=0;
            return;
        }
        memory->Z = 1;
        return;
    }

};

#endif //UNTITLED7_ADVANCE_H
