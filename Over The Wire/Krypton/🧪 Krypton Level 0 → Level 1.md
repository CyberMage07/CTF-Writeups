
---
**Challenge URL:** [Krypton Level 0](https://overthewire.org/wargames/krypton/krypton0.html)

---

#### 🎯 Level Goal:

> Log into `krypton1` using SSH. The password is stored in a file called `level0`, which is **base64 encoded**.

---

#### 📘 Concept:

In this level, you'll get hands-on with:

- Basic SSH authentication
    
- Reading file contents with `cat`
    
- Decoding base64-encoded strings using CLI tools
    

---

#### 🔧 Steps to Solve:

1. **SSH into Krypton Level 1:**
    
    ```bash
    ssh krypton1@krypton.labs.overthewire.org -p 2222
    ```
    
    Password: _Provided externally or captured from earlier_
    
2. **View the base64 encoded file:**
    
    ```bash
    cat level0
    ```
    
    Output:
    
    ```
    S1JZUFRPTklTR1JFQVQ=
    ```
    
3. **Decode using base64:**
    
    ```bash
    echo "S1JZUFRPTklTR1JFQVQ=" | base64 -d
    ```
    
    Output:
    
    ```
    KRYPTONISGREAT
    ```
    
4. **Logout:**
    
    ```bash
    exit
    ```
    

---

#### 🗝️ Password for Krypton Level 1:

```
KRYPTONISGREAT
```

---
