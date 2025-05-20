
---
**Challenge URL:** [Bandit Level 7](https://overthewire.org/wargames/bandit/bandit7.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in the file `/etc/bandit_pass/bandit8` and can be retrieved by reading the **content of a file** that contains the **password**.

But here's the twist:

> You do **not know the file name**—you only know that it is **somewhere in the home directory** and contains the word **"millionth"**.

---

#### 🧠 Concept:

This level focuses on:

- Using `grep` to **search inside files**
    
- Recursively scanning directories
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit7:**
    
    ```bash
    ssh bandit7@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Search for the keyword "millionth" recursively:**
    
    ```bash
    grep -R "millionth" .
    ```
    
    Output:
    
    ```
    ./data.txt:23r6hFYoRa9NEC0XWnSKKb4t9UQFi7rk
    ```
    
3. **That's the password! No need to `cat` — `grep` showed the line already.**
    
4. **Exit session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 8:

```
23r6hFYoRa9NEC0XWnSKKb4t9UQFi7rk
```

---
