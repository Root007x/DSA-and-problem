#include<stdio.h>

int sum_of_series(int n);

int main()
{
    int n, sum;

    printf("Enter n Value: ");
    scanf("%d", &n);

    sum = sum_of_series(n);

    printf("Sum of series : %d", sum);
    return 0;
}

int sum_of_series(int n){
    int fact = 1,sum = 0;

    for (int i = 1; i <= n;i++){
        for (int j = i; j > 0;j--)
        {
            fact = fact * j;
        }
        sum = sum + (fact/i);
        fact = 1;
    }
    return sum;
}