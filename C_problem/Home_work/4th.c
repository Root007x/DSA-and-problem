#include<stdio.h>

double harmonicSum(int n)
{
    double sum = 0;
    for (int i = 1; i <= n;i++){
        sum = sum + (1 / (double)i);
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter any Number : ");
    scanf("%d", &n);
    printf("Harmonic Sum : %0.2f", harmonicSum(n));
    return 0;
}