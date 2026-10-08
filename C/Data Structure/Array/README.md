# 📦 C Arrays

An **array** is simply:

> **One variable that can store multiple values of the same type.**

Instead of making this:

```c
int number1 = 10;
int number2 = 20;
int number3 = 30;
int number4 = 40;
int number5 = 50;
```

You can make:

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

Much easier.

---

# 🧠 1. Think of an Array as a Row of Boxes

Imagine you have 5 boxes:

```text
┌────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │
└────┴────┴────┴────┴────┘
```

The computer needs a way to identify each box.

It uses an **index**.

```text
Index:    0     1     2     3     4
          ↓     ↓     ↓     ↓     ↓
        ┌────┬────┬────┬────┬────┐
Value:  │ 10 │ 20 │ 30 │ 40 │ 50 │
        └────┴────┴────┴────┴────┘
```

### ⚠️ VERY IMPORTANT

C arrays start counting at **0**, NOT 1.

So:

```text
First element  → index 0
Second element → index 1
Third element  → index 2
Fourth element → index 3
Fifth element  → index 4
```

This is one of the first things that confuses beginners.

---

# 2. Creating an Array

The basic syntax is:

```c
data_type array_name[size];
```

For example:

```c
int numbers[5];
```

This means:

> Create an array called `numbers` that can hold **5 integers**.

Think:

```text
numbers

Index
  0       1       2       3       4
  ↓       ↓       ↓       ↓       ↓
┌───────┬───────┬───────┬───────┬───────┐
│       │       │       │       │       │
└───────┴───────┴───────┴───────┴───────┘
```

---

# 3. Putting Values Inside

You can initialize it immediately:

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

Now:

```text
numbers[0] = 10
numbers[1] = 20
numbers[2] = 30
numbers[3] = 40
numbers[4] = 50
```

---

# 4. Getting a Value From an Array

Suppose:

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

If you write:

```c
printf("%d", numbers[0]);
```

Output:

```text
10
```

Because `numbers[0]` means:

> Give me the value inside box number 0.

---

### Another example

```c
printf("%d", numbers[3]);
```

Output:

```text
40
```

Because:

```text
Index:     0    1    2    3    4
           ↓    ↓    ↓    ↓    ↓
Value:    10   20   30   40   50
```

`numbers[3]` = `40`.

---

# 5. Changing an Array Value

You can change individual elements.

```c
int numbers[5] = {10, 20, 30, 40, 50};

numbers[2] = 999;
```

Now:

```text
Index:     0    1     2     3    4
           ↓    ↓     ↓     ↓    ↓
Value:    10   20    999   40   50
```

Only element `2` changed.

---

# 6. Array + Loop = 🚀

This is where arrays become REALLY useful.

Instead of:

```c
printf("%d\n", numbers[0]);
printf("%d\n", numbers[1]);
printf("%d\n", numbers[2]);
printf("%d\n", numbers[3]);
printf("%d\n", numbers[4]);
```

You can use a loop:

```c
#include <stdio.h>

int main() {

    int numbers[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
```

Output:

```text
10
20
30
40
50
```

---

# 🧠 Why does `numbers[i]` work?

Look at the loop:

```c
for (int i = 0; i < 5; i++)
```

`i` changes:

```text
First loop:
i = 0

Second:
i = 1

Third:
i = 2

Fourth:
i = 3

Fifth:
i = 4
```

Therefore:

```c
numbers[i]
```

becomes:

```text
numbers[0]
numbers[1]
numbers[2]
numbers[3]
numbers[4]
```

That's how you process the entire array.

---

# 📦 7. Array in Memory

Here's the slightly more technical part.

Suppose:

```c
int numbers[4] = {10, 20, 30, 40};
```

Conceptually:

```text
Memory

Address        Value
0x1000   →      10
0x1004   →      20
0x1008   →      30
0x100C   →      40
```

Why are the addresses separated?

Because an `int` is commonly **4 bytes**.

So:

```text
numbers[0] → 0x1000
numbers[1] → 0x1004
numbers[2] → 0x1008
numbers[3] → 0x100C
```

This is the beginning of understanding **pointers**, which you'll encounter later.

---

# ⚠️ 8. The Biggest Beginner Mistake

If you create:

```c
int numbers[5];
```

Valid indexes are:

```text
0
1
2
3
4
```

NOT:

```text
5
```

So this:

```c
numbers[5] = 100;
```

is **wrong**.

You are trying to access memory outside the array.

