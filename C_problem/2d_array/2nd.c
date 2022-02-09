#include<stdio.h>

int main()
    
{
    int A[3][4] = { {11, 12, 13, 14},
                    {21, 22, 23, 24},
                    {31, 32, 33, 34}};
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}