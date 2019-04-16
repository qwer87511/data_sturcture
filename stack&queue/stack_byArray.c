#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 10

typedef int data_t;

typedef struct _stack {
    data_t data[STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, data_t item)
{
    if (stack->top == STACK_SIZE - 1)
        return; // STACK_OVERFLOW

    stack->top++;
    stack->data[stack->top] = item;
}

data_t pop(Stack* stack)
{
    if (stack->top == -1)
        return -1; // STACK_UNDERFLOW

    data_t item = stack->data[stack->top];
    stack->top--;
    return item;
}

data_t top(Stack* stack)
{
    if (stack->top == -1)
        return -1; // STACK_UNDERFLOW

    return stack->data[stack->top];
}

bool isEmpty(Stack* stack)
{
    return stack->top == -1;
}

void print(Stack* stack)
{
    for(int i = stack->top; i >= 0; i--)
        printf("%d ", stack->data[i]);
}

int main(int argc, char** argv)
{
    Stack stack;
    stack.top = -1;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    pop(&stack);
    push(&stack, 4);
    push(&stack, 5);
    pop(&stack);
    print(&stack);
}
