
---
### 🧩 Challenge Description

> A program is listening on port **XXXX** (localhost only) and will give the password for the next level if the **right password** is sent to it.

> The previous password is the input it expects.

---

### 🧪 Solution Strategy

1. First, start a **Netcat listener** to inspect how the binary behaves:
    
    ```bash
    nc -lvnp 4444
    ```
    
2. Execute the binary `suconnect` with a port number:
    
    ```bash
    ./suconnect 4444
    ```
    
    On wrong password input, it returns:
    
    ```
    ERROR: This doesn't match the current password!
    ```
    
3. Then run with the correct previous password (Bandit20 password):
    
    ```bash
    ./suconnect 4444
    ```
    
    From the `nc` terminal, input the password:
    
    ```
    oQXahG8ZjoVMN9Ghs7iOWsCfZyXOUbYO
    ```
    
4. If correct, you'll get:
    
    ```
    Password matches, sending next password
    ```
    

---

### ✅ Commands Used

```bash
nc -lvnp 4444
./suconnect 4444
# Then input: oQXahG8ZjoVMN9Ghs7iOWsCfZyXOUbYO
```

---

### 🔑 Password for Bandit21

```
EeoULMcra2q0dSKyJ56lDX7s1CpBu0Bt
```

---
