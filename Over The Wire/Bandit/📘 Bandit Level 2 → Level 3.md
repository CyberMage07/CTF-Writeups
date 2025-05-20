
---
**Challenge URL:** [Bandit Level 2](https://overthewire.org/wargames/bandit/bandit2.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in a file called  
> `spaces in this filename`  
> located in the home directory.

---

#### 🧠 Concept:

This level introduces:

- **Filenames with spaces**, which must be handled using quotes or escape characters.
    

---

#### 🛠️ Steps to Solve:

1. **SSH into the machine:**
    
    ```bash
    ssh bandit2@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Check file listing:**
    
    ```bash
    ls -alh
    ```
    
    You’ll see:
    
    ```
    spaces in this filename
    ```
    
3. **Read the file using quotes:**
    
    ```bash
    cat 'spaces in this filename'
    ```
    
    Output:
    
    ```
    MNK8NHSJUi6o4IRUEDOFgFqtxPLSlSmx
    ```
    
4. **Logout once done:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 3:

```
MNK8NHSJUi6o4IRUEDOFgFqtxPLSlSmx
```

---
