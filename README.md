# Tiny CPU Emulator

A beginner-friendly CPU emulator written in C.

This project is part of my low-level programming and computer architecture learning journey. The goal is to understand how CPUs execute instructions by building a small emulator from scratch.

**Current Version: v3**

---

## What's New in v3

### New Features

* Added 256 memory cells
* Added STORE instruction
* Added LOADM instruction
* Register-to-memory transfers
* Memory-to-register transfers
* Expanded CPU architecture with RAM support

---

## Features

### CPU Components

#### Registers

* R0
* R1
* R2
* R3

#### Control Unit

* Program Counter (PC)
* Running Flag
* Zero Flag (ZF)

#### Memory

```text
256 Memory Cells
```

Used to store data outside CPU registers.

---

## Supported Instructions

| Opcode | Instruction | Description                          |
| ------ | ----------- | ------------------------------------ |
| 0      | LOAD        | Load immediate value into register   |
| 1      | ADD         | Add values from multiple registers   |
| 2      | HALT        | Stop execution                       |
| 3      | SUB         | Subtract register values             |
| 4      | JMP         | Unconditional jump                   |
| 5      | CMP         | Compare two registers                |
| 6      | JZ          | Jump if Zero Flag is set             |
| 7      | STORE       | Store register value in memory       |
| 8      | LOADM       | Load value from memory into register |

---

## CPU Architecture

```text
                ┌─────────────┐
                │   MEMORY    │
                │ 256 CELLS   │
                └──────┬──────┘
                       │
                       ▼

┌─────────────────────────────┐
│         CPU CORE            │
├─────────────────────────────┤
│ R0 │ R1 │ R2 │ R3           │
├─────────────────────────────┤
│ PC (Program Counter)        │
│ ZF (Zero Flag)              │
│ Running Flag                │
└─────────────────────────────┘
```

---

## Instruction Set

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

### CMP

```text
5 SRC1 SRC2
```

Example:

```text
5 0 1
```

Meaning:

```text
Compare R0 and R1

If equal:
    ZF = 1
Else:
    ZF = 0
```

---

### JZ

```text
6 ADDRESS
```

Example:

```text
6 29
```

Meaning:

```text
If ZF == 1
    PC = ADDRESS
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
PC = ADDRESS
```

---

### STORE

Store a register value into memory.

Format:

```text
7 SRC MEMORY_ADDRESS
```

Example:

```text
7 1 0
```

Meaning:

```text
MEMORY[0] = R1
```

---

### LOADM

Load a value from memory into a register.

Format:

```text
8 DEST MEMORY_ADDRESS
```

Example:

```text
8 2 0
```

Meaning:

```text
R2 = MEMORY[0]
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

    5, 0, 1,
    6, 29,

    7, 1, 0,
    8, 2, 0,

    4, 12,

    2
};
```

---

## Execution Cycle

The emulator follows a classic CPU execution cycle:

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

## Sample Output

```text
CPU Created!

R0     : 5
R1     : 7
R2     : 7
R3     : 14
PC     : 12
Running: 0
```

---

## Learning Objectives

This project is being built to learn:

* Computer Architecture
* CPU Design Fundamentals
* Memory Systems
* CPU Flags
* Instruction Sets
* Conditional Branching
* Fetch-Decode-Execute Cycles
* Emulator Development
* Low-Level Programming in C

---

## Version History

### v1

* 2 Registers
* LOAD
* ADD
* JMP
* HALT

### v1.5

* 4 Registers
* SUB Instruction
* Improved Arithmetic Support

### v2

* Zero Flag
* CMP Instruction
* JZ Instruction
* Conditional Branching

### v3

* 256 Memory Cells
* STORE Instruction
* LOADM Instruction
* Register ↔ Memory Transfers
* Basic RAM Support

---

## Author

Aryan

Interested in:

* Reverse Engineering
* Systems Programming
* Compiler Design
* Computer Architecture
* Emulator Development

---

## License

MIT License
