

#include "terminal.h"

int main (){
    Memory * memory = new Memory();
    Rscpu * rscpu = new Rscpu(memory);
    Cmd * terminal = new Cmd(memory);
    std::cout << "Now running the RSCPU interpreter...\n";
    terminal->scan();
    std::cout << "Press enter key to quit process... ";
	getchar();
    return 0;
}
