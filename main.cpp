#include "rscpu.h"


int main (){
    Rscpu * rscpu = new Rscpu();
    int arr [] = {1,0,1,1, 0, 1, 1, 0};
    int num = 5;
    int * rec;
    rec = rscpu->decimalToBinary(100);
    rscpu->printArray(rec, 8);

    return 0;
}