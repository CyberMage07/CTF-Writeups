
---
**Challenge URL:** [Bandit Level 8](https://overthewire.org/wargames/bandit/bandit8.html)

---

#### 🔐 Level Goal:

> The password for the next level is the **only line** in the file `data.txt` that occurs **only once**.

---

#### 🧠 Concept:

This level teaches:

- Identifying **unique lines**
    
- Using Unix pipelines: `sort`, `uniq -u`
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit8:**
    
    ```bash
    ssh bandit8@bandit.labs.overthewire.org -p 2220
    ```
    
2. **List files and locate `data.txt`:**
    
    ```bash
    ls -alh
    ```
    
3. **Find the unique line:**
    
    ```bash
    cat data.txt | sort | uniq -u
    ```
    
    Output:
    
    ```
    k4CHm1TJ9iJe2PdXgGnvLAa4vxag0J0M
    ```
    
4. **Logout from the session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 9:

```
k4CHm1TJ9iJe2PdXgGnvLAa4vxag0J0M
```

---
