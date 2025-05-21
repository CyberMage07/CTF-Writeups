
---
**Challenge URL:** [Krypton Level 2](https://overthewire.org/wargames/krypton/krypton2.html)

---

#### 🎯 Level Goal:

> The password for `krypton3` is stored in the file `/krypton/krypton2/krypton3`, encrypted using a **Caesar cipher** — a basic letter-shifting technique.

---

#### 📚 Concept:

In this level, you’ll practice:

- Decrypting a Caesar Cipher
    
- Brute-forcing 26 rotations (shifts)
    
- Recognizing meaningful output from a decoded string
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Krypton Level 2:**
    
    ```bash
    ssh krypton2@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: `ROTTEN`
    
2. **Read the encrypted file:**
    
    ```bash
    cat /krypton/krypton2/krypton3
    ```
    
    Output:
    
    ```
    OMQEMDUEQMEK
    ```
    
3. **Use Python to brute-force Caesar shift:**
    
    ```python
    import string
    
    charset = string.ascii_uppercase
    enc = "OMQEMDUEQMEK"
    
    for k in range(26):
        dec = ""
        for c in enc:
            if c in charset:
                idx = charset.find(c)
                idx = (idx + k) % 26
                dec += charset[idx]
            else:
                dec += c
        print(f"{k:02d}: {dec}")
    ```
    
    One of the outputs will be:
    
    ```
    12: CAESARISEASY
    ```
    
4. **Logout once you get the password:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 3:

```
CAESARISEASY
```

---
