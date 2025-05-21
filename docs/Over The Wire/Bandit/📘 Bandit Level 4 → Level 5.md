
---
**Challenge URL:** [Bandit Level 4](https://overthewire.org/wargames/bandit/bandit4.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in the only **human-readable file** in the **inhere** directory.  
> **Tip:** Many files are binary, only one contains readable ASCII text.

---

#### 🧠 Concept:

This level teaches:

- Using the `file` command to detect file types
    
- Filtering **human-readable** (ASCII) files
    
- Reading file contents via `cat`
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit4:**
    
    ```bash
    ssh bandit4@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Navigate into the `inhere` directory:**
    
    ```bash
    cd inhere
    ```
    
3. **Identify file types:**
    
    ```bash
    file ./*
    ```
    
    Output (sample):
    
    ```
    ./-file00: data  
    ./-file01: data  
    ./-file02: data  
    ...
    ./-file07: ASCII text
    ...
    ```
    
4. **Read the ASCII text file using escape prefix `./`:**
    
    ```bash
    cat ./-file07
    ```
    
    Output:
    
    ```
    tQKcUPy4xX0Eoo05PwT8W1BFj8BJxXxGUGUw
    ```
    
5. **Logout from the session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 5:

```
tQKcUPy4xX0Eoo05PwT8W1BFj8BJxXxGUGUw
```

---
