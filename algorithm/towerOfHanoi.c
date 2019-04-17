#include <stdio.h>

void Hanoi(int n, char a, char b, char c)
{
    /*if (n == 1)
        printf("move disk 1 form %c to %c\n", a, c);
    else*/
    if(n)
    {
        Hanoi(n - 1, a, c, b);
        printf("mode disk %d from %c to %c\n", n, a, c);
        Hanoi(n - 1, b, a, c);
    }
}

int main()
{
    Hanoi(3, 'a', 'b', 'c');
}
