
---
**Challenge URL:** [Krypton Level 1](https://overthewire.org/wargames/krypton/krypton1.html)

---

#### 🎯 Level Goal:

> Find the password for `krypton2`. It is located in the file `/krypton/krypton1/krypton2` and **encrypted using a rotation cipher (ROT13)**.

---

#### 🧠 Concept:

This level demonstrates:

- Reading files from another path
    
- Using **ROT13** substitution ciphers
    
- Simple character translation in shell
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Krypton Level 1:**
    
    ```bash
    ssh krypton1@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: `KRYPTONISGREAT`
    
2. **Display the encrypted file:**
    
    ```bash
    cat /krypton/krypton1/krypton2
    ```
    
    Output:
    
    ```
    YRIRY GJB CNFFJBEQ EBGGRA
    ```
    
3. **Use the `tr` command for ROT13 decryption:**
    
    ```bash
    echo "YRIRY GJB CNFFJBEQ EBGGRA" | tr 'A-Za-z' 'N-ZA-Mn-za-m'
    ```
    
    Output:
    
    ```
    LEVEL TWO PASSWORD ROTTEN
    ```
    
4. **Logout after completion:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 2:

```
ROTTEN
```

---
