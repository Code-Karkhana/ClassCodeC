# `int`, `unsigned int`, `long int`, and `unsigned long int` in C

Many beginners get confused because two different ideas are mixed together:

## Idea 1: Can the number be negative?

```text
signed     → Negative numbers allowed
unsigned   → Negative numbers NOT allowed
```

## Idea 2: How large can the number be?

```text
int
long
long long
```

So you can combine them:

```c
int
unsigned int

long int
unsigned long int

long long int
unsigned long long int
```

Think of it like this:

```text
                 INTEGER
                     │
         ┌───────────┴───────────┐
         │                       │
      signed                 unsigned
         │                       │
         │                       │
       int                    int
       long                   long
       long long              long long
```

---

# 1. `int`

This is the most common integer type.

```c
int age = 25;
```

It can store:

```text
Negative numbers
Zero
Positive numbers
```

Typical 32-bit range:

```text
-2,147,483,648
        │
        │
        0
        │
        │
 2,147,483,647
```

Example:

```c
int temperature = -10;
int score = 95;
```

## Use cases

✅ Temperature

✅ Profit/Loss

✅ Differences

✅ Calculations that may become negative

---

# 2. `unsigned int`

This removes negative numbers.

```c
unsigned int age = 25;
```

Range (32-bit):

```text
0
│
│
│
4,294,967,295
```

Example:

```c
unsigned int people = 500;
```

Because:

```text
-500 people
```

doesn't make sense.

## Use cases

✅ Number of people

✅ Product quantity

✅ RGB color values

✅ Bit flags

✅ Binary data

---

# 3. `long int`

`long` means:

> "I may need a larger integer range."

```c
long population;
```

Important:

The size of `long` depends on the system.

### Windows (64-bit)

```text
int  = 32-bit
long = 32-bit
```

### Linux/macOS (64-bit)

```text
int  = 32-bit
long = 64-bit
```

So:

```text
long is not always 64-bit.
```

---

# 4. Why use `long`?

Suppose you have very large numbers:

```text
Country population
Large counters
Large timestamps
File sizes
Scientific calculations
```

Example:

```c
long population = 170000000;
```

Bangladesh population:

```text
170,000,000
```

This fits in `int`, but much larger values may require `long` or `long long`.

---

# 5. `unsigned long`

This combines two ideas:

```text
unsigned
+
long
```

Meaning:

```text
No negative numbers
+
Larger range
```

Example:

```c
unsigned long stars;
```

---

# 6. Visual comparison

```text
int

-2.1B -------------------- 0 -------------------- +2.1B


unsigned int

0 -------------------------------------- 4.29B


long

Larger signed range (platform dependent)


unsigned long

Larger positive range (platform dependent)
```

---

# 7. Real-world examples

## Number of students

```c
unsigned int students = 500;
```

Because:

```text
-500 students ❌
```

---

## Temperature

```c
int temperature = -10;
```

Because:

```text
-10°C ✔
```

---

## Population

```c
long population = 170000000;
```

Large numbers.

---

## File size

```c
unsigned long fileSize;
```

Because:

```text
-500 MB ❌
```

---

## Binary flags

```c
unsigned int flags;
```

Example:

```text
00000101
```

Used in:

- Operating systems
- Drivers
- Networking
- Embedded systems

---

# 8. What is `long long`?

For very large numbers:

```c
long long int bigNumber;
```

Usually:

```text
64-bit
```

Range:

```text
-9,223,372,036,854,775,808

to

9,223,372,036,854,775,807
```

Unsigned version:

```c
unsigned long long int big;
```

Range:

```text
0

to

18,446,744,073,709,551,615
```

Huge numbers.

---

# 9. Simple memory chart

```text
TYPE                    NEGATIVE?      SIZE

int                     Yes            Usually 32-bit

unsigned int            No             Usually 32-bit

long                    Yes            32 or 64-bit

unsigned long           No             32 or 64-bit

long long               Yes            Usually 64-bit

unsigned long long      No             Usually 64-bit
```

---

# 10. Which one should I use?

```text
Temperature          → int

People count         → unsigned int

Population           → long / long long

File size            → size_t

Binary flags         → unsigned int

Huge numbers         → long long

Very huge positive   → unsigned long long
```

---

# 11. Easy rule

Think of it like containers:

```text
Small Box
   int

Small Box (no negative)
   unsigned int

Big Box
   long

Big Box (no negative)
   unsigned long

Very Big Box
   long long

Very Big Box (no negative)
   unsigned long long
```

The most important thing to remember:

```text
unsigned → No negative numbers

long → Larger range

unsigned long → Larger range + No negative numbers
```

And in modern C, if you need exact sizes, use:

```c
int32_t
uint32_t
int64_t
uint64_t
```

from:

```c
#include <stdint.h>
```

because they are precise and work the same on all systems.