#pragma once
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

};

