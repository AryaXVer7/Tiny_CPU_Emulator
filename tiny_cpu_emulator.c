#include<stdio.h>

typedef struct {
    int regs[2];
    int pc;
    int running;
} CPU;

int main(){

    CPU cpu;

    cpu.regs[0] = 0;
    cpu.regs[1] = 0;

    cpu.pc = 0;

    cpu.running = 1;

    printf("CPU created!\n");

    int program[] = {
        0, 0, 5,//register 1
        0, 1, 7,//register 2
        1, 0, 1,//ADD
        3, 6,//JUMP or JMP using pc.
        2//HALT
    };

    int cycles = 0;

    while(cpu.running == 1){
        int instruction = program[cpu.pc];
        
        if (instruction == 0){
             int reg = program[cpu.pc + 1];
             int value = program[cpu.pc + 2];

             cpu.regs[reg] = value;

             cpu.pc += 3;
        }

        else if (instruction == 1){
            int dest = program[cpu.pc + 1];
            int src = program[cpu.pc + 2];

            cpu.regs[dest] = cpu.regs[dest] + cpu.regs[src];

            cpu.pc += 3;
        }

        else if (instruction == 3){

            int address = program[cpu.pc + 1];
            cpu.pc = address;
            
            cycles++;
            if (cycles > 2){
                cpu.running = 0;
            }
        }

        else if (instruction == 2){
            cpu.running = 0;
        }
    
    }

    printf("R0     : %d\n", cpu.regs[0]);
    printf("R1     : %d\n", cpu.regs[1]);
    printf("PC     : %d\n", cpu.pc);
    printf("Running: %d", cpu.running);

    printf("\n");
    return 0;
}