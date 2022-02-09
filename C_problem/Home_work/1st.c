#include<stdio.h>

int sum(int n){
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter any positive number : ");
    scanf("%d", &n);
    printf("Sum : %d", sum(n));
    return 0;
}