
---
**Challenge URL:** [Bandit Level 13](https://overthewire.org/wargames/bandit/bandit13.html)

---

#### 🔐 Level Goal:

> The password for the next level is **stored in `etc/bandit_pass/bandit14`**, but you **do not have permission** to read it directly.  
> However, there is a **setuid binary called `./sshkey.private`** that will help you log in as **bandit14** using SSH.

---

#### 🧠 Concept:

This level introduces:

- **SSH key-based login**
    
- Understanding and using **private SSH keys**
    
- Running a **setuid binary** to escalate privileges securely
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit13:**
    
    ```bash
    ssh bandit13@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Check for the SSH private key:**
    
    ```bash
    ls
    ```
    
    Output:
    
    ```
    sshkey.private
    ```
    
3. **Set correct permissions:**
    
    ```bash
    chmod 600 sshkey.private
    ```
    
4. **Use the key to login as bandit14:**
    
    ```bash
    ssh -i sshkey.private bandit14@bandit.labs.overthewire.org -p 2220
    ```
    
5. **You’ll be logged in directly as bandit14. Now retrieve the password:**
    
    ```bash
    cat /etc/bandit_pass/bandit14
    ```
    
    Output:
    
    ```
    8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL
    ```
    
6. **Logout from bandit14:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 14:

```
8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL
```

---
