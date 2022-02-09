#include<stdio.h>
#include<math.h>

int main()
{
    int a, x,power;
    printf("Enter any number : ");
    scanf("%d", &a);
    printf("Enter power : ");
    scanf("%d", &x);

    power = pow(a, x);
    printf("Result : %d", power);
    return 0;
}