
---
**Challenge URL:** [Krypton Level 3](https://overthewire.org/wargames/krypton/krypton3.html)

---

#### 🎯 Level Goal:

> The password for `krypton4` is hidden inside an encrypted file using a **monoalphabetic substitution cipher**.  
> You are also provided with **3 plaintext clue files** that were encrypted using the same cipher key.

---

#### 🧠 Concept:

In this level, you’ll work with:

- **Frequency analysis** of ciphered letters
    
- Decrypting monoalphabetic substitution ciphers
    
- Pattern recognition across multiple files
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Krypton Level 3:**
    
    ```bash
    ssh krypton3@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: `CAESARISEASY`
    
2. **Navigate to the challenge directory:**
    
    ```bash
    cd /krypton/krypton3/
    ls
    ```
    
    Files present:
    
    ```
    HINT1  HINT2  README  found1  found2  found3  krypton4
    ```
    
3. **View the encrypted password file:**
    
    ```bash
    cat krypton4
    ```
    
    Output:
    
    ```
    KSVVW BGSJD SVSIS VXBMN YQUUK BNWCU ANMJS
    ```
    
4. **Combine and analyze frequency of known ciphertext samples:**
    
    ```bash
    cat found1 found2 found3 | tr -d ' ' | fold -w1 | sort | uniq -c | sort -nr
    ```
    
    Result:
    
    ```
    (S, Q, J, U...) are most frequent letters
    ```
    
    Based on this and comparing with English letter frequency (`ETAOIN...`), we can start mapping likely substitutions.
    
5. **Use a Python script to apply the frequency-based mapping:**
    
    ```python
    cipher = "KSVVWBGSJDSVSISVXBMNYQUUKBNWCUANMJS"
    mapping_from = "SQJUBNCGDZVWMYTXKELAFIOHRP"
    mapping_to   = "EQTSORINHCLDUPMFWGYBKVXQJZ"
    
    cleartext = ""
    for c in cipher:
        if c in mapping_from:
            i = mapping_from.index(c)
            cleartext += mapping_to[i]
        else:
            cleartext += c
    
    print(cleartext)
    ```
    
    Output:
    
    ```
    WELLDONETHELEVELFOURPASSWORDISBRUTE
    ```
    
6. **Logout once complete:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 4:

```
BRUTE
```

---
