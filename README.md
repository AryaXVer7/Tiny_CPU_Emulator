# Tiny CPU Emulator

A beginner-friendly CPU emulator written in C.

This project is part of my low-level programming and computer architecture learning journey. The goal is to understand how CPUs execute instructions by building a small emulator from scratch.

Current Version: **v1**

---

## Features

### CPU Components

* 2 General Purpose Registers

  * R0
  * R1
* Program Counter (PC)
* Running State Flag

### Supported Instructions

| Opcode | Instruction | Description                    |
| ------ | ----------- | ------------------------------ |
| 0      | LOAD        | Load a value into a register   |
| 1      | ADD         | Add one register to another    |
| 2      | HALT        | Stop execution                 |
| 3      | JMP         | Jump to another memory address |

---

## CPU Architecture

```text
Registers
─────────────
R0
R1

Control Unit
─────────────
PC (Program Counter)

Execution Loop
─────────────
Fetch
Decode
Execute
```

---

## Instruction Format

### LOAD

```text
0 REG VALUE
```

Example:

```text
0 0 5
```

Meaning:

```text
R0 = 5
```

---

### ADD

```text
1 DEST SRC
```

Example:

```text
1 0 1
```

Meaning:

```text
R0 = R0 + R1
```

---

### JMP

```text
3 ADDRESS
```

Example:

```text
3 6
```

Meaning:

```text
PC = 6
```

---

### HALT

```text
2
```

Meaning:

```text
Stop CPU execution
```

---

## Example Program

```c
int program[] = {
    0, 0, 5,
    0, 1, 7,
    1, 0, 1,
    3, 6,
    2
};
```

Program Flow:

```text
LOAD R0, 5
LOAD R1, 7
ADD R0, R1
JMP 6
HALT
```

---

## Execution Cycle

The emulator follows a basic CPU execution cycle:

```text
Fetch Instruction
        │
        ▼
Decode Instruction
        │
        ▼
Execute Instruction
        │
        ▼
Update Program Counter
        │
        ▼
Repeat
```

---

## Building

Compile using GCC:

```bash
gcc tiny_cpu_emulator.c -o cpu
```

Run:

```bash
./cpu
```

---

## Sample Output

```text
CPU created!

R0     : 26
R1     : 7
PC     : 6
Running: 0
```

---

## Learning Objectives

This project is being built to learn:

* Computer Architecture
* CPU Design Fundamentals
* Instruction Sets
* Program Counters
* Fetch-Decode-Execute Cycles
* Low-Level Programming in C
* Emulator Development

---

## Author

Aryan

Interested in:

* Reverse Engineering
* Systems Programming
* Compiler Design
* Computer Architecture
