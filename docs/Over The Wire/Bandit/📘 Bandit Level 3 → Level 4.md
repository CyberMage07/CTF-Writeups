
---
**Challenge URL:** [Bandit Level 3](https://overthewire.org/wargames/bandit/bandit3.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in a **hidden file** in the **inhere** directory.

---

#### 🧠 Concept:

This level introduces:

- Navigating directories
    
- Listing **hidden files** using `ls -a`
    
- Understanding how `.` and `..` work
    
- Reading hidden files
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit3:**
    
    ```bash
    ssh bandit3@bandit.labs.overthewire.org -p 2220
    ```
    
2. **List files and go into `inhere`:**
    
    ```bash
    ls -alh
    cd inhere
    ```
    
3. **Find the hidden file:**
    
    ```bash
    ls -alh
    ```
    
    Output shows a file like:
    
    ```
    .hidden
    ```
    
4. **Display the contents of the hidden file:**
    
    ```bash
    cat .hidden
    ```
    
    Output:
    
    ```
    ZWmrDRF3JMJd3PEt1ZaaMGPhrpG0aFhF3N
    ```
    
5. **Logout after completing the level:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 4:

```
ZWmrDRF3JMJd3PEt1ZaaMGPhrpG0aFhF3N
```

---
