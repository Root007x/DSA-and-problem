#include<stdio.h>

int main()
{
    int array_size = 5;
    int i, j;
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];

    for (i = array_size - 1, j = 0; i > 0, j < array_size; i--, j++)
    {
        b[j] = a[i];
    }

    for (i = 0; i < array_size; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    for (j = 0; j < array_size;j++)
    {
        printf("%d ", a[j]);
    }
        return 0;
}