#include<stdio.h>
#include<math.h>

int main()
{
    int x, n,fact = 1;
    float sum = 1;

    printf("Enter X : ");
    scanf("%d", &x);
    printf("Enter N : ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            fact = fact * j;
        }
        sum = sum + (pow(x, i) / fact);
        fact = 1;
    }

    printf("Result : %.2f",sum);
    return 0;
}