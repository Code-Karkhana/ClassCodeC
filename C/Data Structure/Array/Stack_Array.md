# 📚 Stack Using Array

A **stack** is a data structure that follows:

> **LIFO — Last In, First Out**

Think of a stack of plates:

```text
       ┌───────┐
       │  12   │ ← TOP
       ├───────┤
       │  23   │
       ├───────┤
       │   5   │
       └───────┘
```

If you add another plate:

```text
       ┌───────┐
       │  61   │ ← TOP
       ├───────┤
       │  12   │
       ├───────┤
       │  23   │
       ├───────┤
       │   5   │
       └───────┘
```

You can only remove the **top** one.

So `61` comes out first.

---

# 🧠 The Four Operations

Your program implements four basic stack operations:

| Operation | Meaning |
|---|---|
| `push()` | Add something to the top |
| `pop()` | Remove the top item |
| `peek()` | Look at the top without removing it |
| `display()` | Print the stack |

---

# 1. The Array

Your code starts with:

```c
#define MAX 5

int mystack[MAX], top = -1;
```

This creates:

```text
MAX = 5

mystack

Index:     0     1     2     3     4
           ↓     ↓     ↓     ↓     ↓
        ┌─────┬─────┬─────┬─────┬─────┐
        │     │     │     │     │     │
        └─────┴─────┴─────┴─────┴─────┘

top = -1
```

Why `top = -1`?

Because the stack is initially empty.

```text
top = -1
     ↓
Nothing is inside the stack
```

Once we add something:

```text
top = 0
```

---

# 2. `push()`

Your function:

```c
void push(int mystack[], int val)
{
    if(top == MAX-1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        top++;
        mystack[top] = val;
    }
}
```

Its job is:

> **Put a new value on top of the stack.**

Suppose we start:

```text
top = -1
```

Then:

```c
push(mystack, 5);
```

First:

```c
top++;
```

So:

```text
top = 0
```

Then:

```c
mystack[top] = val;
```

becomes:

```c
mystack[0] = 5;
```

Now:

```text
Index:     0     1     2     3     4
           ↓
        ┌─────┬─────┬─────┬─────┬─────┐
        │  5  │     │     │     │     │
        └─────┴─────┴─────┴─────┴─────┘
          ↑
         TOP
```

---

# 3. Push Another Value

```c
push(mystack, 23);
```

`top` becomes:

```text
top = 1
```

And:

```c
mystack[1] = 23;
```

Now:

```text
Index:     0     1     2     3     4
           ↓     ↓
        ┌─────┬─────┬─────┬─────┬─────┐
        │  5  │ 23  │     │     │     │
        └─────┴─────┴─────┴─────┴─────┘
                 ↑
                TOP
```

Push `12`:

```text
Index:     0     1     2     3     4
           ↓     ↓     ↓
        ┌─────┬─────┬─────┬─────┬─────┐
        │  5  │ 23  │ 12  │     │     │
        └─────┴─────┴─────┴─────┴─────┘
                       ↑
                      TOP
```

---

# 4. Why `top == MAX - 1`?

This line:

```c
if(top == MAX-1)
```

checks whether the stack is full.

Remember:

```text
MAX = 5
```

Array indexes are:

```text
0  1  2  3  4
```

Therefore:

```text
MAX - 1
   ↓
5 - 1
   ↓
4
```

So:

```c
if(top == 4)
```

means:

> We are already at the last array position.

Trying to push another value would exceed the array.

That's called:

# 🚨 STACK OVERFLOW

---

# 5. `pop()`

Now we have:

```text
        ┌─────┐
        │ 12  │ ← TOP
        ├─────┤
        │ 23  │
        ├─────┤
        │  5  │
        └─────┘
```

Then:

```c
pop(mystack);
```

Your function does:

```c
val = mystack[top];
top--;
return val;
```

First:

```c
val = mystack[2];
```

So:

```text
val = 12
```

Then:

```c
top--;
```

So:

```text
top = 1
```

The stack is now considered:

```text
        ┌─────┐
        │ 23  │ ← TOP
        ├─────┤
        │  5  │
        └─────┘
```

Notice something important:

### The `12` isn't necessarily physically erased from memory.

We simply moved `top`.

```text
Before:

[ 5 ][ 23 ][ 12 ]
          ↑       ↑
          │       │
        valid    old data


After:

[ 5 ][ 23 ][ 12 ]
       ↑
      TOP
```

