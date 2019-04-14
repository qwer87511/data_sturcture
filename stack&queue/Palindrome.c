#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindromeWithoutStack(char[]);

bool isPalindrome(char input[])
{
    int len = strlen(input);
    int i = 0;
    Node* stack = NULL;

    for (i = 0; i < len / 2; i++)
    {
        char x = input[i]; // next token
        push(&stack, x);
    }

    if (len % 2) i++; // skip a char

    for (; i < len; i++)
    {
        char x = input[i]; // next token
        if (x != pop(&stack))
            return false;
    }

    return true;
}

int main()
{
    char input[60];
    scanf("%s", input);
    if (isPalindrome(input))
        printf("true");
    else
        printf("false");
}

bool isPalindromeWithoutStack(char input[])
{
    int len = strlen(input);
    for (int i = 0; i < len / 2; i++)
        if (input[i] != input[len - 1 - i])
            return false;
    return true;
}
