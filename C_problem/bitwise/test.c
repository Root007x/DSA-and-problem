#include<stdio.h>

int main()
{
 int A[100][100], i, j, rows, columns,sum = 0;
    printf("Number of rows: ");
    scanf("%d",&rows);
    printf("Number of columns: ");
    scanf("%d",&columns);
    for(i = 0;i<rows;i++)
    {
        for(j = 0;j<columns;j++)
        {
            printf("A[%d][%d]: ",i, j);
            scanf("%d",&A[i][j]);
        }
    }
    for (int i = 0; i < columns;i = i + (columns-1)){
        for (int j = 0; j < rows;j++){
            printf("%d\n", A[j][i]);
            sum = sum + A[j][i];
        }
    }
    printf("Sum of coloumn : %d", sum);
    return 0;
}
