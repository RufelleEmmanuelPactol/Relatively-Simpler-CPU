
#include "terminal.h"

int main (){
    Memory * memory = new Memory();
    Cmd * terminal = new Cmd(memory);
    Rscpu * rscpu = new Rscpu(memory);
    terminal->scan();
    rscpu->seeMemoryID();


    return 0;
}
