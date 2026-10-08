# 🔤 C `char`

A `char` stores **one character**.

```c
char letter = 'A';
```

Think of it as one small box:

```text
┌───────┐
│   A   │
└───────┘
```

## 1. One Character

```c
char a = 'A';
char b = 'B';
char number = '7';
char symbol = '@';
```

Notice the **single quotes**:

```c
'A'
'B'
'7'
'@'
```

Not:

```c
"A"
```

`'A'` = character  
`"A"` = string

---

## 2. A `char` Is Actually a Number

This is the important part.

Computers store characters as numbers.

For example, in ASCII:

```text
'A' = 65
'B' = 66
'C' = 67

'a' = 97
'b' = 98
'c' = 99

'0' = 48
'1' = 49
'2' = 50
```

So:

```c
char letter = 'A';
```

is essentially storing the numeric value:

```text
65
```

You can see this:

```c
#include <stdio.h>

int main() {
    char letter = 'A';

    printf("Character: %c\n", letter);
    printf("Number:    %d\n", letter);

    return 0;
}
```

Output:

```text
Character: A
Number:    65
```

---

# 🧠 3. `%c` vs `%d`

This is a great way to understand `char`.

```c
char x = 'A';

printf("%c\n", x);
```

Output:

```text
A
```

But:

```c
printf("%d\n", x);
```

Output:

```text
65
```

Same stored value.

You're simply asking `printf` to interpret/display it differently.

```text
             char x = 'A'
                   │
                   ▼
                 65
              /       \
             /         \
          %c             %d
           │              │
           ▼              ▼
           A              65
```

---

# 🔢 4. Characters Have a Number Sequence

ASCII characters are arranged numerically.

```text
65 → A
66 → B
67 → C
68 → D
69 → E
...
90 → Z
```

And lowercase:

```text
97 → a
98 → b
99 → c
...
122 → z
```

That's why this works:

```c
char letter = 'A';

letter = letter + 1;

printf("%c", letter);
```

Output:

```text
B
```

Because:

```text
'A' = 65
65 + 1 = 66
66 = 'B'
```

---

# 📦 5. `char` Takes One Character

This:

```c
char letter = 'A';
```

is valid.

This:

```c
char letter = 'ABC';
```

is **not what you want**.

If you want multiple characters:

```c
char name[] = "SHOURAV";
```

That's a **character array**, commonly called a **string**.

```text
S H O U R A V \0
```

We'll cover strings separately.

---

# 🔤 6. Character Array

You can combine what we just learned about arrays:

```c
char letters[5] = {'A', 'B', 'C', 'D', 'E'};
```

Memory conceptually:

```text
Index:    0    1    2    3    4
          ↓    ↓    ↓    ↓    ↓

        ┌────┬────┬────┬────┬────┐
        │ A  │ B  │ C  │ D  │ E  │
        └────┴────┴────┴────┴────┘
```

Then:

```c
printf("%c", letters[2]);
```

gives:

```text
C
```

---

# 💡 Real-World Uses

`char` is useful for:

- Letters
- Symbols
- User input
- Menu choices
- Commands
- Password characters
- Text
- Strings
- File data
- ASCII data

For example:

```c
char choice;

printf("Continue? (Y/N): ");
scanf(" %c", &choice);

if (choice == 'Y') {
    printf("Continuing...");
}
```

Here `choice` contains either:

```text
'Y'
```

or:

```text
'N'
```

---

# ⚠️ One Important Thing

A `char` is an **integer type** in C.

That means you can do arithmetic:

```c
char letter = 'A';

printf("%d\n", letter + 1);
```

Output:

```text
66
```

And:

```c
printf("%c\n", letter + 1);
```

Output:

```text
B
```

---

# 🧠 The Big Picture

So far you've learned:

```text
C DATA TYPES
│
├── Integer
│   ├── signed int
│   ├── unsigned int
│   ├── long
│   └── long long
│
└── Character
    └── char
         │
         ├── 'A'
         ├── 'B'
         ├── '7'
         └── '@'
```

And the really important connection is:

```text
' A '
 │
 ▼
ASCII value
 │
 ▼
65
 │
 ▼
stored as a number
```

So **characters aren't magic**.

At the computer level, they're numbers that we agree to interpret as characters.
