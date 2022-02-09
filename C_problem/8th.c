#include<stdio.h>

int main()
{
    int i, x, n;
    x = 3;
    n = 3;
    float temp = 1;
    float result = 1;

    for (i = 1; i <= n ;i++)
    {
        temp = (temp * x) / i;
        result = result + temp;
    }

    printf("%f \n", result);
    return 0;
}
