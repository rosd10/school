.data
usage:          .string "Usage : %s LEN APPLES\n"
.bss
.text
.globl _start

_start: 
        movl %esp, %ebp
        
        # if arguments are less than 3 print usage text
        cmp $3, (%ebp) 
        je validInput
        pushl 4(%ebp)           #printf parameter 2
        pushl $usage            #printf parameter 1
        call printf             #printf("Usage: %s LEN APPLES\n", argv[0]);
        addl $8, %esp           #reset stack pointer
        jmp exitProg        #quit program
        
validInput:
        
        
        
        pushl 12(%ebp)          #num of appled
        call atoi               # atoi -> char -> int (%eax holds result)
        addl $4, %esp           #reset stack pointer
        pushl %eax              #number of apples -> stack
        
        pushl 8(%ebp)           #initial length of snake
        call atoi               #see above
        addl $4, %esp           #reset stack pointer
        pushl %eax              #push result
                       
        call start_game         #start the game, we've got apples and initial length
        addl $8, %esp           #reset stack pointer

exitProg:

        #clean up and quit
        pushl $-1
        call exit
