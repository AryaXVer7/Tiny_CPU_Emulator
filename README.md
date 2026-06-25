# Tiny CPU Emulator

A beginner-friendly CPU emulator written in C.

This project is part of my low-level programming and computer architecture learning journey. The goal is to understand how CPUs execute instructions by building a small emulator from scratch.

**Current Version: v4**

---

# What's New in v4

## New Features

* File-based program loading
* User-entered machine code
* Instructions stored in `instructions.txt`
* Program loading from external files
* Separation between CPU and programs

---

# Features

## CPU Components

### Registers

* R0
* R1
* R2
* R3

### Flags

* Zero Flag (ZF)

### Control Unit

* Program Counter (PC)
* Running Flag

### Memory

* 256 memory cells

---

# Supported Instructions

| Opcode | Instruction | Description                    |
| ------ | ----------- | ------------------------------ |
| 0      | LOAD        | Load value into register       |
| 1      | ADD         | Add registers                  |
| 2      | HALT        | Stop execution                 |
| 3      | SUB         | Subtract registers             |
| 4      | JMP         | Unconditional jump             |
| 5      | CMP         | Compare registers              |
| 6      | JZ          | Jump if Zero Flag is set       |
| 7      | STORE       | Store register value in memory |
| 8      | LOADM       | Load value from memory         |

---

# CPU Architecture

```text
                ┌──────────────┐
                │ instructions │
                │    .txt      │
                └──────┬───────┘
                       │
                       ▼

┌─────────────────────────────┐
│         CPU CORE            │
├─────────────────────────────┤
│ R0 │ R1 │ R2 │ R3           │
├─────────────────────────────┤
│ PC                          │
│ ZF                          │
│ Running Flag                │
└─────────────────────────────┘
             │
             ▼
      256 Memory Cells
```

---

# New Concept: Program Loading

The CPU now loads programs from a file.

Example:

```text
0 0 5
0 1 7
1 3 0 1 2
2
```

This allows programs to be changed without recompiling the emulator.

---

# Execution Flow

```text
User Input
      │
      ▼
instructions.txt
      │
      ▼
Program Array
      │
      ▼
Fetch
      │
      ▼
Decode
      │
      ▼
Execute
```

---

# Example Program

```text
0 0 5
0 1 7
0 2 9
0 3 0

1 3 0 1 2

3 3 0 1 2

5 0 1

6 29

7 1 0

8 2 0

4 12

2
```

---

# Building

Compile:

```bash
gcc tiny_cpu_emulator.c -o cpu
```

Run:

```bash
./cpu
```

---

# Example Output

```text
CPU Created!

How many instructions: 32

Then, enter each instruction till < 32.

R0     : 5
R1     : 7
R2     : 7
R3     : 14
PC     : 12
Running: 0
```

---

# Learning Objectives

This project is being built to learn:

* Computer Architecture
* CPU Design
* Instruction Sets
* Memory Systems
* CPU Flags
* Conditional Branching
* Program Loading
* Emulator Development
* Low-Level Programming in C

---

# Version History

## v1

* LOAD
* ADD
* JMP
* HALT
* 2 Registers

## v1.5

* 4 Registers
* SUB instruction

## v2

* Zero Flag
* CMP
* JZ
* Conditional branching

## v3

* 256 memory cells
* STORE
* LOADM
* Memory architecture

## v4

* File-based program loading
* User-entered instructions
* instructions.txt support
* External program execution

---

# Author

Aryan

Interested in:

* Reverse Engineering
* Systems Programming
* Compiler Design
* Computer Architecture
* Emulator Development