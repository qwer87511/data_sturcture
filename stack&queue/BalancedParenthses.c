#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isBalancedParenthesesWithoutStack(char[]);

bool isBalancedParentheses(char input[])
{
    Node* stack = NULL;

    for (int i = 0; i < strlen(input); i++)
    {
        char x = input[i]; // next token
        if (x == '(')
            push(&stack, '(');
        else if (x == ')')
        {
            if (isEmpty(stack))
                return false;
            pop(&stack);
        }
    }

    return isEmpty(stack);
}

int main()
{
    char input[60];
    scanf("%s", input);
    if (isBalancedParentheses(input))
        printf("true");
    else
        printf("false");
}

bool isBalancedParenthesesWithoutStack(char input[])
{
    int count = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '(')
            count++;
        else if (input[i] == ')')
        {
            if (count == 0)
                return false;
            count --;
        }
    }

    return count == 0;
}
