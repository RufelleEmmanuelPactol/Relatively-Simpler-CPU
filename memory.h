#ifndef memory_h
#define memory_h
#include "lib.h"
const int capacity = 256*8;



/*
 * TBD:
 * errorString
 * commandList
 * error ptr
 * errorAC
 * commandAC
 */

class Memory {
public:
    int * RAM;
    int * AC;
    int * R;
    int Z;
    int PC;
    int AR;
    int line;
    Memory (){
        RAM = new int[256*8];
        AC = new int[8];
        R = new int[8];
        AR = 0;
        Z = 0;
        PC = 0;
        line = 1;


        clearMemoryAll();
    }

    void clearMemoryAll(){
        Z = 0;
        for (int i=0; i<capacity; i++){
            *(RAM+i) = 0;
        }
        for (int i=0; i<8; i++){
            *(AC+i) = 0;
        }

        for (int i=0; i<8; i++){
            *(R+i) = 0;
        }
        AR = 0;
        PC = 0;

    }

    void numToAC (int * arr){
        for (int i=0; i<8; i++){
            *(AC+i) = *(arr+i);
        }
    }

};




#endif
