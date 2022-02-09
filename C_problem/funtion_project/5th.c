#include<stdio.h>

int fibonacci(int n);
int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Fibonacci : %d",fibonacci(n));
    return 0;
}

int fibonacci(int n)
{
    int sum, prev, next;
    sum = 0;
    prev = 1;
    next = 1;
    if(n == 1)
    {
        return sum;
    }
    else if(n == 2)
    {
        return prev;
    }
    else
    {
        for (int i = 1; i < n-1;i++)
        {
            sum = sum + prev;
            prev = next; 
            next = sum; 
        }
    }
    return sum;
}
