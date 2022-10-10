#pragma once
#include "numsys.h"
#include "lib.h"
#include "debug.h"
class Display {
  Memory * memory;
  NumSys * numsys;
  Debug * debug;
public:

    Display (){

    }
    Display(Memory * local){
        memory = local;
        numsys = new NumSys();
        debug = new Debug(memory);
    }

    void seeMemoryID(){
        for (int i=0; i<256; i++){
            if (i<10){
                std::cout << "0";
            }
            if (i<100){
                std::cout << "0";
            }

            std::cout << i << "\t";
            int * target = memory->RAM;
            int factor = 8*i;
            for (int j=0; j<8; j++){
                std::cout << *(target+j+factor) << " ";
            }
            std::cout << std::endl;
        }
    }

    void seeMemoryHex(){
        for (int bytes = 0; bytes < 256; bytes+=4){
            if (bytes<10){
                //   std::cout << "0";
            }
            if (bytes<100){
               //   std::cout << "0";
            }
               // std::cout << bytes << "\t";
            int * target = memory->RAM;
            target+=bytes;
            int start = 0;
            int spacing = 1;
            for (int i=1; i<=8; i++){
                int factor = i+start;
                int * arr = new int[4];
                *(arr)= target[factor+0];
                *(arr+1) = target[factor+1];
                *(arr+2) = target[factor+2];
                *(arr+3) = target[factor+3];
                debug->printArray(arr, 4);
                std::cout <<"DONE PRINT\n";
                char disp;
                //char disp = numsys->toHex(arr);
                start+=4;
           //     std::cout << disp;
              /*  if (spacing==2){
                    std::cout << " ";
                    spacing = 1;
                }
                else {
                    spacing++;
                } */
            }
           // std::cout << std::endl;
        }


    }
    void seeZ (){
        std::cout << memory->Z;
        return;
    }

    void seeAC (){
        for (int i=0; i<8; i++){
            std::cout << *(memory->AC+i) << " ";
        }
        std::cout << std::endl;
    }

    void seeR (){
        for (int i=0; i<8; i++){
            std::cout << *(memory->R+i) << " ";
        }
        std::cout << std::endl;
    }

    void seePC (){
        int pc = memory->PC;
        int * arr = new int[8];
        numsys->decimalToBinary(pc, arr);
        debug->printArray(arr, 8);

    }

    void viewReg (){
        std::cout << "AC - ";
        for (int i=0; i<8; i++){
            std::cout << *(memory->AC+i) << " ";
        }
        std::cout << std::endl;
        std::cout << "R - ";
        for (int i=0; i<8; i++){
            std::cout << *(memory->R+i) << " ";
        }
        std::cout << std::endl;
        std::cout << "FLAG - ";
        std::cout << memory->Z;
        std::cout << std::endl;
        std::cout << "PC - ";
        int binarr[8];
        numsys->decimalToBinary(memory->PC, binarr);
        for (int i=0; i<8; i++){
            std::cout << *(binarr+i) << " ";
        }
        std::cout << std::endl;
    }

    void vmem (int num){
        int cap = 8*num;
        for (int i=0; i<20; i++){
            std::cout << num << "\t";
            for (int j=0; j<8; j++){
                std::cout << *(memory->RAM+cap) << " ";
                cap++;
            }
            num++;
            std::cout << std::endl;
        }
    }


};


