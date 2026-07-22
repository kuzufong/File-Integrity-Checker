# File-Integrity-Checker
A C-based file integrity verification tool using SHA-256 cryptographic hashing.

Properties of a Secure Cryptographic Hash Function: Deterministic, One-way, Collision resistance and avalanche effect.

-- 

# Features:
SHA-256 Hashing
Low Memory Footprint
Integrity Verification
Fast Execution



# Usage

Hash a single file:
```bash
make
./checker 
```

Example:
```
./checker checker.c
b339a0938d6b76d6e47c7a9d666441a24e532f068acf7a16faf500a39dda2eb1  checker.c
```