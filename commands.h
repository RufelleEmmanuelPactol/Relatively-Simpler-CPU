//
// Created by Rufelle on 09/10/2022.
//


#ifndef UNTITLED7_COMMANDS_H
#define UNTITLED7_COMMANDS_H
#include "memory.h"
#include "basic.h"
#include "numsys.h"


class Commands {
    Memory * memory;
    Basic * basic;
public:
    Commands (){

    }

    Commands (Memory * local){
        memory = local;
        basic = new Basic(memory);
    }

    void PUTS (int num, int address){

        basic->PUTS(num, address);
        return;
    }
};




#endif //UNTITLED7_COMMANDS_H
