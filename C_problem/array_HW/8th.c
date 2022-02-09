#include<stdio.h>

int main()
{
    int sum, c[100][100];
    int rowa, rowb, columna, columnb;
    printf("Number of rows in A: ");
    scanf("%d",&rowa);
    printf("Number of columns in A: ");
    scanf("%d",&columna);
    printf("Number of rows in B: "); 
    scanf("%d",&rowb);
    printf("Number of columns in B: "); 
    scanf("%d",&columnb); 

    if(columna != rowb)     
    {         
        printf("Invalid matrix dimensions\n");
        return 0;     
    }

    int a[100][100] = {{1, 0, -2},
                       {3, -2, -1}};
    int b[100][100] = {{-1, 3},
                       {4, 0},
                       {2, 6}};

    for (int r = 0; r < rowa; r++)
    {
        for (int i = 0; i < columnb; i++)
        {
            sum = 0;
            for (int j = 0; j < columna; j++)
            {
                sum = sum + a[r][j] * b[j][i];
            }
            c[r][i] = sum;
        }
    }

    for (int i = 0; i < rowa;i++)
    {
        for (int j = 0; j < columnb;j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}