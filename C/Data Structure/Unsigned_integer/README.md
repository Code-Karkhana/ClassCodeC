# 1. First: What is an integer?

An **integer** is simply a whole number.

```text
... -3  -2  -1   0   1   2   3   4   5 ...
```

In C, you can create one with:

```c
int age = 25;
```

Think of:

```c
int age = 25;
```

as telling the computer:

> "Create a box called `age` and put the number 25 inside it."

```text
┌─────────────────────┐
│        age          │
│        25           │
└─────────────────────┘
```

---

# 2. What does `unsigned` mean?

The word **unsigned** basically means:

> **No negative numbers.**

Compare:

```c
int A;
unsigned int B;
```

`int` can normally contain both negative and positive numbers.

```text
          int
           │
     ┌─────┴─────┐
     ↓           ↓
 negative       positive
 -5 -4 -3 -2 -1 0 1 2 3 4 5
```

But `unsigned int` removes the negative side:

```text
      unsigned int
            │
            ↓
     0  1  2  3  4  5  6  7 ...
```

So:

```c
unsigned int age;
```

means:

> "I promise this variable will only represent zero or positive numbers."

---

# 3. Why does removing negative numbers give us more positive numbers?

This is where the computer's **bits** become important.

A computer stores numbers using **binary**.

Binary uses only:

```text
0
1
```

For example:

```text
Decimal     Binary

0           0000
1           0001
2           0010
3           0011
4           0100
5           0101
6           0110
7           0111
```

Imagine you have only **4 bits**.

Each bit can be either:

```text
0 or 1
```

So:

```text
4 bits
 ↓
┌───┬───┬───┬───┐
│ 0 │ 0 │ 0 │ 0 │
└───┴───┴───┴───┘
```

There are:

```text
2 × 2 × 2 × 2
```

possibilities.

That's:

```text
2⁴ = 16
```

possible combinations.

Therefore 4-bit **unsigned** numbers can represent:

```text
0 → 15
```

Chart:

```text
Binary     Decimal

0000          0
0001          1
0010          2
0011          3
0100          4
0101          5
0110          6
0111          7
1000          8
1001          9
1010         10
1011         11
1100         12
1101         13
1110         14
1111         15
```

There are no negative numbers.

---

# 4. What happens with a normal `int`?

A normal signed integer needs to represent negative numbers too.

For a simplified 4-bit example:

```text
        SIGNED INTEGER

       negative     positive

          ↓            ↓
     ┌─────────┬─────────────┐
     -8 -7 ... -1  0  1 ... 7
     └─────────┴─────────────┘
```

With 4-bit signed integers, using the common two's-complement representation:

```text
Binary      Decimal

1000          -8
1001          -7
1010          -6
1011          -5
1100          -4
1101          -3
1110          -2
1111          -1
0000           0
0001           1
0010           2
0011           3
0100           4
0101           5
0110           6
0111           7
```

So:

```text
unsigned 4-bit:

0 ─────────────────────────── 15


signed 4-bit:

-8 ─────────── 0 ─────────── 7
```

That's the fundamental difference.

---

# 5. Your `unsigned int` is normally 32 bits

On the system you're compiling on, `unsigned int` is 32 bits.

Think of it as a box containing:

```text
32 little switches
```

Each switch is either:

```text
OFF = 0
ON  = 1
```

So:

```text
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
│ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ 0 │ ...                         │ 0 │
└───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
                         32 bits
```

32 bits gives:

```text
2³²
```

possible combinations.

That's:

```text
4,294,967,296
```

different values.

Because `unsigned` doesn't need to represent negative numbers, those values are:

```text
0
↓
1
↓
2
↓
3
↓
...
↓
4,294,967,295
```

Therefore:

```text
unsigned int

MIN = 0
MAX = 4,294,967,295
```

---

# 6. Now your code makes sense

You wrote:

```c
unsigned int B;
```

This creates a variable called `B`.

Think:

```text
B
┌───────────────────────────────────────────┐
│           32 bits of storage              │
└───────────────────────────────────────────┘
```

And you're telling C:

> "Interpret these 32 bits as an unsigned number."

---

# 7. CASE 1 — storing zero

You have:

```c
B = 0;
```

Binary:

```text
00000000 00000000 00000000 00000000
```

Therefore:

```text
B = 0
```

And:

```c
printf("%u", B);
```

prints:

```text
0
```

Simple.

