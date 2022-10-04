#pragma once
#include "numsys.h"
#include "lib.h"
class Display {
  Memory * memory;
  NumSys * numsys;
public:

    Display (){

    }
    Display(Memory * local){
        memory = local;
        numsys = new NumSys();
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
            for (int j=0; j<8; j++){
                std::cout << *(memory->RAM+i) << " ";
            }
            std::cout << std::endl;
        }
    }

    void seeMemoryHex(){
        for (int bytes = 0; bytes < 256; bytes+=4){
            if (bytes<10){
                std::cout << "0";
            }
            if (bytes<100){
                std::cout << "0";
            }
            std::cout << bytes << "\t";
            Memory localMem;
            localMem.RAM = memory->RAM;
            int start = 0;
            int spacing = 1;
            for (int i=1; i<=8; i++){
                int arr[4] = {localMem.RAM[i+start], localMem.RAM[i+start+1], localMem.RAM[i+start+2], localMem.RAM[i+start+3]};
                char disp = numsys->toHex(arr);
                start+=4;
                std::cout << disp;
                if (spacing==2){
                    std::cout << " ";
                    spacing = 1;
                }
                else {
                    spacing++;
                }
            }
            std::cout << std::endl;
        }


    }


};


