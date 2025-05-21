
---
**Challenge URL:** [Krypton Level 4](https://overthewire.org/wargames/krypton/krypton4.html)

---

#### 🎯 Level Goal:

> The password for `krypton5` is stored in a file named `krypton5`.  
> It was encrypted using a **Vigenère cipher** with a known key length of **6**, and you are given two reference plaintexts (`found1`, `found2`) to help derive the key.

---

#### 🧠 Concept:

This challenge focuses on:

- Understanding **polyalphabetic substitution ciphers**
    
- Cracking **Vigenère ciphers**
    
- Using **frequency analysis** on repeated intervals
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Krypton Level 4:**
    
    ```bash
    ssh krypton4@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: `BRUTE`
    
2. **Navigate to the correct directory and list files:**
    
    ```bash
    cd /krypton/krypton4/
    ls
    ```
    
    You’ll see:
    
    ```
    HINT  README  found1  found2  krypton5
    ```
    
3. **Read the encrypted file:**
    
    ```bash
    cat krypton5
    ```
    
    Output:
    
    ```
    HCIKV RJOX
    ```
    
4. **Use frequency analysis to find the key:**
    
    Since key length is 6, we split the ciphertext into 6 separate columns and analyze each as a Caesar cipher:
    
    A Python approach was used to analyze each position's frequency and match it with English frequency norms.
    
    After decoding and verifying through mapping:
    
    ✅ **Derived key:** `FREKEY`
    
5. **Decrypt the final ciphertext using the derived key** with a Vigenère decoder.
    
    Output:
    
    ```
    CLEARTEXT
    ```
    
6. **Logout after completing:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 5:

```
CLEARTEXT
```

---
