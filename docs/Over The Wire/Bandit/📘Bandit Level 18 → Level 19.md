
---
### 🧩 Challenge Description

> The password for the next level is in a file called `readme` located in the home directory. However, you are not logged in as bandit18 directly—any command you try to execute will be run **remotely via SSH** from `bandit18` user.

---

### 🧪 Solution Strategy

Since we are restricted to using commands remotely via SSH (without an interactive shell), we can use the SSH `-p` flag along with commands like `cat` to read the file.

1. **Try listing files remotely (just for confirmation)**:
    
    ```bash
    ssh bandit18@bandit.labs.overthewire.org -p 2220 'ls'
    ```
    
2. **Read the `readme` file remotely**:
    
    ```bash
    ssh bandit18@bandit.labs.overthewire.org -p 2220 'cat readme'
    ```
    

---

### ✅ Commands Used

```bash
ssh bandit18@bandit.labs.overthewire.org -p 2220 'cat readme'
```

---

### 🔑 Password for Bandit19

```
GWpM2hKXVmUDUNgPAVJBwYuGHYn9zL3j8
```

---
