
---
**Challenge URL:** [Bandit Level 14](https://overthewire.org/wargames/bandit/bandit14.html)

---

#### 🔐 Level Goal:

> The password for the next level is **retrieved via SSH on localhost**, using a **public/private key pair**.  
> You must use the **provided private key** to authenticate to user `bandit15`.

---

#### 🧠 Concept:

This level tests:

- Using **SSH keys** to log into another user’s account on **localhost**
    
- Understanding **key-based SSH authentication**
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit14:**
    
    ```bash
    ssh bandit14@bandit.labs.overthewire.org -p 2220
    ```
    
2. **List the private key file:**
    
    ```bash
    ls
    ```
    
    You’ll see:
    
    ```
    sshkey.private
    ```
    
3. **Set the right permissions:**
    
    ```bash
    chmod 600 sshkey.private
    ```
    
4. **SSH into localhost as bandit15 using the key:**
    
    ```bash
    ssh -i sshkey.private bandit15@localhost
    ```
    
5. **Once logged in, read the password:**
    
    ```bash
    cat /etc/bandit_pass/bandit15
    ```
    
    Output:
    
    ```
    TLWrGzQlinKfCOmpt9ES9w2GcxZiYH79
    ```
    
6. **Logout from bandit15 session:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 15:

```
TLWrGzQlinKfCOmpt9ES9w2GcxZiYH79
```

---
