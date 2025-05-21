
---
**Challenge URL:** [Krypton Level 6](https://overthewire.org/wargames/krypton/krypton6.html)

---

#### 🎯 Level Goal:

> The password for `krypton7` is encrypted using a **stream cipher**.  
> You’re provided a compiled binary (`encrypt6`) that encrypts input using a **repeating key + random seed**, and the original ciphertext is already known.

---

#### 🧠 Concept:

This level introduces:

- The concept of **stream ciphers**
    
- Performing a **known plaintext attack**
    
- Observing **pattern repetitions** to deduce encryption weaknesses
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Krypton Level 6:**
    
    ```bash
    ssh krypton6@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: `RANDOM`
    
2. **Navigate to the directory:**
    
    ```bash
    cd /krypton/krypton6/
    ls
    ```
    
    Files available:
    
    ```
    HINT1  HINT2  README  encrypt6  keyfile.dat  krypton7  onetime
    ```
    
3. **View the encrypted password:**
    
    ```bash
    cat krypton7
    ```
    
    Output:
    
    ```
    PNUKLYLWRQKGKBE
    ```
    
4. **Generate test ciphertext with known plaintext:**
    
    Create a plaintext of repeating characters and encrypt it:
    
    ```bash
    python3 -c "print('A'*100)" > /tmp/plain.txt
    ./encrypt6 /tmp/plain.txt /tmp/cipher.txt
    cat /tmp/cipher.txt
    ```
    
    Output:
    
    ```
    EICTDGYIYZKTHNSIRFXYCPFUEOCKRN...
    ```
    
    Notice the repeated **30-character** pattern — the stream cipher’s key repeats every 30 bytes!
    
5. **Repeat with another character (e.g., `'B'`)** to verify offset change:
    
    ```bash
    python3 -c "print('B'*100)" > /tmp/plain2.txt
    ./encrypt6 /tmp/plain2.txt /tmp/cipher2.txt
    cat /tmp/cipher2.txt
    ```
    
    Compare differences to isolate the XOR pattern.
    
6. **XOR the known ciphertext with the observed keystream to recover the plaintext:**
    
    ```python
    cipher = "PNUKLYLWRQKGKBE"
    key    = "EICTDGYIYZKTHNS"  # Extracted from encrypting 'A'*30
    
    for i in range(len(cipher)):
        k = ord(cipher[i]) - ord(key[i])
        if k < 0: k += 26
        k += ord('A')
        print(chr(k), end='')
    ```
    
    Output:
    
    ```
    LFSRISNOTRANDOM
    ```
    
7. **Logout:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 7:

```
LFSRISNOTRANDOM
```

---
