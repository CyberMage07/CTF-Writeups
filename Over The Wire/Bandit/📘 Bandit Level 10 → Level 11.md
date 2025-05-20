
---
**Challenge URL:** [Bandit Level 10](https://overthewire.org/wargames/bandit/bandit10.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in the file `data.txt`, which contains **base64 encoded** text.

---

#### 🧠 Concept:

This level teaches:

- Identifying and decoding **base64-encoded** content
    
- Using the `base64` command-line tool
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit10:**
    
    ```bash
    ssh bandit10@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Check the contents of `data.txt`:**
    
    ```bash
    cat data.txt
    ```
    
    You'll see a long base64-encoded string.
    
3. **Decode it using `base64 -d`:**
    
    ```bash
    cat data.txt | base64 -d
    ```
    
    Output:
    
    ```
    The password is dt1eRM2zF7hvLHlH5KkZcwYHUo6YczR6
    ```
    
4. **Logout once done:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 11:

```
dt1eRM2zF7hvLHlH5KkZcwYHUo6YczR6
```

---
