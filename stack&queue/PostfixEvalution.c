#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#define OP_NUM 5

char operators[OP_NUM] = {'+', '-', '*', '/', '%'};

bool isOperator(char input)
{
    for (int i = 0; i < OP_NUM; i++)
        if (input == operators[i])
            return true;
    return false;
}

int operate(char operator0, int left, int right)
{
    switch (operator0)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '%':
            return left % right;
    }
}

void PostfixEvalution(char input[])
{
    Node* stack = NULL;

    for(int i = 0; input[i]; i++)
    {
        char x = input[i]; // next token

        if (!isOperator(x)) // is operand
            push(&stack, x - '0');
        else // is operator
        {
            int right = pop(&stack);
            int left = pop(&stack);
            int result = operate(x, left, right);
            push(&stack, result);
        }
    }

    printf("%d", pop(&stack));
}

int main()
{
    char input[60] = "";
    scanf("%s", input);
    PostfixEvalution(input);
}
