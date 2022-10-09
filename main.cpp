#include "interface.h"

int main (){
    auto * interface = new Interface();
    Memory * memory = interface->getMemory();
    auto * rscpu = new Rscpu(memory);
    return 0;
}
