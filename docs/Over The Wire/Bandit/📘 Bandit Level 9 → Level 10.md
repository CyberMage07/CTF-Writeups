
---
**Challenge URL:** [Bandit Level 9](https://overthewire.org/wargames/bandit/bandit9.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in the file `data.txt` in the home directory.  
> The **password is preceded by several `=` characters**.

---

#### 🧠 Concept:

This level introduces:

- Handling **binary files**
    
- Using `strings` to extract printable text
    
- Searching for specific patterns using `grep`
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit9:**
    
    ```bash
    ssh bandit9@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Try to `cat` the file (not helpful due to binary content):**
    
    ```bash
    cat data.txt | grep "="
    ```
    
    You'll likely see a warning like:
    
    ```
    grep: binary file matches
    ```
    
3. **Use `strings` to extract human-readable content:**
    
    ```bash
    strings data.txt | grep "="
    ```
    
    Output:
    
    ```
    ===================
    the password is
    FGWmSllgJCBzE3zDE5FYh6t86EZxv3bW
    ===================
    ```
    
4. **Logout from session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 10:

```
FGWmSllgJCBzE3zDE5FYh6t86EZxv3bW
```

---
