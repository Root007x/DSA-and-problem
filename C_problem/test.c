#include<stdio.h>
int fact = 1;
int main()
{
    for (int i = 3; i > 0; i--)
    {
        fact = fact * i;
    }
    printf("%d", fact);
    return 0;
}
