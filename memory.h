#pragma once
#include "lib.h"
#include "basic.h"


class Memory {
public:
    int * RAM;
    int * AC;
    int * R;
    Memory (){
        RAM = new int[256*8];
        AC = new int[8];
        R = new int[8];
        clearMemoryAll();
    }

    void clearMemoryAll(){
        for (int i=0; i<capacity; i++){
            *(RAM+i) = 0;
        }
        for (int i=0; i<8; i++){
            *(AC+i) = 0;
        }

        for (int i=0; i<8; i++){
            *(R+i) = 0;
        }
    }

};
