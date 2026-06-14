# Tiny CPU Emulator

A beginner-friendly CPU emulator written in C.

This project is part of my low-level programming and computer architecture learning journey. The goal is to understand how CPUs execute instructions by building a small emulator from scratch.

**Current Version: v1.5**

---

## What's New in v1.5

### Added Features

* Expanded register count from **2 to 4**
* Added **SUB** instruction
* Improved arithmetic instruction handling
* More complex example programs
* Better foundation for future memory and stack support

---

## Features

### CPU Components

* 4 General Purpose Registers

  * R0
  * R1
  * R2
  * R3

* Program Counter (PC)

* Running State Flag

---

## Supported Instructions

| Opcode | Instruction | Description                     |
| ------ | ----------- | ------------------------------- |
| 0      | LOAD        | Load a value into a register    |
| 1      | ADD         | Add multiple registers together |
| 2      | HALT        | Stop execution                  |
| 3      | SUB         | Subtract register values        |
| 4      | JMP         | Jump to another memory address  |

---

## CPU Architecture

```text
Registers
─────────────
R0
R1
R2
R3

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
1 DEST SRC1 SRC2 SRC3
```

Example:

```text
1 3 0 1 2
```

Meaning:

```text
R3 = R3 + R0 + R1 + R2
```

---

### SUB

```text
3 DEST SRC1 SRC2 SRC3
```

Example:

```text
3 3 0 1 2
```

Meaning:

```text
R3 = R3 - R2 - R1 - R0
```

---

### JMP

```text
4 ADDRESS
```

Example:

```text
4 12
```

Meaning:

```text
PC = 12
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
    0, 2, 9,
    0, 3, 0,

    1, 3, 0, 1, 2,
    3, 3, 0, 1, 2,

    4, 12,

    2
};
```

Program Flow:

```text
LOAD R0, 5
LOAD R1, 7
LOAD R2, 9
LOAD R3, 0

ADD R3, R0, R1, R2
SUB R3, R0, R1, R2

JMP 12

HALT
```

---

## Execution Cycle

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

Compile:

```bash
gcc tiny_cpu_emulator.c -o cpu
```

Run:

```bash
./cpu
```

---

## Learning Objectives

This project is being built to learn:

* Computer Architecture
* CPU Design Fundamentals
* Instruction Sets
* Program Counters
* Arithmetic Instructions
* Fetch-Decode-Execute Cycles
* Low-Level Programming in C
* Emulator Development

---

## Version History

### v1

* 2 Registers (R0, R1)
* LOAD Instruction
* ADD Instruction
* JMP Instruction
* HALT Instruction
* Basic Fetch-Decode-Execute Cycle

### v1.5

* 4 Registers (R0-R3)
* SUB Instruction
* Improved ADD Instruction
* Larger Example Programs
* Enhanced CPU Architecture

---

## Author

Aryan

Interested in:

* Reverse Engineering
* Systems Programming
* Compiler Design
* Computer Architecture
