
---
**Challenge URL:** [Bandit Level 5](https://overthewire.org/wargames/bandit/bandit5.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in a **file somewhere under the `inhere` directory** and has the following properties:
> 
> - It is **human-readable**
>     
> - It is **1033 bytes in size**
>     
> - It is **not executable**
>     

---

#### 🧠 Concept:

This level tests:

- Using `find` with multiple conditions (`-type`, `-size`, `-executable`)
    
- Filtering by file size
    
- Displaying specific file content
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit5:**
    
    ```bash
    ssh bandit5@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Search using `find`:**
    
    ```bash
    find inhere -type f -size 1033c ! -executable
    ```
    
    Output:
    
    ```
    inhere/maybehere07/.file2
    ```
    
3. **Read the file content:**
    
    ```bash
    cat inhere/maybehere07/.file2
    ```
    
    Output:
    
    ```
    Z7WtoNQUuWYvwM2RqxqHkUDvZwS2ONQYEw
    ```
    
4. **Logout from session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 6:

```
Z7WtoNQUuWYvwM2RqxqHkUDvZwS2ONQYEw
```

---
