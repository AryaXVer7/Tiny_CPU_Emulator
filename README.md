# Tiny CPU Emulator

A beginner-friendly CPU emulator written in C.

This project is part of my low-level programming and computer architecture learning journey. The goal is to understand how CPUs execute instructions by building a small emulator from scratch.

**Current Version: v2**

---

## What's New in v2

### Added Features

* Zero Flag support
* CMP instruction
* JZ (Jump if Zero) instruction
* Conditional branching
* Cycle limit protection
* Improved CPU execution flow

---

## Features

### CPU Components

* 4 General Purpose Registers

  * R0
  * R1
  * R2
  * R3

* Program Counter (PC)

* Running Flag

* Zero Flag

---

## Supported Instructions

| Opcode | Instruction | Description                  |
| ------ | ----------- | ---------------------------- |
| 0      | LOAD        | Load a value into a register |
| 1      | ADD         | Add multiple registers       |
| 2      | HALT        | Stop execution               |
| 3      | SUB         | Subtract register values     |
| 4      | JMP         | Unconditional jump           |
| 5      | CMP         | Compare two registers        |
| 6      | JZ          | Jump if Zero Flag is set     |

---

## CPU Architecture

```text
Registers
─────────────
R0
R1
R2
R3

Flags
─────────────
ZF (Zero Flag)

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
    PC = 29
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

```text
LOAD R0, 5
LOAD R1, 7
LOAD R2, 9
LOAD R3, 0

ADD R3, R0, R1, R2
SUB R3, R0, R1, R2

CMP R0, R1
JZ 29

JMP 12

HALT
```

---

## New Concepts Introduced

### Flags

The emulator now supports CPU flags.

Currently implemented:

```text
Zero Flag (ZF)
```

Used to determine whether two values are equal after a comparison.

---

### Conditional Branching

The emulator can now change execution flow based on CPU state.

Example:

```text
CMP R0, R1
JZ target
```

This is the foundation for:

* if statements
* loops
* function calls
* real CPU control flow

---

## Learning Objectives

This project is being built to learn:

* Computer Architecture
* CPU Design Fundamentals
* Instruction Sets
* CPU Flags
* Conditional Branching
* Program Counters
* Fetch-Decode-Execute Cycles
* Low-Level Programming in C
* Emulator Development

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
* Expanded Arithmetic Support

### v2

* Zero Flag
* CMP Instruction
* JZ Instruction
* Conditional Branching
* Cycle Limit Protection

---

## Author

Aryan

Interested in:

* Reverse Engineering
* Systems Programming
* Compiler Design
* Computer Architecture
