
---
 **Challenge URL:** [Bandit Level 6](https://overthewire.org/wargames/bandit/bandit6.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored somewhere on the server and has **user bandit7** and **group bandit6**, and is **33 bytes in size**.

---

#### 🧠 Concept:

This level teaches:

- Deep search using `find` across entire filesystem
    
- Filtering by **user**, **group**, and **exact file size**
    
- Using `2>/dev/null` to silence permission errors
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit6:**
    
    ```bash
    ssh bandit6@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Run `find` with all required filters:**
    
    ```bash
    find / -type f -user bandit7 -group bandit6 -size 33c 2>/dev/null
    ```
    
    Output:
    
    ```
    /var/lib/dpkg/info/bandit7.password
    ```
    
3. **Read the password from the file:**
    
    ```bash
    cat /var/lib/dpkg/info/bandit7.password
    ```
    
    Output:
    
    ```
    HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs
    ```
    
4. **Exit the session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 7:

```
HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs
```

---
