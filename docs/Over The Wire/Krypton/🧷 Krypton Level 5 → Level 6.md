
---
**Challenge URL:** [Krypton Level 5](https://overthewire.org/wargames/krypton/krypton5.html)

---

#### 🎯 Level Goal:

> The password for `krypton6` is encrypted with a **Vigenère cipher**, just like the previous level.  
> This time, however, the **key length is unknown**, and your job is to deduce it before decrypting the message.

---

#### 🧠 Concept:

This level introduces:

- **Key-length detection** in Vigenère ciphers
    
- Trial-and-error for Caesar shift alignment
    
- Leveraging intuition and repetition to validate plaintext
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Krypton Level 5:**
    
    ```bash
    ssh krypton5@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: `CLEARTEXT`
    
2. **Navigate to the challenge directory:**
    
    ```bash
    cd /krypton/krypton5/
    ls
    ```
    
    Files available:
    
    ```
    README  found1  found2  found3  krypton6
    ```
    
3. **Read the encrypted password file:**
    
    ```bash
    cat krypton6
    ```
    
    Output:
    
    ```
    BELOS Z
    ```
    
4. **Try different key lengths and analyze shifts:**
    
    Reuse the script from Level 4 and adjust the key length until a readable plaintext appears.
    
    Eventually, the output:
    
    ```
    RANDOM
    ```
    
    was found when the guessed key was:
    
    ```
    KEYLENGTH
    ```
    
    (A clever pun by the challenge author 👀)
    
5. **Logout:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 6:

```
RANDOM
```

---
