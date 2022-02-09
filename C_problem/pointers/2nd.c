#include<stdio.h>

void swap(int *p1, int *p2);

int main()
{
    int x = 5, y = 9;
    swap(&x, &y);
    printf("%d %d", x, y);
    return 0;
}

void swap(int *p1,int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

