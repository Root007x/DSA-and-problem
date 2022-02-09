#include<stdio.h>

double getArea(int a, int b, int h) 
{
    return ((float)1 / 2) * (a + b) * h;
}

int main()
{
    int a, b, h;
    double trapezoid;
    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);
    printf("Enter h : ");
    scanf("%d", &h);

    trapezoid = getArea(a, b, h);
    printf("%0.2f", trapezoid);
    return 0;
}