---

# 8. CASE 2 — storing `-1`

This is the interesting part.

You wrote:

```c
B = -1;
```

But `B` is unsigned.

It doesn't have a negative-number representation.

So the value wraps around.

For a 32-bit unsigned integer:

```text
0
```

goes backward:

```text
0
↓
4,294,967,295
```

Therefore:

```c
B = -1;
```

results in:

```text
B = 4,294,967,295
```

Conceptually:

```text
             UNSIGNED NUMBER LINE

4,294,967,295                         0
        │                              │
        │                              │
        └───────────────←──────────────┘
                       -1
```

It's like a clock.

Imagine a clock with only:

```text
0 1 2 3 4
```

If you're at `0` and go backward one:

```text
0
↑
4
```

You end up at 4.

Unsigned integers work similarly.

---

# 9. The binary explanation of `-1`

The maximum 32-bit unsigned number is:

```text
11111111 11111111 11111111 11111111
```

That's:

```text
4,294,967,295
```

So `-1` has the same **bit pattern** under two's complement:

```text
11111111 11111111 11111111 11111111
```

The important idea is:

> **Bits don't inherently have a meaning. The type tells the computer how to interpret them.**

Those 32 bits can be interpreted as:

```text
unsigned → 4,294,967,295
signed   → -1
```

Same bits.

Different interpretation.

---

# 10. This is VERY important

Think about this:

```text
┌────────────────────────────────────┐
│ 11111111 11111111 11111111 11111111│
└────────────────────────────────────┘
                  ↓
          How do we interpret it?
             /           \
            /             \
       unsigned          signed
           ↓                ↓
  4,294,967,295            -1
```

The bits haven't changed.

The **interpretation** changed.

This concept becomes extremely important when learning:

- C
- C++
- operating systems
- networking
- drivers
- embedded programming
- file formats
- memory
- cryptography
- binary protocols

---

# 11. CASE 3 — maximum value

Your code:

```c
B = 4294967295;
```

That's the maximum 32-bit unsigned integer.

Binary:

```text
11111111 11111111 11111111 11111111
```

So:

```c
printf("%u\n", B);
```

gives:

```text
4294967295
```

---

# 12. What happens when you add 1?

This is where the "overflow" idea becomes easy.

Start:

```text
4,294,967,295
```

Add 1:

```text
4,294,967,296
```

But that number doesn't fit.

So the counter wraps around:

```text
4,294,967,295
          +
          1
          ↓
          0
```

In binary:

```text
11111111 11111111 11111111 11111111
+
00000000 00000000 00000000 00000001
─────────────────────────────────────
00000000 00000000 00000000 00000000
```

The extra carry falls off the end.

Think of a car's odometer:

```text
999999
   +1
──────
000000
```

That's basically the idea.

---

# 13. Your compiler warning

You wrote:

```c
B = 4294967296;
```

Your compiler says:

```text
unsigned conversion from 'long long int' to 'unsigned int'
changes value from '4294967296' to '0'
```

It's warning you because:

```text
4294967296
```

doesn't fit into:

```text
unsigned int
```

The compiler sees:

```text
4294967296
        ↓
too large
        ↓
convert to unsigned int
        ↓
0
```

So the warning is actually **useful**.

It is telling you:

> "Hey! You're trying to put a number outside the container."

---

# 14. A simple container analogy

Imagine an `unsigned int` is a box that can hold numbers from:

```text
0 → 100
```

You put:

```text
50
```

inside.

No problem.

```text
┌─────────────────┐
│       50        │
└─────────────────┘
```

You put:

```text
100
```

inside.

Still fine.

```text
┌─────────────────┐
│      100        │
└─────────────────┘
```

But:

```text
101
```

doesn't fit.

With an actual fixed-width unsigned integer, instead of getting a bigger box, the value wraps according to the type's range.

---

# 15. Why would anyone WANT unsigned integers?

This is the most important practical question.

You should use `unsigned` when **negative values don't make logical sense**.

For example:

### Number of people

```c
unsigned int people;
```

Can you have:

```text
-5 people?
```

No.

So:

```c
unsigned int people = 50;
```

makes logical sense.

---

# 16. Age

You could theoretically use:

```c
unsigned int age;
```

because:

```text
-25 years old
```

doesn't make sense.

However, in modern C programming, I'd usually prefer an appropriately sized integer type or simply `int` unless the non-negative range is actually important.

