#include<stdio.h>

int sumOfDigits(int x)
{
    int sum = 0;
    int temp = x;
    int div = x;

    while(div != 0)
    {
        sum = sum + (temp % 10);
        div = div / 10;
        temp = div;
    }

    return sum;
}

int main()
{
    int n;
    printf("Enter any positive number : ");
    scanf("%d", &n);
    printf("Sum of Digits : %d",sumOfDigits(n));
    return 0;
}