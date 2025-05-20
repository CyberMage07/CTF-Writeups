
---
**Challenge URL:** [Bandit Level 12](https://overthewire.org/wargames/bandit/bandit12.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in the file `data.txt`, but it is **encrypted using OpenSSL** and the **AES-256-CBC** cipher.  
> The **decryption password is “notexplained”**.

---

#### 🧠 Concept:

This level teaches:

- **Decrypting files** encrypted with OpenSSL using `openssl enc -d`
    
- Understanding symmetric encryption with a passphrase
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit12:**
    
    ```bash
    ssh bandit12@bandit.labs.overthewire.org -p 2220
    ```
    
2. **View file type to confirm encryption:**
    
    ```bash
    file data.txt
    ```
    
    Output:
    
    ```
    data.txt: openssl enc'd data with salted password
    ```
    
3. **Decrypt using `openssl`:**
    
    ```bash
    openssl enc -d -aes-256-cbc -in data.txt -out decrypted.txt -k notexplained
    ```
    
4. **Display decrypted content:**
    
    ```bash
    cat decrypted.txt
    ```
    
    Output:
    
    ```
    55TBjpPZUUJgVP5b3BnbG6ON9uDPVzCJ
    ```
    
5. **Logout:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 13:

```
55TBjpPZUUJgVP5b3BnbG6ON9uDPVzCJ
```

---

