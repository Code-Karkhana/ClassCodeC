# Signed Integer in C 

The easiest definition is:

> **A signed integer is a whole-number variable that can store negative numbers, zero, and positive numbers.**

For example:

```c
int number = -50;
```

Here `number` can be:

```text
-50
-10
-1
 0
 1
 10
 50
```

That's it.

But let's understand **why** and **how** it works.

---

# 1. What does "signed" mean?

Think about a number line:

```text
              ZERO
                ↓
───────┬───────┬───────┬───────┬───────
      -3      -2      -1       0       1       2       3
```

Actually, the full number line continues forever:

```text
... -5 -4 -3 -2 -1  0  1  2  3  4  5 ...
```

A **signed integer** can go on both sides of zero.

```text
        NEGATIVE        ZERO        POSITIVE
             │           │             │
             ▼           ▼             ▼
        -100 -10 -1      0       1 10 100
```

That's what **signed** means.

---

# 2. What about `unsigned`?

Remember our previous lesson:

```c
unsigned int number;
```

An unsigned integer cannot represent negative numbers.

So:

```text
SIGNED:

-5 -4 -3 -2 -1  0  1  2  3  4  5


UNSIGNED:

 0  1  2  3  4  5  6  7  8  9 ...
```

The difference is simply:

```text
signed   → negative + zero + positive

unsigned → zero + positive
```

---

# 3. So what is `int`?

Here's something important:

When you write:

```c
int number;
```

`int` is normally a **signed integer**.

So:

```c
int number = -10;
```

is perfectly valid.

You can also write:

```c
int number = 10;
```

or:

```c
int number = 0;
```

All valid.

---

# 4. Think of `int` as a box

Imagine you have a box called `number`.

```text
┌─────────────────────┐
│       number        │
│                     │
│        -50          │
└─────────────────────┘
```

You can replace what's inside:

```c
number = -50;
```

Then:

```text
┌─────────────────────┐
│       number        │
│        -50          │
└─────────────────────┘
```

Later:

```c
number = 100;
```

Now:

```text
┌─────────────────────┐
│       number        │
│        100          │
└─────────────────────┘
```

The box doesn't care whether the number is:

```text
negative
zero
positive
```

because it is a **signed integer**.

---

# 5. Why does the computer need signed integers?

Because real life has negative numbers everywhere.

### Temperature

```text
-10°C
-5°C
 0°C
+20°C
```

You need negative numbers.

So:

```c
int temperature = -10;
```

makes sense.

---

### Money

Suppose your account is overdrawn:

```text
Balance = -500
```

You need negative numbers.

```c
int balance = -500;
```

---

### Difference

Suppose:

```text
Your score = 50
Opponent = 70
```

Difference:

```text
50 - 70 = -20
```

You need a signed integer.

```c
int difference = 50 - 70;
```

Result:

```text
-20
```

---

# 6. Now the interesting part: bits

Computers don't actually store:

```text
-10
```

as the characters `-`, `1`, `0`.

They store bits:

```text
0
1
```

For example:

```text
01010101
```

So how can a computer represent:

```text
-10
```

using only:

```text
0
1
```

?

The answer is:

# Two's complement

Don't panic. 😄

The name sounds scary, but the basic idea is simple.

---

# 7. Imagine an 8-bit box

Let's use only 8 bits so we can see everything clearly.

```text
┌───┬───┬───┬───┬───┬───┬───┬───┐
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │
└───┴───┴───┴───┴───┴───┴───┴───┘
```

There are 8 switches.

Each switch is:

```text
OFF = 0
ON  = 1
```

---

# 8. Positive numbers

For positive numbers, binary works normally.

```text
Binary       Decimal

00000000        0
00000001        1
00000010        2
00000011        3
00000100        4
00000101        5
00000110        6
00000111        7
00001000        8
```

And so on.

---

# 9. What about negative numbers?

Here's the clever trick.

In a signed integer, the **leftmost bit** helps determine whether the number is negative.

For an 8-bit signed integer:

```text
0xxxxxxx
↑
positive/zero
```

and:

```text
1xxxxxxx
↑
negative
```

Very simplified way to think about it:

```text
First bit = 0 → positive

First bit = 1 → negative
```

But remember: the exact representation uses **two's complement**.

---

# 10. 8-bit signed range

