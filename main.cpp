#include "rscpu.h"


int main (){
    auto * rscpu = new Rscpu();
    rscpu->PUTS(255, 0);
    rscpu->PUTS(4, 1);
    rscpu->seeMemoryID();
    int * a = rscpu->GETS(0);
    int * b = rscpu->GETS(1);

    std::cout << rscpu->ADD(a, b) << std::endl;
    rscpu->seeZ();
    return 0;
}

/*known bugs
 * rscpu->seeMemoryHEX is buggy and in development
 *
 *
 * */