The stack considers only elements `0` through `top` to be active.

---

# 6. `peek()`

`peek()` is very simple:

```c
return mystack[top];
```

It means:

> Tell me what's on top, but don't remove it.

For example:

```text
        ┌─────┐
        │ 23  │ ← TOP
        ├─────┤
        │  5  │
        └─────┘
```

```c
peek(mystack);
```

returns:

```text
23
```

But the stack stays:

```text
        ┌─────┐
        │ 23  │ ← TOP
        ├─────┤
        │  5  │
        └─────┘
```

That's the difference:

```text
pop()
 ↓
LOOK + REMOVE

peek()
 ↓
LOOK ONLY
```

---

# 7. `display()`

Your function:

```c
for(i=top; i>=0; i--)
{
    printf("\n %d", mystack[i]);
}
```

It starts at `top` and moves backwards.

Suppose:

```text
Index:     0     1     2
           ↓     ↓     ↓
        ┌─────┬─────┬─────┐
        │  5  │ 23  │ 12  │
        └─────┴─────┴─────┘
                       ↑
                      TOP
```

The loop does:

```text
i = 2 → print 12
i = 1 → print 23
i = 0 → print 5
```

Output:

```text
12
23
5
```

This makes sense because a stack is normally viewed from the **top down**.

---

# 8. Empty Stack

Initially:

```c
top = -1;
```

Your code checks:

```c
if(top == -1)
```

That means:

> There is nothing in the stack.

So:

```text
top = -1

        ┌─────┐
        │     │
        ├─────┤
        │     │
        ├─────┤
        │     │
        └─────┘

        EMPTY
```

Trying:

```c
pop(mystack);
```

would produce:

```text
STACK IS EMPTY
```

This situation is called:

# 🚨 STACK UNDERFLOW

---

# 🔥 Your Entire Program Flow

Your `main()` does this:

```c
display(mystack);

push(mystack, 5);
push(mystack, 23);
push(mystack, 12);

display(mystack);

pop(mystack);

display(mystack);

push(mystack, 61);

display(mystack);

printf("\nCurrent stack top is %d", peek(mystack));
```

Let's visualize it.

### Step 1

```text
display()

EMPTY
```

### Step 2

```c
push(5)
```

```text
┌────┐
│ 5  │ ← TOP
└────┘
```

### Step 3

```c
push(23)
```

```text
┌────┐
│ 23 │ ← TOP
├────┤
│ 5  │
└────┘
```

### Step 4

```c
push(12)
```

```text
┌────┐
│ 12 │ ← TOP
├────┤
│ 23 │
├────┤
│ 5  │
└────┘
```

### Step 5

```c
pop()
```

`12` is removed.

```text
┌────┐
│ 23 │ ← TOP
├────┤
│ 5  │
└────┘
```

### Step 6

```c
push(61)
```

```text
┌────┐
│ 61 │ ← TOP
├────┤
│ 23 │
├────┤
│ 5  │
└────┘
```

### Step 7

```c
peek()
```

Returns:

```text
61
```

But **doesn't remove it**.

---

# 🧠 The Most Important Part

Your entire stack is basically controlled by **one variable**:

```c
int top = -1;
```

Think of `top` as a finger pointing at the current top:

```text
                  TOP
                   ↓
        ┌───────┬───────┬───────┐
        │   5   │  23   │  61   │
        └───────┴───────┴───────┘
                           ↑
                          top
```

### Push

```text
top++
```

Move the finger up.

### Pop

```text
top--
```

Move the finger down.

### Peek

```text
mystack[top]
```

Look at what's underneath the finger.

### Display

```text
for(i = top; i >= 0; i--)
```

Walk from the finger back toward the bottom.

---

# 🎯 Stack Rules to Memorize

```text
STACK
 │
 ├── LIFO
 │     └── Last In, First Out
 │
 ├── PUSH
 │     └── Add to TOP
 │
 ├── POP
 │     └── Remove from TOP
 │
 ├── PEEK
 │     └── Look at TOP
 │
 ├── OVERFLOW
 │     └── Push when FULL
 │
 └── UNDERFLOW
       └── Pop when EMPTY
```

And the key relationship:

```text
             TOP
              ↓
        ┌──────────┐
        │   61     │ ← Last In
        ├──────────┤
        │   23     │
        ├──────────┤
        │    5     │ ← First In
        └──────────┘

POP → 61
POP → 23
POP → 5
```

That's **LIFO: Last In, First Out**.
