#ifndef ran_h
#define ran_h

#include "macro.h"
#include "lib.h"

class Rscpu {
    int * binaryArray;
    Memory * memory;
    Display * display;
    NumSys * numsys;

public:
    Rscpu(){
        memory = new Memory();
        display = new Display(memory);
        numsys = new NumSys(memory);
        binaryArray = new int[8];

    }

    void seeMemoryID(){ //display.h
        display->seeMemoryID();
    }

    int toDecimal(int * arr, int size){ // numsys.h
        return numsys->toDecimal(arr, size);
    }

    char toHex(int * arr){  //numsys.h
        return numsys->toHex(arr);
    }

    void seeMemoryHex (){ //display.h
        display->seeMemoryHex();
    }

    int * decimalToBinary (int n){ //numsys.h
        int * arr = new int[8];
        numsys->decimalToBinary(n, arr);
        for (int i=0; i<8; i++){
            binaryArray[i] = arr[i];
        }
        return binaryArray;

    }

    int arrayToInt (int * arr, int size){ //numsys.h
        int result = numsys->arrayToInt(arr, size);
        return result;
    }

    void printArray (int * arr, int size){
        numsys->printArray(arr, size);
    }

    int digits (int num){
        return numsys->digits(num);
    }
};

#endif