#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(Node** top, int item)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top)
{
    if (*top == NULL) return -1;

    Node* oldNode = *top;
    *top = (*top)->next;
    int item = oldNode->data;
    free(oldNode);
    return item;
}

int top(Node* top)
{
    return top->data;
}

bool isEmpty(Node* top)
{
    return !top;
}
