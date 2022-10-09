#Interfaces and hierarchy:

                        main.cpp                            - command starting point
                        terminal.h                          - reads user input
                        interface.h                         - connects registers together with commands
                        rscpu.h                             - encapsulates all primitive methods
                 basic.h       display.h                    - has RSCPU command list
            debug.h       numsys.h    memory.h              - memory handles memory storage, numsys for number manip, and debug for debugging
                  macro.h       lib.h                       - contains header files #include


# rscpu.h command return types

    display commands:
    1. seeMemoryID(); void
    2. seeMemoryHex(); void
    3. seeMemory();  void
    4. seeZ(); void

    numsys commands:
    1. toDecimal(int * arr, int size) - int
    2. toHex (int * arr) - int
    3. decimalToBinary (int n) - int ptr
    4. arrayToInt (int * arr, int size) - int
    5. digits (int num) - int (returns the size)

    debug commands:
    1. printArray(int * arr, int size) - void

    commands:
        BASIC commands:                             upon conversion to interface.h
        1. PUTS(int num, int address) - void        - no conversions needed                                         - DB
        2. GETS (int address) - int ptr             - must replace return int * ptr with AC                         - LDAC
        3. ADD (int a, int b) - int                 - set a to AC and b to R, and return set to binary to AC        - ADD
        4. SAVE (int * num, int address)            - change num to AC's address                                    - STAC
