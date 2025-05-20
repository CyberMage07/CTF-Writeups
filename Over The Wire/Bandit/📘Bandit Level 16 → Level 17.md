
---
### 🧩 Challenge Description

> The credentials for the next level are stored in a file called `bandit17_rsa` in the home directory of the current level. This file is a private SSH key, which can be used to log into `bandit17@localhost`.

---

### 🧪 Solution Strategy

1. **Check for the private key file** in the home directory:
    
    ```bash
    ls
    ```
    
2. **Set appropriate permissions** for the private key to prevent SSH warnings:
    
    ```bash
    chmod 600 bandit17_rsa
    ```
    
3. **Use the private key to log into bandit17**:
    
    ```bash
    ssh -i bandit17_rsa bandit17@localhost -p 2220
    ```
    
4. **Retrieve the password for the next level** using:
    
    ```bash
    cat /etc/bandit_pass/bandit17
    ```
    

---

### ✅ Commands Used

```bash
chmod 600 bandit17_rsa
ssh -i bandit17_rsa bandit17@localhost -p 2220
cat /etc/bandit_pass/bandit17
```

---

### 🔑 Password for Bandit17

```
x2gLTTjFwMOhQ8oWNbNM362QKxfRqGLO
```

---
