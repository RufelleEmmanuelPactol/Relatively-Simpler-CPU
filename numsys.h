
#ifndef lib_h
#define lib_h
#include "lib.h"
#include "macro.h"

class NumSys{
    Memory * memory;
public:

    NumSys(){

    }
    NumSys (Memory * temp){
        memory = temp;
    }

    int toDecimal(int * arr, int size){
        int sum = 0;
        int ctr = 0;
        for (int i=size-1; i>=0; i--){
            if (*(arr+i)){
                sum = sum + pow(2, ctr);
            }
            ctr++;
        }
        return sum;

    }

    char toHex (int * arr){
        int returning = toDecimal(arr, 4);
        if (returning<10){
            return returning+48;
        }
        else{
            return returning+55;
        }
    }

    void decimalToBinary (int decimal, int * arr){
        if (decimal>255){
            return;
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

    void printArray (int * arr, int size){
        for (int i=0; i<size; i++){
        std::cout << arr[i];
        }
        std::cout << std::endl;
        return;
    }

    int digits (int num){
        int d = 1;
        while (num/10>0){
            num = num/10;
            d++;
        }
        return d;
    }
};

#endif