---

# 17. File size

This is a much better example.

A file can't have:

```text
-500 bytes
```

So a size is naturally non-negative.

```c
unsigned long long fileSize;
```

For example:

```text
File size:
4,827,392 bytes
```

No negative value is needed.

---

# 18. Number of items

Imagine you're writing inventory software.

```c
unsigned int numberOfProducts;
```

You might have:

```text
0 products
1 product
25 products
500 products
```

But:

```text
-25 products
```

doesn't make sense.

---

# 19. Bit manipulation

This is where unsigned integers become **really important**.

Suppose you are working with:

```text
flags
permissions
hardware registers
binary data
network packets
```

You care about individual bits.

For example:

```text
00000001
```

could mean:

```text
        Bit
         ↓
00000001
       ↑
    enabled
```

Unsigned integers are extremely useful for this.

Example:

```c
unsigned int flags = 0;
```

Then:

```c
flags |= 1;
```

sets a bit.

This kind of programming appears in:

- operating systems
- drivers
- embedded systems
- networking
- hardware programming

---

# 20. RGB colors

Here's another cool example.

A color can be represented using bytes:

```text
RED   GREEN   BLUE
255    128     50
```

Each value is:

```text
0 → 255
```

Negative values make no sense.

So an unsigned 8-bit integer is perfect:

```c
unsigned char red;
unsigned char green;
unsigned char blue;
```

For example:

```text
RGB:

┌─────────┬─────────┬─────────┐
│   RED   │  GREEN  │  BLUE   │
│   255   │   128   │    50   │
└─────────┴─────────┴─────────┘
```

---

# 21. Network packets

Suppose a network protocol says:

```text
Packet length = 1500 bytes
```

It doesn't make sense for the packet length to be:

```text
-1500
```

So unsigned integer types are commonly useful for representing such raw fields.

---

# 22. Memory addresses and sizes

When dealing with memory, sizes and bit patterns are generally non-negative.

For example:

```text
Buffer size = 4096 bytes
```

You don't have:

```text
-4096 bytes
```

Unsigned types can be useful here, although C has specialized types such as `size_t` that you should learn rather than simply replacing every size with `unsigned int`.

For example:

```c
size_t file_size;
```

is generally preferable for sizes.

---

# 23. Where you SHOULD NOT blindly use unsigned

This is a common beginner mistake.

You might think:

> "Negative numbers aren't allowed, so I'll use unsigned everywhere!"

Don't.

Suppose you're calculating temperature:

```c
int temperature;
```

This makes sense:

```text
-10°C
-5°C
0°C
25°C
40°C
```

Using unsigned would be inappropriate.

---

# 24. Bank balance

Be careful here too.

You might think:

```c
unsigned int balance;
```

because money shouldn't be negative.

But a bank account **can have a negative balance**:

```text
Balance = -500
```

So signed arithmetic may be appropriate.

---

# 25. Differences

Suppose:

```c
int a = 10;
int b = 20;

int difference = a - b;
```

You get:

```text
10 - 20 = -10
```

If you unnecessarily use unsigned:

```c
unsigned int a = 10;
unsigned int b = 20;

unsigned int difference = a - b;
```

you don't get `-10`.

You get a very large unsigned value because the arithmetic wraps.

Conceptually:

```text
10 - 20
   ↓
-10
   ↓
wrap around
   ↓
4,294,967,286
```

This is one reason unsigned integers can cause **nasty bugs**.

---

# 26. The biggest beginner trap

Look at this:

```c
unsigned int a = 10;
unsigned int b = 20;

if (a - b < 0)
{
    printf("Negative!");
}
```

You might expect:

```text
10 - 20 = -10
```

so:

```text
-10 < 0
```

should be true.

But unsigned arithmetic doesn't work that way.

The result is unsigned.

So it wraps to a huge positive number.

Therefore:

```text
a - b < 0
```

is not true.

This is why you need to understand unsigned arithmetic rather than thinking of it simply as "positive int."

---

# 27. Think of `unsigned` as a circular number system

This mental model is extremely useful.

For a tiny 3-bit unsigned integer:

```text
Maximum = 7
```

The number line is actually a circle:

```text
                 0
              ↗     ↘
            7         1
            ↑         ↓
            6         2
              ↖     ↙
              5  ←  3
                 4
```

If you go forward from 7:

```text
7 + 1
 ↓
0
```

