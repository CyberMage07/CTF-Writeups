
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> The binary decrypts a hidden section of code using XOR and executes it. Our task is to analyze the decrypted payload and supply the correct input to spawn a shell.

---

### 🧠 Concepts Covered:

- 🧩 XOR-based self-modifying code
    
- 🧠 Analyzing dynamic decryption loops
    
- 🪛 Understanding in-memory code patching
    
- 🧪 Supplying magic values to unlock hidden functionality
    

---

### 🔍 Binary Behavior Summary

From reverse engineering, the binary:

1. Loads a block of 44 bytes from section `d1` into memory
    
2. XORs each byte with the constant `0x12345678`
    
3. Executes the newly patched code
    

This is a **self-modifying program** where XOR transforms junk bytes into a valid function.

---

### 📜 Decompiled Logic (Simplified)

```c
for (int i = 0; i < 44; ++i) {
    decrypted[i] = encrypted[i] ^ 0x12345678;
}
((void (*)())decrypted)();
```

The decrypted block checks if:

```c
argv[1] == 0x1337c0de
```

If true → it executes `/bin/sh`

If false → it exits

---

### 🛠️ Exploitation

We don’t need shellcode or environment injection — just pass the correct **magic argument**.

---

### ▶️ Exploit Command

```bash
/maze/maze3 $(python3 -c 'print("\xde\xc0\x37\x13")')
```

Explanation:

- Little-endian of `0x1337c0de` = `\xde\xc0\x37\x13`
    
- The XOR-decrypted code compares this with your input
    

If correct, you instantly get a shell 🐚

---

### 🔑 Password for Maze Level 4:

```
deekaihiek
```

---
