#include<stdio.h>

int main()
{
    int n, fact = 1;

    printf("Enter any positive number : ");
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        fact = fact * i;
    }

    printf("Factorical of %d is : %d",n, fact);
    return 0;
}
