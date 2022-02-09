#include<stdio.h>

int main()
    
{
    int A[3][4];
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            printf("A[%d][%d]: ",i, j); 
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}