An 8-bit signed integer can represent:

```text
-128 → +127
```

So:

```text
             8-bit signed

-128 ─────────── 0 ─────────── +127
```

Why not +128?

Because some of the 256 possible combinations are used for negative values.

There are:

```text
2⁸ = 256
```

possible combinations.

Those are divided into:

```text
128 negative values
128 non-negative values
```

Giving:

```text
-128 → -1
0 → 127
```

---

# 11. Compare signed and unsigned 8-bit

This is a REALLY useful chart.

### Unsigned 8-bit

```text
0 ─────────────────────────────── 255
```

### Signed 8-bit

```text
-128 ─────────────── 0 ─────────── 127
```

Same:

```text
8 bits
```

Different interpretation.

---

# 12. Why does signed get a smaller positive maximum?

Because it has to make room for negative numbers.

Imagine you have 10 seats.

### Unsigned

All 10 seats can be used for positive numbers:

```text
0 1 2 3 4 5 6 7 8 9
```

### Signed

You need some seats for negative numbers:

```text
-5 -4 -3 -2 -1 0 1 2 3 4
```

You're using some of the available combinations for negative values.

That's basically what happens.

---

# 13. What is `int` on your computer?

Your `int` is very likely 32-bit.

So the range is typically:

```text
-2,147,483,648
        ↓
       ...
        ↓
        0
        ↓
       ...
        ↓
+2,147,483,647
```

Compare:

```text
signed int:

-2.147 billion → +2.147 billion
```

versus:

```text
unsigned int:

0 → 4.294 billion
```

So:

```text
SIGNED

negative ◄──────── 0 ────────► positive


UNSIGNED

0 ───────────────────────────► positive
```

---

# 14. Why isn't signed max `2,147,483,648`?

Because there is one extra negative value.

For 32-bit signed integers:

```text
MIN = -2,147,483,648

MAX = +2,147,483,647
```

Notice:

```text
negative side = 2,147,483,648 values

positive side = 2,147,483,647 values
```

Plus zero.

This asymmetry comes from two's complement.

---

# 15. Let's see `-1`

This is one of the most important things to understand.

In an 8-bit signed integer:

```text
-1
```

is represented as:

```text
11111111
```

The same bits interpreted as unsigned are:

```text
255
```

So:

```text
┌──────────┐
│11111111  │
└──────────┘
      │
      ├──────────────┐
      ↓              ↓
   signed         unsigned
      ↓              ↓
     -1             255
```

Same bits.

Different interpretation.

---

# 16. Why does that happen?

This is where two's complement comes in.

Let's find `-1` using the traditional two's-complement process.

Start with positive 1:

```text
00000001
```

Invert every bit:

```text
11111110
```

Add 1:

```text
11111110
+       1
─────────
11111111
```

Therefore:

```text
11111111 = -1
```

for an 8-bit signed integer.

---

# 17. What about `-2`?

Start:

```text
2 = 00000010
```

Invert:

```text
11111101
```

Add 1:

```text
11111101
+       1
─────────
11111110
```

So:

```text
11111110 = -2
```

---

# 18. Negative number chart

For 8-bit signed integers:

```text
Binary       Decimal

11111111        -1
11111110        -2
11111101        -3
11111100        -4
11111011        -5
...
10000001      -127
10000000      -128
```

Then:

```text
01111111       +127
01111110       +126
01111101       +125
...
00000001         +1
00000000          0
```

---

# 19. The most important picture

Remember this:

```text
8-BIT SIGNED INTEGER

10000000 → -128
10000001 → -127
10000010 → -126
   ...
11111110 → -2
11111111 → -1

00000000 → 0
00000001 → 1
00000010 → 2
   ...
01111110 → 126
01111111 → 127
```

The first bit gives you a clue:

```text
0xxxxxxx → non-negative

1xxxxxxx → negative
```

---

# 20. What happens when you add 1?

This is another cool thing.

Start:

```text
01111111
```

That's:

```text
127
```

Add 1:

```text
01111111
+00000001
─────────
10000000
```

For a signed 8-bit integer:

```text
10000000 = -128
```

So:

```text
127 + 1 = -128
```

in an 8-bit signed representation.

### BUT IMPORTANT:

In actual C, **signed integer overflow is not defined to wrap around like unsigned arithmetic**. Signed overflow causes **undefined behavior**.

