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

  /*  void seeMemoryID(){
        for (int i=0; i<256; i++){
            if (i<10){
                std::cout << "0";
            }
            if (i<100){
                std::cout << "0";
            }

            std::cout << i <<    " ";
            int * target = memory->RAM;
            int factor = 8*i;
            for (int j=0; j<8; j++){
                std::cout << *(target+j+factor) << " ";
            }
            std::cout << std::endl;
        }
    }*/
    
    void seeMemoryID(){
    	int a = 0, b = 32, c = 64, h = 96, d = 128, e = 160, f = 192, g = 224;
    	for (int i=0; i<32; i++){
    	//	std::cout << "NOW AT I: "<< i <<    " ";
//    		std::cout << "a: ";
    		if (a+i<10){
    			std::cout << "0";
			}
			if (a+i<100){
				std::cout << "0";
			}
    		std::cout << a+i <<    " ";
    		for (int j=1; j<=8; j++){
    			int target = ((a+i)*8);
    			std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
			}
//			std::cout << "b: ";
			std::cout <<    " ";
			if (b+i<100){
				std::cout << "0";
			}
    		std::cout << b+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((b+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
            }
//			std::cout << "c: ";
			std::cout <<    " ";
			
			if (c+i<100){
				std::cout << "0";
			}
    		std::cout << c+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((c+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
            }
            std::cout <<    " ";
            if (h+i<100){
                std::cout << "0";
            }
            std::cout << h+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((h+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
            }
//			std::cout << "d: ";
			std::cout <<    " ";
			
			if (d+i<100){
				std::cout << "0";
			}
    		std::cout << d+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((d+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
            }
//			std::cout << "e: ";
			std::cout <<    " ";
			
			if (e+i<100){
				std::cout << "0";
			}
    		std::cout << e+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((e+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
            }
//			std::cout << "f: ";
			std::cout <<    " ";
			
			if (f+i<100){
				std::cout << "0";
			}
    		std::cout << f+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((f+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
            }
//			std::cout << "g: ";
			std::cout <<    " ";
			
			if (g+i<100){
				std::cout << "0";
			}
    		std::cout << g+i <<    " ";
            for (int j=1; j<=8; j++){
                int target = ((g+i)*8);
                std::cout << *(memory->RAM+target+j-1);
                if (j%4==0){
                    std::cout << " ";
                }
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
               // std::cout << bytes <<    " ";
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
        std::cout << "AR - ";
        numsys->decimalToBinary(memory->PC, binarr);
        for (int i=0; i<8; i++){
            std::cout << *(binarr+i) << " ";
        }
        std::cout << std::endl;
    }

    void vmem (int num){
        int cap = 8*num;
        for (int i=0; i<10; i++){
            if (num>10){
                std::cout << "0";
            }
            if (num<100){
                std::cout << "0";
            }
            std::cout << num <<    " ";
            for (int j=0; j<8; j++){
                std::cout << *(memory->RAM+cap) << " ";
                cap++;
            }
            num++;
            std::cout << std::endl;
        }
    }


};


