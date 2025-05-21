
---
**Challenge URL:** [Bandit Level 0](https://overthewire.org/wargames/bandit/bandit0.html)

---

#### 🔐 Level Goal:

> The goal of this level is to log into the game using SSH. The host to which you need to connect is:
> 
> ```
> ssh bandit0@bandit.labs.overthewire.org -p 2220
> ```
> 
> The password for the next level is stored in a file called `readme`, located in the home directory.

---

#### 🧠 Concept:

This challenge tests your ability to:

- Use **SSH** to log into a remote Linux machine.
    
- List files using `ls`
    
- Read file contents using `cat`
    

---

#### 🛠️ Steps to Solve:

1. **SSH into the target machine using the given credentials:**
    
    ```bash
    ssh bandit0@bandit.labs.overthewire.org -p 2220
    ```
    
    - You’ll get a prompt to accept the server fingerprint.
        
    - Then, you'll be prompted for the password for user `bandit0`.
        
2. **Once logged in, list files in the current directory:**
    
    ```bash
    ls
    ```
    
    - You’ll see a file named `readme`.
        
3. **Read the contents of `readme` using `cat`:**
    
    ```bash
    cat readme
    ```
    
    Output:
    
    ```
    ZzLjTmM6FvvyRnrb2rfNWOZOTa6ip5If
    ```
    
    This is the **password for Bandit Level 1**.
    
4. **Logout from the session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 1:

```
ZzLjTmM6FvvyRnrb2rfNWOZOTa6ip5If
```

---
