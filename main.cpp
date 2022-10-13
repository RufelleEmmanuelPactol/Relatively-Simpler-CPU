
#include "terminal.h"

int main (){
    Memory * memory = new Memory();
    Rscpu * rscpu = new Rscpu(memory);
    Cmd * terminal = new Cmd(memory);
    terminal->scan();
	getchar();

    return 0;
}
