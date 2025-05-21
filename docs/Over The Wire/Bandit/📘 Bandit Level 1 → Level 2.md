
---
**Challenge URL:** [Bandit Level 1](https://overthewire.org/wargames/bandit/bandit1.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in a file called `-`. The file is located in the home directory.

---

#### 🧠 Concept:

This level teaches how to:

- Handle files with names that start with **special characters** like `-`
    
- Use escape techniques or double-dot prefixing to avoid command misinterpretation
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit Level 1:**
    
    ```bash
    ssh bandit1@bandit.labs.overthewire.org -p 2220
    ```
    
    - Use the password obtained from Level 0 (`ZzLjTmM6FvvyRnrb2rfNWOZOTa6ip5If`).
        
2. **Check the home directory contents:**
    
    ```bash
    ls -alh
    ```
    
    - You'll see a suspiciously named file: `-`
        
3. **Attempt to read the file using `cat -` (fails):**
    
    ```bash
    cat -
    ```
    
    - This treats `-` as STDIN, not a filename.
        
4. **Correct way: use relative path prefix `./` to escape the special meaning:**
    
    ```bash
    cat ./-
    ```
    
    Output:
    
    ```
    263JGPf9u6LDtvtf6vFUW1XP5yac29mFx
    ```
    
    This is the **password for Bandit Level 2**.
    
5. **Exit the SSH session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 2:

```
263JGPf9u6LDtvtf6vFUW1XP5yac29mFx
```

---
