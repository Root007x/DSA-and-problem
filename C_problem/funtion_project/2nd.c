#include<stdio.h>

int computeAverage(int a , int b)
{
    return (a + b) / 2;
}

int main()

{
    int a, b, average;
    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);

    average = computeAverage(a, b);
    printf("Average : %d", average);
    return 0;
}