
//
// Created by Rufelle on 13/10/2022.
//
#define spc "\n\t\t"

#ifndef UNTITLED7_HELP_H
#define UNTITLED7_HELP_H
#include <iostream>
#include <cstring>


void buffer (){
    char t[3];
    std::cout << "\nPress any key + enter to terminate this line...";
    std::cin >> t;
}

void aboutrscpu (){
	std::cout << "\t" << "Relatively Simpler CPU, otherwise known as RSimplerCPU is an ASM emulator designed for education.";
	std::cout <<"\n\tNot only is the syntax simpler to understand as it heavily borrows from modern English,\n";
	std::cout <<"\tthe RSimplerCPU also heavily abstracts instructions through no-operannd commands while giving its users \n";
	std::cout <<"\tthe feel and look of ASM.\n";
    std::cout << "\n\n" << "Registers and Memory:" << spc << "256-byte memory" << spc << "AC - Accumulator, 8 bits" << spc << "R - General Purpose Register, 8 bits" << spc << "AR - Address Register, 8 bits" << spc << "PC - Program Counter, 8 bits" << spc << "Z Flag, 1 bit\n";
	buffer();
	return;
}


void aboutterminalcommands(int n){
    if (n==1){
        std::cout << spc << "$start is a terminal command that dictates which memory address is to be the start of execution." << spc <<  "For example, if you decided to use org 10 before placing your RSimplerCPU commands," << spc << "you must $start at 10 as to not mix up your data and your instructions." << spc << "Remember, if your data has the same value with an OP Code, it will execute the command accordingly.\n";
    }
    if (n==2){
        std::cout << spc << "$clr is a terminal command that resets all the registers and the RAM.\n";
    }
    if (n==3){
        std::cout << spc << "$vmem is a one operand terminal command that takes in an integer value from 0 to 245." << spc << "It displays 10 RAM values starting from the address of the inputted integer.\n";
    }
    if (n==4){
        std::cout << spc << "$cmem is a terminal command that displays all the values inside the ram\n";
    }
    if (n==5){
        std::cout << spc << "$vreg is a terminal command that displays all the values of the registers\n";
    }
    if (n==6){
        std::cout << spc << "--r is a terminal command that compiles the code and runs it." << spc << "Make sure to put the \"end\" command in your code to not create unnecessary crashes and overlaps.\n";
    }
    if (n==7){
        std::cout << spc << "--t is a terminal command that terminates the program.\n";
    }
    buffer();
}

void terminalcommands(){
    std::cout << "\tLearn more about: "<< spc << "1. $start" << spc << "2. $clr" << spc << "3. $vmem" << spc << "4. $cmem" << spc << "5. $vreg" << spc << "6. --r" << spc "7. --t" << spc << "Enter command: ";
    int n;
    std::cin >> n;
    aboutterminalcommands(n);
	return;
}



void directives(){
    std::cout << "\tLearn more about: "<< spc << "1. org" << spc << "2. db" << spc << "Enter command: ";
    int n;
    std::cin >> n;
    if (n==1){
        std::cout << spc << "org is a directive that moves the PC's value and thus, all other directives and RSimplerCPU commands will write from thereon out.\n";
    }
    if (n==2){
        std::cout << spc << "db or define byte allows you to put base 10 integers" <<spc <<"and stores them in 8-bit binary format inside the memory." << spc << "db automatically stores the number in the position where the PC is pointing\n";
    }
    buffer();
	return;
}

void aboutcommands(int n){
    if (n==1){
        std::cout << spc << "LOAD is a one-operand command and copies the value at the memory position" << spc << "and stores it inside the AC. It takes an integer as an argument.\n";
    }
    if (n==2){
        std::cout << spc << "SAVE is a one-operand command and copies the value from the AC" << spc << "and stores it inside the specified memory location. It takes an int as an argument.\n";
    }
    if (n==3){
        std::cout << spc << "TOR copies the data from the AC to R\n";
    }
    if (n==4){
        std::cout << spc << "TOAC copiees the data from R to AC\n";
    }
    if (n==5){
        std::cout << spc << "ADD sums the values inside the AC and R. Stores the result in the AC\n";
    }
    if (n==6){
        std::cout << spc << "INCR adds one to the AC\n";
    }
    if (n==7){
        std::cout << spc << "JUMPS the PC at the specified memory location\n";
    }
    if (n==8){
        std::cout << spc << "JNEG: if the Z is 0, then jumps at the specified memory location.\n";
    }
    if (n==9){
        std::cout << spc << "JPOS: if the Z is 1, then jumps at the specified memory location.\n";
    }
    if (n==10){
        std::cout << spc << "COMP compares the AC and R. If the  R is greater than the AC, Z is 1. Else, Z is 0.\n";
    }
    if (n==11){
        std::cout << spc << "EQUA compares if AC and R is equal. If it is equal, then Z is 0. Else, Z is 1.\n";
    }
    if (n==12){
        std::cout << spc << "END terminates the program execution. It is crucial to put this at every end of your program.\n";
    }
    if (n==13){
        std::cout << spc << "SUB subtracts R from AC (AC-R), stores result at AC. If answer is negative, sets Z to 1." << spc << "Otherwise, sets it to zero. Negative numbers are represented by 2s compliment.\n";
    }
    if (n==14){
        std::cout << spc << "MULT gets the product of AC and R. Stores the result in AC. Overflows set Z to 1.\n";
    }
    if (n==15){
        std::cout << spc << "EXP raises AC to R. Stores result in AC. Overflows set Z to 1. Otherwise, sets Z to 0.\n";
    }
    if (n==16){
        std::cout << spc << "Reverses the Z Flag.\n";
    }
}

void commands (){
    std::cout << "\tLearn more about: "<< spc << "1. LOAD" << spc << "2. SAVE" << spc << "3. TOR" << spc << "4. TOAC" << spc << "5. ADD" << spc << "6. INCR" << spc << "7. JUMP" << spc << "8. JNEG" << spc << "9. JPOS" << spc << "10. COMP" << spc << "11. EQUA" << spc << "12. END" << spc << "13. SUB" << spc << "14: MULT" << spc << "15: EXP" << spc << "16. NOT" << spc << "Enter command: ";
    int n;
    std::cin >> n;
    aboutcommands(n);
    buffer();
    return;
}





#endif //UNTITLED7_HELP_H
