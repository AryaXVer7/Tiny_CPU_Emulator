#include<stdio.h>

typedef struct {
    int regs[4];
    int pc;
    int running;
    int zero_flag;
} CPU;

int main(){

    CPU cpu;

    cpu.regs[0] = 0;
    cpu.regs[1] = 0;
    cpu.regs[2] = 0;
    cpu.regs[3] = 0;

    cpu.pc = 0;

    cpu.running = 1;

    cpu.zero_flag = 0;

    printf("CPU created!\n");

    int program[] = {
        0, 0, 5,
        0, 1, 7,
        0, 2, 9,
        0, 3, 0,
        1, 3, 0, 1, 2,
        3, 3, 0, 1, 2,
        5, 0, 1,
        6, 29,
        4, 12,
        2
    };

    int cycles = 0;

    while(cpu.running == 1){
         
        cycles++;
        if (cycles > 30){ //30 Instruction Cycles limit.
            printf("Cycles Limit Reached!\n");
            cpu.running = 0;
        }

        int instruction = program[cpu.pc];
        
        if (instruction == 0){
             int reg = program[cpu.pc + 1];
             int value = program[cpu.pc + 2];

             cpu.regs[reg] = value;

             cpu.pc += 3;
        }

        else if (instruction == 1){
            int dest = program[cpu.pc + 1];
            int src1 = program[cpu.pc + 2];
            int src2 = program[cpu.pc + 3];
            int src3 = program[cpu.pc + 4];

            cpu.regs[dest] += cpu.regs[src1] + cpu.regs[src2] + cpu.regs[src3];

            cpu.pc += 5;
        }

        else if (instruction == 3){
            int dest = program[cpu.pc + 1];
            int src1 = program[cpu.pc + 2];
            int src2 = program[cpu.pc + 3];
            int src3 = program[cpu.pc + 4];

            cpu.regs[dest] -= cpu.regs[src3] - cpu.regs[src2] - cpu.regs[src1];

            cpu.pc += 5;
        }

        else if (instruction == 4){
            int address = program[cpu.pc + 1];
            cpu.pc = address;
        }

        else if (instruction == 5){
            int src1 = program[cpu.pc + 1];
            int src2 = program[cpu.pc + 2];

            if (cpu.regs[src1] == cpu.regs[src2]){
                cpu.zero_flag = 1;
            }
            else{
                cpu.zero_flag = 0;
            }
        }

        else if (instruction == 6){
            int address = program[cpu.pc + 1];

            if (cpu.zero_flag == 1){
                cpu.pc = address;
            }
            else{
                cpu.pc += 2;
            }
        }

        else if (instruction == 2){
            cpu.running = 0;
        }
    
    }

	printf("R0     : %d\n", cpu.regs[0]);
	printf("R1     : %d\n", cpu.regs[1]);
	printf("R2     : %d\n", cpu.regs[2]);
	printf("R3     : %d\n", cpu.regs[3]);
	printf("PC     : %d\n", cpu.pc);
	printf("Running: %d\n", cpu.running);

    return 0;
}