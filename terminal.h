//
// Created by Rufelle on 09/10/2022.
//
#include "macro.h"
#include "lib.h"
#include "interface.h"
#include <cstring>
#include "rscpu.h"
#ifndef UNTITLED7_TERMINAL_H
#define UNTITLED7_TERMINAL_H
#define so sizeof(string)

 class Cmd {
    int * rmv;
public:
    NumSys * numsys;
    Interface * interface;
    Rscpu * rscpu;
    Cmd (){
    }
    Cmd (Memory * memory){
         numsys = new NumSys(memory);
        interface = new Interface(memory);
        rscpu = new Rscpu(memory);
        rmv = new int;
    }

    void scan (){
        char command [10];
        int temp;
        do{
            std::cin >> command;
            char c = getchar();
            if (c=='\n'){
                temp = noop;
            }
            else{
                std::cin >>temp;
            }


            numsys->strtolower(command);
            *(rmv) = temp;
            conv(command, temp);

        }
        while (strcmp(command, "--r"));
    }

    void conv (char * command, int address){
        if (!strcmp(command, "load")){
            if (isnoop()){
                interface->PUTS(1);
                interface->PUTS(errorcode);
                return;
            }
            interface->PUTS(1);
            interface->PUTS(address);
            return;

        }
        if (!strcmp(command, "db")){
            interface->PUTS(address);
            return;
        }
        if (!strcmp(command, "vreg")){
            rscpu->viewReg();
            return;
        }
        if (!strcmp(command, "incr")){
            interface->PUTS(63);
            return;
        }
        if (!strcmp(command, "end")){
            interface->PUTS(254);
            return;
        }
        if (!strcmp(command, "--r")){
            comp();
            return;
        }

        if (!strcmp(command, "help")){
            help();
            return;
        }

        if (!strcmp(command, "vmem")){
            if (isnoop()){
                std::cout << "error, no address entered, use syntax \"vmem xxx\"\n";
                return;
            }
            if (address>255-20){
                std::cout << "error, address " << address << " out of bounds\n";
                return;
            }
            rscpu->vmem(address);
            return;
        }

        std::cout << "syntax error, unknown command " << command << std::endl;

    }


    bool isnoop (){
        int num =  *rmv;
        if (num==noop){
            return true;
        }
        return false;
    }

    void help(){
        return;
    }
    void comp (){
        return;
    }






};





#endif //UNTITLED7_TERMINAL_H
