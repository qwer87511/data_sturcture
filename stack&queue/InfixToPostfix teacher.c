#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#define OP_NUM 15

char operators[OP_NUM] = {'#', '(', '|', '&', '!', '=', '>', '<', '+', '-', '*', '/', '%', '^', ')'};
int priority[OP_NUM] = {   0,   2,   3,   4,   5,   6,   6,   6,   7,   7,   8,   8,   8,   9,  NULL};

bool isOperator(char c)
{
    for (int i = 0; i < OP_NUM; i++)
        if (c == operators[i])
            return true;
    return false;
}

int priorityOf(char c)
{
    for (int i = 0; i < OP_NUM; i++)
        if (c == operators[i])
            return priority[i];
}

void InfixToPostfix(char input[])
{
    Node* stack;
    push(&stack, '#');

    char y;

    for (int i = 0; input[i]; i++)
    {
        char x = input[i]; // next token

        if (!isOperator(x))
        {
            printf("%c ", x);
        }
        else if (x == ')')
        {
            do
            {
                y = pop(&stack);
                if (y != '(')
                    printf("%c ", y);
            }while(y != '(');
        }
        else if (x == '(' || priorityOf(x) > priorityOf(top(stack)))
        {
            push(&stack, x);
        }
        else // if (priorityOf(x) <= priorityOf(Top(stack)))
        {
            do
            {
                y = pop(&stack);
                printf("%c ", y);
            }while(priorityOf(x) <= priorityOf(top(stack)));

            push(&stack, x); // REMEBER PUSH !
        }
    }

    while(top(stack) != '#')
        printf("%c ", pop(&stack));
}

int main() {
    char input[60];
    scanf("%s", input);
    InfixToPostfix(input);
}

