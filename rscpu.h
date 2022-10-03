#ifndef ran_h
#define ran_h

#include "macro.h"
#include "lib.h"

class Rscpu {

    Memory * memory;
    Display * display;
    NumSys * numsys;

public:
    Rscpu(){
        memory = new Memory();
        display = new Display(memory);
        numsys = new NumSys(memory);

    }

    void seeMemoryID(){
        display->seeMemoryID();
    }

    int toDecimal(int * arr, int size){
        return numsys->toDecimal(arr, size);
    }

    char toHex(int * arr){
        return numsys->toHex(arr);
    }

    void seeMemoryHex (){
        display->seeMemoryHex();
    }
};

#endif