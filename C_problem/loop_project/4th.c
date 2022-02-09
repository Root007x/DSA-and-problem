#include<stdio.h>

int main()
{

    int sum, prev, next,n;
    sum = 0;
    prev = 1;
    next = 1;

    printf("Enter n : ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    printf("%d %d ", sum, prev);

    for (int i = 1; i < n-1; i++)
    {
        sum = sum + prev;
        printf("%d ", sum);
        prev = next; 
        next = sum; 
    }
    return 0;
}