The 8-bit example is useful for understanding the bit representation, but don't write C code assuming:

```c
int x = INT_MAX;
x++;
```

will safely become `INT_MIN`.

It won't be valid C behavior.

---

# 21. Compare with unsigned

Unsigned overflow is different.

For an 8-bit unsigned integer:

```text
255 + 1 → 0
```

because unsigned arithmetic wraps modulo 256.

But signed:

```text
127 + 1
```

is **signed overflow**, which is undefined behavior in C.

This difference is VERY important.

---

# 22. When should you use signed integers?

Use a signed integer when the value can logically be negative.

### Temperature

```c
int temperature = -5;
```

### Bank balance

```c
int balance = -500;
```

### Score difference

```c
int difference = score1 - score2;
```

### Coordinates

```c
int x = -100;
int y = 50;
```

Coordinates are a great example.

A point could be:

```text
             Y
             ↑
       (-2,3)│
             │
─────────────┼─────────────→ X
             │
             │    (3,-2)
             ↓
```

You need negative numbers.

So signed integers make sense.

---

# 23. When should you NOT use unsigned?

Don't automatically think:

> "Negative numbers aren't needed, therefore unsigned is always better."

For example:

```c
int counter;
```

can sometimes be safer than:

```c
unsigned int counter;
```

because subtraction and comparisons can become surprising with unsigned values.

For beginners, signed integers are often easier to reason about.

---

# 24. A simple real-world analogy

Imagine an elevator.

It has floors:

```text
       +3
       +2
       +1
        0  ← Ground
       -1
       -2
       -3
```

A signed integer can represent:

```text
-3
-2
-1
 0
 1
 2
 3
```

An unsigned integer would only have:

```text
0
1
2
3
4
...
```

So:

```text
SIGNED
        ↑
     +3 │
     +2 │
     +1 │
      0 │
     -1 │
     -2 │
     -3 │


UNSIGNED

      0
      1
      2
      3
      4
      5
      ↓
```

---

# 25. One more important thing: `signed` can be written explicitly

These are effectively the same type:

```c
int number;
```

and:

```c
signed int number;
```

`int` is signed by default.

So:

```c
int x = -10;
```

is basically:

```c
signed int x = -10;
```

You normally just write:

```c
int
```

because it's shorter.

---

# 26. Format specifier

When printing a normal signed `int`:

```c
int number = -50;

printf("%d\n", number);
```

Use:

```text
%d
```

For unsigned:

```c
unsigned int number = 50;

printf("%u\n", number);
```

Use:

```text
%u
```

So remember:

```text
int          → %d

unsigned int → %u
```

---

# 27. Signed vs unsigned — final comparison

```text
┌──────────────────┬───────────────────────┐
│ SIGNED INTEGER   │ UNSIGNED INTEGER      │
├──────────────────┼───────────────────────┤
│ Negative ✔       │ Negative ✘            │
│ Zero ✔           │ Zero ✔                │
│ Positive ✔       │ Positive ✔            │
│ Smaller + range  │ Larger + range        │
│ %d for int       │ %u for unsigned int   │
└──────────────────┴───────────────────────┘
```

For typical 32-bit integers:

```text
SIGNED:

-2,147,483,648
        ↓
        0
        ↓
+2,147,483,647


UNSIGNED:

0
↓
4,294,967,295
```

---

# 28. The three things I want you to remember

### Rule #1

```text
signed = negative numbers are allowed
```

### Rule #2

```text
unsigned = negative numbers are not allowed
```

### Rule #3

```text
int is normally signed
```

So:

```c
int x = -100;
```

is completely normal.

And:

```c
unsigned int x = -100;
```

is **not** a way to store negative 100. The conversion produces an unsigned value according to C's unsigned conversion rules.

---

# 29. The whole thing in one picture

```text
                         INTEGER
                            │
               ┌────────────┴────────────┐
               │                         │
            SIGNED                    UNSIGNED
               │                         │
        Negative allowed           No negative
               │                         │
               ▼                         ▼

     -2,147,483,648                 0
             │                      │
             │                      │
             ▼                      ▼
             0               4,294,967,295
             │
             ▼
      2,147,483,647
```

And the simplest definition:

> **A signed integer is a whole-number type that can represent negative numbers, zero, and positive numbers.**
