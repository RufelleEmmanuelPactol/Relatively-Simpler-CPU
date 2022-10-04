#pragma once
#include "macro.h"



class Basic{
    Memory * memory;
    Basic(){

    }
    Basic (Memory * local){
        memory = local;
    }

};