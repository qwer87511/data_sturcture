#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int data_t;

typedef struct _stack {
    data_t data;
    struct _stack* next;
} Stack;

void push(Stack** stack, data_t item)
{
    Stack* newNode = malloc(sizeof(Stack));
    newNode->data = item;
    newNode->next = *stack;
    *stack = newNode;
}

data_t pop(Stack** stack)
{
    if (*stack == NULL)
        return -1; // STACK_UNDERFLOW

    Stack* oldNode = *stack;
    data_t item = oldNode->data;
    *stack = oldNode->next;
    free(oldNode);
    return item;
}

data_t top(Stack* stack)
{
    if (stack == NULL)
        return -1;

    return stack->data;
}

bool isEmpty(Stack* stack)
{
    return !stack;
}

void print(Stack* stack)
{
    while(stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

int main() {
    Stack* stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    pop(&stack);
    push(&stack, 4);
    push(&stack, 5);
    pop(&stack);
    print(stack);
}
