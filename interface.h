//
// Created by Rufelle on 09/10/2022.
//
#include "rscpu.h"


#ifndef UNTITLED7_INTERFACE_H
class Interface {
    Memory * memory;
    Rscpu * rscpu;
    int * PC;
public:

    Interface () {
        memory = new Memory();
        rscpu = new Rscpu(memory);
        PC = &(memory->PC);
    }

    Memory * getMemory (){
        return memory;
    }

    void ADD (){
        int res = rscpu->ADD(memory->AC, memory->R);
        int * arr = rscpu->decimalToBinary(res);
        rscpu->numToAC(arr);
        rscpu->PUTS(8, *PC);
        return;
    }

    void LOAD (int num){
        int * arr = rscpu->GETS(num);
        rscpu->numToAC(arr);
        rscpu->PUTS(1, *PC);
        rscpu->PUTS(num, *PC);
        return;
    }

    void PUTS (int num){
        rscpu->PUTS(num, *PC);
        incr;
        return;
    }

    void ORG (int num){
        rscpu->ORG(num);
        return;
    }

    void SAVE (int address){
        rscpu->SAVE(memory->AC, address);
        PUTS(2);
        PUTS(address);
    }

    void TOR (){
        rscpu->TOR();
        PUTS(5);
        return;
    }

    void TOAC(){
        rscpu->TOAC();
        return;
    }







};



#define UNTITLED7_INTERFACE_H

#endif //UNTITLED7_INTERFACE_H
