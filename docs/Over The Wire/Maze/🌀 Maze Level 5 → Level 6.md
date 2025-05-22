
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> The binary asks for a **username** and a **key**, and executes a hidden function only if certain transformations of these values match expected results. Your objective is to **reverse the logic inside a custom function** and input the correct pair to spawn a shell.

---

### 🧠 Concepts Covered:

- 🧵 Anti-debugging with `ptrace`
    
- 🔍 Reversing character transformations
    
- 🧠 Understanding loop-based character checks
    
- 🎯 Supplying exact values to satisfy verification logic
    

---

### 🔎 Binary Logic Summary

#### Prompt:

```
X----------------
Username:
Key:
```

#### Validation Flow:

1. Username and Key **must both be 8 characters long**
    
2. `ptrace(PTRACE_TRACEME)` is used to block debugging tools like `gdb`
    
3. If not being debugged → proceeds to the `foo()` function
    

---

### 📜 Reconstructed Logic from `foo()`

```c
char p[9] = {0x70, 0x72, 0x69, 0x6e, 0x74, 0x6c, 0x6f, 0x6c}; // = "printlol"
for (int i = 0; i < 8; ++i) {
    p[i] -= user[i] + 2 * i - 0x41;
}
while (i--) {
    if (pass[i] != p[i]) return 0;
}
return 1;
```

We must ensure:

```c
user[i] + 2*i - 0x41 == 0
⇒ user[i] = 0x41 - 2*i
```

---

### 🧪 Calculated Inputs

**Username:**

```c
user[i] = 0x41 - 2*i
```

|i|Calculation|Char|
|---|---|---|
|0|0x41 - 0|A|
|1|0x41 - 2 = 0x3F|?|
|2|0x41 - 4 = 0x3D|=|
|3|0x41 - 6 = 0x3B|;|
|4|0x41 - 8 = 0x39|9|
|5|0x41 - 10 = 0x37|7|
|6|0x41 - 12 = 0x35|5|
|7|0x41 - 14 = 0x33|3|

✅ **Username = `A?=;9753`**

**Password = `printlol`** (from hardcoded array)

---

### ▶️ Execution

Run the binary and input:

```bash
Username: A?=;9753
Key: printlol
```

You’ll receive:

```
Yeh, here's your shell
```

Shell spawns 🐚

---

### 🔑 Password for Maze Level 6:

```
epheghuoli
```

---
