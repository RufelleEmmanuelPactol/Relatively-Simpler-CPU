//
// Created by Rufelle on 09/10/2022.
//
#include <ctime>
#include "macro.h"
#include "lib.h"
#include "interface.h"
#include <cstring>
#include "help.h"
#ifndef UNTITLED7_TERMINAL_H
#define UNTITLED7_TERMINAL_H
#define so sizeof(string)
#define line local->line
 class Cmd {
    int * rmv;
    time_t tmd;
    Debug * debug;

public:
    NumSys * numsys;
    Interface * interface;
    Rscpu * rscpu;
    Memory * local;
    char * timedeets;
    Cmd (){
    }
    Cmd (Memory * memory){
        local = memory;
        tmd = time(0);
        numsys = new NumSys(memory);
        rscpu = new Rscpu(memory);
        interface = new Interface(memory, rscpu);
        rmv = new int;
        debug = new Debug (memory);
        timedeets = ctime(&tmd);
    }

    void scan (){
        setup();
        char command [1000];
        int temp;
        do{
            std::cout << ">>>\t";
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

            line++;
            if (local->AR>250){
                std::cout  << "failed to compile, no \"end\" command detected, AR out of bounds\n";
                return;
            }
        }
        while (strcmp(command, "--t"));
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
        if (!strcmp(command, "$vreg")){
            rscpu->viewReg();
            return;
        }
        if (!strcmp(command, "incr")){
            interface->PUTS(63);
            interface->PUTS(0);
            return;
        }
        if (!strcmp(command, "end")){
            interface->PUTS(254);
            return;
        }

        if (!strcmp(command, "$start")){
            local->AR = address;
            return;
        }
        if (!strcmp(command, "--r")){
            comp();
            return;
        }

        if (!strcmp(command, "$help")){
            help();
            return;
        }
        if (!strcmp(command, "$cmem")){
            rscpu->seeMemoryID();
            return;
        }

        if (!strcmp(command, "$vmem")){
            if (isnoop()){
                std::cout << "error, no address entered, use syntax \"vmem <int address>\"\n";
                line++;
                return;
            }
            if (address>255-10){
                std::cout << "error, address " << address << " out of bounds, max address input is 245\n";
                line++;
                return;
            }
            rscpu->vmem(address);
            return;
        }
        if (!strcmp(command, "$ver")){
            ver();
            return;
        }

        if (!strcmp(command, "org")){
            interface->ORG(address);
            return;
        }

        if (!strcmp(command, "$clr")){
            local->clearMemoryAll();
            return;
        }

        if (!strcmp(command, "save")){
            if (isnoop()){
                interface->PUTS(2);
                interface->PUTS(255);
                return;
            }
            interface->PUTS(2);
            interface->PUTS(address);
            return;
        }
        if (!strcmp(command, "tor")){
            interface->PUTS(5);
            interface->PUTS(0);
            return;
        }
        if (!strcmp(command, "toac")){
            interface->PUTS(4);
            interface->PUTS(0);
            return;
        }
        if (!strcmp(command, "add")){
            interface->PUTS(8);
            interface->PUTS(0);
            return;
        }
        if (!strcmp(command, "--t")){
            return;
        }

        std::cout << "in line "<< line << " command  \"" << command  << "\" is not defined" << std::endl;

    }


    bool isnoop (){
        int num =  *rmv;
        if (num==noop){
            return true;
        }
        return false;
    }

    void help(){
    	std::cout << std::endl << "(c) 2022, Great Taste Black";
        std::cout << std:: endl << "Select Help Menu: \n";
        std::cout << "1: About Relatively Simpler CPU\n";
        std::cout << "2: Terminal Commands\n";
        std::cout << "3: Directives\n";
        std::cout << "4: RSimplerCPU Commands\n";
        std::cout << "5: Exit help menu\n";
        int ans;
        std::cout << "Enter command: ";
        std::cin >> ans;
        if (ans==5){
            return;
        }
        if (ans==1){
            aboutrscpu();
            help();
        }
        if (ans==2){
            terminalcommands();
            help();
        }
        if (ans==3){
            directives();
            help();
        }
        if (ans==4){
            commands();
            help();
        }
    }
    void comp (){
        int currnum = 0;
        int address = 0;
        int * temp = new int[8];
        while (currnum!=254){
            int cadd = local->AR;
            temp = rscpu->GETS(cadd);
            currnum = rscpu->binaryToDecimal(temp);
            if (isoneop(currnum)){
                int * tem = rscpu->GETS(local->AR+1);
                address = rscpu->binaryToDecimal(tem);
            }

            if (currnum==1){
                if (address==255){
                    std::cout << "error compiling on LOAD, no operand specified.\n";
                    return;
                }
                interface->LOAD(address);
            }
            if (currnum==2){
                if (address==255){
                    std::cout << "error compiling on SAVE, no operand specified.\n";
                    return;
                }
                interface->SAVE(address);
            }
            if (currnum==4){
                interface->TOAC();
            }
            if (currnum==5){
                interface->TOR();
            }
            if (currnum==8){
                interface->ADD();
            }
            if (currnum==63){
                interface->INCR();
            }

            local->AR = local->AR+2;
        }
        return;
    }

    void setup(){
        std::cout << "relatively simpler cpu prompt: sysinfo: " << timedeets <<  "enter \"$help\" for help instructions and \"$ver\" for version details\n";
    }

    void ver(){
        std::cout << "relatively simpler cpu ver 0.2.1 \n(c)great taste black, 2022\ncompiler build 0.2.1\n";
        line +=3;
    }

    bool isoneop (int com){
        if (com==1||com==2||com==32||com==33||com==34){
            return true;
        }
        return false;
    }






};





#endif //UNTITLED7_TERMINAL_H