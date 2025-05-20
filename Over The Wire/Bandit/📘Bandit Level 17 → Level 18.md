
---
### 🧩 Challenge Description

> There are two files in the home directory: `passwords.old` and `passwords.new`. The password for the next level is the only line that has been changed between the two files.

---

### 🧪 Solution Strategy

To identify the changed line between the two files, we use the `diff` command:

```bash
diff passwords.old passwords.new
```

This compares both files line by line and displays the difference.

The line with `>` indicates content from `passwords.new` that is not present in `passwords.old`, i.e., the newly changed line (the password).

---

### ✅ Commands Used

```bash
diff passwords.old passwords.new
```

---

### 🔑 Password for Bandit18

```
x2gLTTjFwMOhQ8oWNbNM362QKxfRqGLO
```

---
