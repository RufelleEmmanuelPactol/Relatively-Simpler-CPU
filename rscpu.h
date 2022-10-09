#ifndef ran_h
#define ran_h

#include "macro.h"
#include "lib.h"

class Rscpu {
    int * binaryArray;
    Memory * memory;
    Display * display;
    NumSys * numsys;
    Basic * basic;
    Debug * debug;
    Commands * commands;

public:
    Rscpu(){
        memory = new Memory();
        display = new Display(memory);
        numsys = new NumSys(memory);
        binaryArray = new int[8];
        debug = new Debug(memory);
        basic = new Basic(memory);
    }
    Rscpu(Memory * memory1){
        memory = memory1;
        display = new Display(memory);
        numsys = new NumSys(memory);
        binaryArray = new int[8];
        debug = new Debug(memory);
        basic = new Basic(memory);
    }

    void seeMemoryID(){ //display.h
        display->seeMemoryID();
    }

    int binaryToDecimal(int * arr){ // numsys.h
        return numsys->binaryToDecimal(arr);
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

    void printArray (int * arr, int size){ //debug.h
        debug->printArray(arr, size);
    }

    int digits (int num){ //numsys.h
        return numsys->digits(num);
    }

    void PUTS (int num, int address){
        basic->PUTS(num, address);
    }

    int * GETS (int address){
        return basic->GETS(address);
    }

    void seeZ (){
        return display->seeZ();
    }

    int ADD (int * a, int * b){
        return basic->ADD(a, b);
    }

    void SAVE (int * num, int address){
        return basic->SAVE(num, address);
    }

    void TOAC (){
        return basic->TOAC();
    }

    void TOR(){
        return basic->TOR();
    }

    void numToAC(int * arr){
        return memory->numToAC(arr);
    }

    void seeR(){
        return display->seeR();
    }

    void seeAC(){
        return display->seeAC();
    }

    void seePC(){
        return display->seePC();
    }

    void ORG(int num){
        return basic->ORG(num);
    }


};

#endif