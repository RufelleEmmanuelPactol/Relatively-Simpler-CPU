
#ifndef lib_h
#define lib_h
#include "lib.h"
#include "debug.h"
#include <ctype.h>

class NumSys{
    Memory * memory;
    Debug * debug;
public:

    NumSys(){

    }
    NumSys (Memory * temp){
        memory = temp;
        debug = new Debug (memory);
    }

    int binaryToDecimal (int * arr){
        int sum = 0;
        int ctr = 7;
        for (int i=0; i<8; i++){
            int factor = pow(2, ctr);
            ctr--;
            sum = factor*arr[i] + sum;
        }
        return sum;
    }

    /*int toDecimal(int * arr, int size){   -> legacy method, needs to be changed
        int sum = 0;
        int ctr = 0;
        for (int i=size-1; i>=0; i--){
            if (*(arr+i)){
                sum = sum + pow(2, ctr);
            }
            ctr++;
        }
        return sum;

    } */



    char toHex (int * arr){
        debug->printArray(arr, 4);
        return 'c';
       // int returning = toDecimal(arr, 4); -> must change
       int returning = 100;
        if (returning<10){
            char r = (char)returning+48;
            return r;
        }
        else{
            char r = char(returning+55);
            return r;
        }
    }

    void decimalToBinary (int decimal, int * arr){
        if (decimal>255){
            std::cout << "error assembling, selected data " << decimal <<" beyond bounds.";
            exit(42);
        }
        for (int i=0; i<8; i++){
            arr[i] = 0;
        }
        int i = decimal;
        if (i>128){
            arr[0] = 1;
            i -= 128;
        }
        if (i>=64){
            arr[1] = 1;
            i-=64;
        }
        if (i>=32){
            arr[2] = 1;
            i-=32;
        }
        if (i>=16){
            arr[3] = 1;
            i-=16;
        }
        if (i>=8){
            arr[4] = 1;
            i-=8;
        }
        if (i>=4){
            arr[5] = 1;
            i-=4;
        }
        if (i>=2){
            arr[6] = 1;
            i-=2;
        }
        if (i==1){
            arr[7] = 1;
            i-=1;
        }
        return;


    }
    int arrayToInt (int * arr, int size){
        int sum = 0;
        int index = 0;
        for (int i=size-1; i>=0; i--){
            int factor = pow(10, i);
            sum = (arr[index]*factor) + sum;
            index++;
        }

        return sum;
    }



    int digits (int num){
        int d = 1;
        while (num/10>0){
            num = num/10;
            d++;
        }
        return d;
    }

    void strtolower(char * str){
        int i=0;
        while (str[i]){
            str[i] = tolower(str[i]);
            i++;
        }
        return;
    }

};

#endif