```text
VALID

0       1       2       3       4
↓       ↓       ↓       ↓       ↓
┌───────┬───────┬───────┬───────┬───────┐
│       │       │       │       │       │
└───────┴───────┴───────┴───────┴───────┘


INVALID

5
↓
┌───────┐
│ ???   │  ← NOT YOUR ARRAY
└───────┘
```

This is called **out-of-bounds access** and can cause bugs, crashes, or corrupted data.

---

# 9. You Don't Always Need to Specify the Size

You can do:

```c
int numbers[] = {10, 20, 30, 40, 50};
```

C automatically figures out:

```text
5 elements
```

So this:

```c
int numbers[] = {10, 20, 30, 40, 50};
```

is effectively:

```c
int numbers[5] = {10, 20, 30, 40, 50};
```

---

# 10. What Happens If You Give Fewer Values?

Example:

```c
int numbers[5] = {10, 20};
```

C creates 5 elements.

The remaining elements become zero:

```text
Index:     0    1    2    3    4
           ↓    ↓    ↓    ↓    ↓
Value:    10   20    0    0    0
```

---

# 11. Arrays Can Use Other Types

Not just `int`.

### `float`

```c
float temperatures[3] = {25.5, 28.2, 30.1};
```

### `char`

```c
char letters[4] = {'A', 'B', 'C', 'D'};
```

### `double`

```c
double prices[3] = {10.50, 20.75, 30.99};
```

The rule is:

> An array normally contains elements of **one type**.

---

# 12. Real-Life Example — Student Marks

Imagine you have 5 students:

```c
int marks[5] = {85, 72, 91, 66, 78};
```

You can calculate the total:

```c
#include <stdio.h>

int main() {

    int marks[5] = {85, 72, 91, 66, 78};
    int total = 0;

    for (int i = 0; i < 5; i++) {
        total = total + marks[i];
    }

    printf("Total = %d\n", total);

    return 0;
}
```

Output:

```text
Total = 392
```

Then you could calculate the average:

```c
float average = total / 5.0;

printf("Average = %.2f\n", average);
```

---

# 13. User Input Into an Array

This is where things get interesting.

```c
#include <stdio.h>

int main() {

    int numbers[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("\nYou entered:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
```

Example:

```text
Enter number 1: 15
Enter number 2: 25
Enter number 3: 8
Enter number 4: 100
Enter number 5: 42

You entered:
15
25
8
100
42
```

---

# 🧠 14. The `&` in `scanf`

This is important.

You write:

```c
scanf("%d", &numbers[i]);
```

Not:

```c
scanf("%d", numbers[i]);
```

Why?

Because `scanf()` needs the **memory address** where it should put the input.

The `&` means roughly:

> "Give me the address of this variable."

You'll understand this properly when we learn **pointers**.

---

# 🔥 15. Arrays Are Extremely Useful

Imagine you need to store:

### 10 numbers

```c
int numbers[10];
```

### 100 student marks

```c
int marks[100];
```

### 1,000 product prices

```c
float prices[1000];
```

### RGB color

```c
int rgb[3] = {255, 128, 0};
```

### Sensor readings

```c
float temperature[24];
```

For example:

```text
temperature[0]  → 00:00
temperature[1]  → 01:00
temperature[2]  → 02:00
...
temperature[23] → 23:00
```

---

# 🧩 16. Array vs Normal Variable

### Normal variable

```c
int age = 25;
```

One box:

```text
┌───────┐
│  25   │
└───────┘
```

### Array

```c
int ages[5] = {20, 25, 30, 35, 40};
```

Five boxes:

```text
┌────┬────┬────┬────┬────┐
│ 20 │ 25 │ 30 │ 35 │ 40 │
└────┴────┴────┴────┴────┘
  0    1    2    3    4
```

---

# 🧠 17. The Most Important Array Rules

Memorize these:

```text
ARRAY
  │
  ├── Multiple values
  │
  ├── Same data type
  │
  ├── Index starts at 0
  │
  ├── Stored next to each other in memory
  │
  └── Size is fixed after creation
```

For:

```c
int numbers[5];
```

remember:

```text
Number of elements = 5

First index = 0
Last index  = 4
```

Formula:

```text
Last index = array size - 1
```

Therefore:

```text
[5] → indexes 0–4
[10] → indexes 0–9
[100] → indexes 0–99
```

---

# 🎯 One Small Program to Practice

Try to understand this completely:

```c
#include <stdio.h>

int main() {

    int numbers[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("Index %d = %d\n", i, numbers[i]);
    }

    return 0;
}
```

Output:

```text
Index 0 = 10
Index 1 = 20
Index 2 = 30
Index 3 = 40
Index 4 = 50
```

