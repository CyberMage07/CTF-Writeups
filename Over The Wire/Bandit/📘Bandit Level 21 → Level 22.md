
---
### 🧩 Challenge Description

> A **cronjob** is running every minute on the server as user `bandit22`.  
> It is **copying a password file** to a location **only readable by bandit22**.  
> Your task is to find out where it puts the file, and read it.

---

### 🧪 Solution Strategy

1. **Go to the cron directory for bandit22:**
    
    ```bash
    cd /etc/cron.d
    ```
    
2. **View the cronjob script:**
    
    ```bash
    cat cronjob_bandit22
    ```
    
    Output:
    
    ```
    * * * * * bandit22 /usr/bin/cronjob_bandit22.sh
    ```
    
3. **Inspect the cron script:**
    
    ```bash
    cat /usr/bin/cronjob_bandit22.sh
    ```
    
    Output:
    
    ```bash
    #!/bin/bash
    chmod 777 /tmp/0
    cat /etc/bandit_pass/bandit22 > /tmp/0
    ```
    
4. **Read the password from the temporary file:**
    
    ```bash
    cat /tmp/0
    ```
    

---

### ✅ Commands Used

```bash
cat /etc/cron.d/cronjob_bandit22
cat /usr/bin/cronjob_bandit22.sh
cat /tmp/0
```

---

### 🔑 Password for Bandit22

```
GbKksEFF4yrVs6il55v6gwY5aVje5f0j
```

---
