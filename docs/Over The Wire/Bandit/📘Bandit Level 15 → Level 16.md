
---
### 🧩 Challenge Description

> The password for the next level can be retrieved by submitting the password of the current level to a port on `localhost` in the range `30000 to 31000`. You will need to figure out which of these ports contains a server that will give you the next password. The programs **`openssl`** and **`nmap`** might be helpful here.

---

### 🧪 Solution Strategy

1. **Read current level's password** from the password file:
    
    ```bash
    cat /etc/bandit_pass/bandit15
    ```
    
2. **Scan open ports from 30000 to 31000** on localhost:
    
    ```bash
    nmap -p 30000-31000 localhost
    ```
    
3. **Use OpenSSL client** to connect to identified SSL-enabled port and send the password:
    
    ```bash
    PASSWORD=$(cat /etc/bandit_pass/bandit15)
    echo -e "$PASSWORD\n" | openssl s_client -connect localhost:30001 -quiet
    ```
    
4. **Retrieve the password** from the server response.
    

---

### ✅ Commands Used

```bash
cat /etc/bandit_pass/bandit15
PASSWORD=$(cat /etc/bandit_pass/bandit15)
echo -e "$PASSWORD\n" | openssl s_client -connect localhost:30001 -quiet
```

---

### 🔑 Password for Bandit16

```
kSkVbMQ7lBYyCM4GBPvCvT1BfWRy0Dx
```

---
