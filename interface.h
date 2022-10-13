//
// Created by Rufelle on 09/10/2022.
//
#include "rscpu.h"


#ifndef UNTITLED7_INTERFACE_H
#define incrp (*PC)++
class Interface {
    Memory * memory;
    Rscpu * rscpu;
    int * PC;
public:

    Interface (){

    }

    Interface (Memory * memory, Rscpu * localrs) {
        rscpu = localrs;
        PC = &(memory->PC);
    }
    Interface (Memory * memory){
        PC = &(memory->PC);
    }

    Memory * getMemory (){
        return memory;
    }

    void ADD (){
        int res = rscpu->ADD(rscpu->memory->AC, rscpu->memory->R);
        int * arr = rscpu->decimalToBinary(res);
        rscpu->numToAC(arr);
        return;
    }

    void LOAD (int num){
        int * arr = rscpu->GETS(num);
        rscpu->numToAC(arr);
        return;
    }

    void PUTS (int num){
        rscpu->PUTS(num, *PC);
        incrp;
        return;
    }

    void ORG (int num){
        rscpu->ORG(num);
        return;
    }

    void SAVE (int address){
        rscpu->SAVE(rscpu->memory->AC, address);
    }

    void TOR (){
        rscpu->TOR();
        return;
    }

    void TOAC(){
        rscpu->TOAC();
        PUTS(4);
        PUTS(0);
        return;
    }

    void INCR(){
        rscpu->INCR();
    }







};



#define UNTITLED7_INTERFACE_H

#endif //UNTITLED7_INTERFACE_H
