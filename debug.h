//
// Created by Rufelle on 04/10/2022.
//
#include <iostream>
#include "memory.h"
#ifndef UNTITLED7_DEBUG_H
#define UNTITLED7_DEBUG_H

class Debug {

public:
    Debug (){

    }
    Debug (Memory * memory){

    }
    void printArray (int * arr, int size){
        for (int i=0; i<size; i++){
            std::cout << arr[i];
        }
        std::cout << std::endl;
        return;
    }
};

#endif //UNTITLED7_DEBUG_H
