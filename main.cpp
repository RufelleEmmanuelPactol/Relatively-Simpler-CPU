

#include "terminal.h"

int main (){
    Memory * memory = new Memory();
    Rscpu * rscpu = new Rscpu(memory);
    Cmd * terminal = new Cmd(memory);
    terminal->scan();
    std::cout << "Press enter key to quit process... ";
	getchar();
    return 0;
}
