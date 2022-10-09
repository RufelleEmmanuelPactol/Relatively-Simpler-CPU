#ifndef memory_h
#define memory_h
#include "lib.h"



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
    int * commandList; //stores all commands
    char * errorString; // stores all errors
    char ** error; //index pointer to errors
    int commandAC; //stores which index the last command is at
    int errorAC; //stores which index the last error is at
    Memory (){
        RAM = new int[256*8];
        AC = new int[8];
        R = new int[8];
        Z = 0;
        commandList = new int[256*8];
        errorString = new char[100*100];
        error = new char*[100];
        commandAC = 0;
        errorAC = 0;

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
        for (int i=0; i<capacity; i++){
            commandList[i] = 0;
        }
        for (int i=0; i<100; i++){
            error[i] = errorString+(i*100);
        }

    }

};




#endif