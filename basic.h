#pragma once
#include "lib.h"
#include "numsys.h"
#include "debug.h"


class Basic{
    NumSys * numsys;
    Memory * memory;
    Debug * debug;
public:
    Basic(){

    }
    Basic (Memory * local){
        memory = local;
        numsys = new NumSys(memory);
        debug = new Debug(memory);
    }

    void PUTS (int num, int address){
        if (address>255){
            std::cout << "error assembling, selected address " << address << " beyond bounds.";
            exit(42);
            return;
        }
        int * arr = new int[8];
        numsys->decimalToBinary(num, arr);
        int * target = memory->RAM+(address*8);
        for (int i=0; i<8; i++){
           *(target+i) = *(arr+i);
        }
        return;

    }

    int * GETS (int address){
        return memory->RAM+(address*8);
    }

    int ADD (int * a, int * b){
        int op1, op2;
        op1 = numsys->binaryToDecimal(a);
        op2 = numsys->binaryToDecimal(b);
        if (op1+op2>255){
            memory->Z = 1;
        }
        return (op1+op2)%256;

    }

    void SAVE (int * num, int address){
        int n = numsys->binaryToDecimal(num);
        PUTS(n, address);
        return;
    }

};