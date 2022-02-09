#include<stdio.h>

int main()
{
    int trans[100][100],a[100][100], row, column;

    printf("Enter row and coloum : ");
    scanf("%d %d", &row, &column);

    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < column;j++)
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            trans[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

        return 0;
}