
---
**Challenge URL:** [Bandit Level 11](https://overthewire.org/wargames/bandit/bandit11.html)

---

#### 🔐 Level Goal:

> The password for the next level is stored in the file `data.txt`, which contains **a hex dump of a file** that has been **compressed repeatedly**.  
> Your task is to **reverse the decompression** to retrieve the password.

---

#### 🧠 Concept:

This level introduces:

- Hex dumps (`xxd -r`)
    
- Multiple compression formats: gzip, bzip2, tar
    
- Extracting and working with files in `/tmp`
    

---

#### 🛠️ Steps to Solve:

1. **SSH into Bandit11:**
    
    ```bash
    ssh bandit11@bandit.labs.overthewire.org -p 2220
    ```
    
2. **Create and switch to a temp directory:**
    
    ```bash
    mkdir /tmp/tempf && cd /tmp/tempf
    ```
    
3. **Copy the data file:**
    
    ```bash
    cp ~/data.txt .
    ```
    
4. **Convert hex dump back to binary:**
    
    ```bash
    xxd -r data.txt binary
    ```
    
5. **Iteratively detect and decompress formats:**
    
    ```bash
    file binary
    gzip -d binary
    file binary
    bunzip2 binary
    file binary
    tar -xf binary
    ```
    
    Repeat this as shown in the screenshot until you reach the final readable file.
    
6. **Final output (from `cat` on the ASCII text file):**
    
    ```bash
    cat data8
    ```
    
    Output:
    
    ```
    The password is F05wY0XDiHoRo1ZDTXWTn9V7sT1kLmgc
    ```
    
7. **Logout:**
    
    ```bash
    exit
    ```
    

---

#### 🔑 Password for Bandit Level 12:

```
F05wY0XDiHoRo1ZDTXWTn9V7sT1kLmgc
```

---
