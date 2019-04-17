#include <stdio.h>
#define SIZE 3

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char list[], int i, int size)
{
    if (i == size - 1)
    {
        for (int j = 0; j < size; j++)
            printf("%c ", list[j]);
        printf("\n");
    }
    else
    {
        for (int j = i; j < size; j++)
        {
            swap(&list[i], &list[j]);
            permutation(list, i + 1, size);
            swap(&list[i], &list[j]);
        }
    }
}

int main()
{
    char list[SIZE] = {'a', 'b', 'c'};
    permutation(list, 0, SIZE);
}