If you go backward from 0:

```text
0 - 1
 ↓
7
```

For 32 bits, the circle is enormous:

```text
0
↓
1
↓
2
↓
...
↓
4,294,967,295
↓
0
↓
1
...
```

---

# 28. Signed vs unsigned — big picture

Here's the chart I want you to remember:

```text
                 INTEGER
                    │
          ┌─────────┴─────────┐
          │                   │
       SIGNED              UNSIGNED
          │                   │
    Can be negative       No negative
          │                   │
     ┌────┴────┐             0
     │         │              │
  negative   positive         │
     │         │              │
    -5         5              5
   -10        10             10
```

For a typical 32-bit type:

```text
SIGNED INT

-2,147,483,648
        │
        │
        0
        │
        │
 2,147,483,647
```

Whereas:

```text
UNSIGNED INT

0
│
│
│
4,294,967,295
```

---

# 29. Why unsigned has a larger maximum

This is actually clever.

Suppose we have 8 bits.

There are:

```text
2⁸ = 256
```

possible combinations.

Unsigned uses all 256 for positive/non-negative numbers:

```text
0 → 255
```

Signed needs some of those combinations for negative numbers:

```text
-128 → 127
```

So:

```text
8-bit unsigned:

0 ─────────────────────────── 255


8-bit signed:

-128 ─────────── 0 ───────── 127
```

You are essentially trading **negative range for positive range**.

---

# 30. Your whole program simplified

Your original program is basically demonstrating these four situations:

```text
             unsigned int
                  │
                  ▼
       ┌──────────────────────┐
       │ 0 → 4,294,967,295   │
       └──────────────────────┘
             │       │
             │       │
             ▼       ▼
           normal   maximum
             │       │
             0       4,294,967,295
                     │
                     │ + 1
                     ▼
                     0
```

And:

```text
0 - 1
 ↓
4,294,967,295
```

So the two important operations are:

```text
MAX + 1 → 0

0 - 1 → MAX
```

---

# 31. One correction to your original comments

You wrote:

```c
// %d forces the computer to read it as a Signed
// (can be negative) number.
```

That's **not a good way to explain it**.

`%d` tells `printf` that the corresponding argument is an `int`.

It does **not** safely tell C:

> "Take this unsigned number and reinterpret it as signed."

Because the argument you passed is `unsigned int`, using `%d` for it is technically a format mismatch and can lead to undefined behavior.

For learning, keep these separate:

```c
printf("%u", unsigned_value);
```

for unsigned.

And:

```c
printf("%d", signed_value);
```

for signed.

---

# 32. Also, don't write this

```c
B = 4294967296;
```

if your goal is simply to demonstrate unsigned overflow.

Instead, write:

```c
B = 4294967295;
B = B + 1;
```

That's much better.

Why?

Because you're actually demonstrating:

```text
MAX
 ↓
MAX + 1
 ↓
0
```

instead of asking the compiler to convert an oversized constant.

A cleaner demonstration is:

```c
#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned int B;

    B = 0;
    printf("0       = %u\n", B);

    B = UINT_MAX;
    printf("MAX     = %u\n", B);

    B = B + 1;
    printf("MAX + 1 = %u\n", B);

    B = 0;
    B = B - 1;
    printf("0 - 1   = %u\n", B);

    return 0;
}
```

You'll get something like:

```text
0       = 0
MAX     = 4294967295
MAX + 1 = 0
0 - 1   = 4294967295
```

---

# 33. The one picture to remember

If you forget everything else, remember this:

```text
                 UNSIGNED INT
                     32 BITS
                       │
                       ▼

      ┌────────────────────────────────┐
      │                                │
      0                          4,294,967,295
      │                                │
      └────────────────────────────────┘
          ▲                        │
          │                        │
          │        +1              │
          └────────────────────────┘
                       │
                       ▼
                       0


And going backwards:

                       0
                       │
                       │ -1
                       ▼
                4,294,967,295
```

### In one sentence:

> **An `unsigned int` is an integer type that uses its available bits entirely for non-negative values, giving it a larger positive range but no negative range.**

And **where to use it**:

```text
GOOD                         THINK CAREFULLY
──────────────────────       ─────────────────────
Bit flags                    Temperatures
RGB/color components         Money/balances
Raw binary data              Differences
Packet fields                Values that may go negative
Non-negative counts          Loop calculations
Sizes → usually size_t
```
