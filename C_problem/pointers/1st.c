// Accessing array elements using pointers
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n = 5;
    int *ptr = NULL;
    ptr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n;i++)
    {
        printf("A[%d]", i);
        scanf("%d", (ptr + i));
    }

    for (int j = 0; j < n;j++)
    {
        printf("%d ", *(ptr + j));
    }

    free(ptr);
    return 0;
}