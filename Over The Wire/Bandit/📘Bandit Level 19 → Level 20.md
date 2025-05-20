
---
### 🧩 Challenge Description

> To gain access to the next level, you must run a **setuid binary** (`bandit20-do`) that will execute your command as the `bandit20` user.

> You do **not** have direct access to the `bandit20` password file, so the binary must be used to read it.

---

### 🧪 Solution Strategy

1. **List files in the home directory** to check the special binary:
    
    ```bash
    ls -alh
    ```
    
    Output:
    
    ```
    -rwsr-x--- 1 bandit20 bandit19 ... bandit20-do
    ```
    
2. Use the **`bandit20-do`** binary to **run `cat` on the password file** for `bandit20`.
    
3. The command:
    
    ```bash
    ./bandit20-do cat /etc/bandit_pass/bandit20
    ```
    

---

### ✅ Commands Used

```bash
./bandit20-do cat /etc/bandit_pass/bandit20
```

---

### 🔑 Password for Bandit20

```
oQXahG8ZjoVMN9Ghs7iOWsCfZyXOUbYO
```

---
