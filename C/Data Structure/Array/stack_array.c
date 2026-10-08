/*
    Stack Implementation Using Array
    ---------------------------------
    Operations:
        1. Push   - Add an element
        2. Pop    - Remove the top element
        3. Peek   - View the top element
        4. Display - Show the entire stack

    Stack follows LIFO:
    Last In, First Out
*/

#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;


/* Add an element to the top of the stack */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Stack is full.\n");
        return;
    }

    top++;
    stack[top] = value;

    printf("%d pushed into the stack.\n", value);
}


/* Remove and return the top element */
int pop(void)
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return -1;
    }

    int value = stack[top];
    top--;

    printf("%d popped from the stack.\n", value);

    return value;
}


/* Show the top element without removing it */
void peek(void)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}


/* Display the stack from top to bottom */
void display(void)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nStack (Top -> Bottom):\n");

    for (int i = top; i >= 0; i--)
    {
        printf("| %d |\n", stack[i]);
    }

    printf("-----\n");
}


int main(void)
{
    int choice;
    int value;

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("======================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
