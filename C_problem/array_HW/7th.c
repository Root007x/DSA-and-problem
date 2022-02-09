#include<stdio.h>

int main()
{
    int rowA,columnA,rowB,columnB,A[100][100],B[100][100],C[100][100];

    printf("Number of rows in A: ");     
    scanf("%d",&rowA);     
    printf("Number of columns in A: ");     
    scanf("%d",&columnA);     
    printf("Number of rows in B: ");     
    scanf("%d",&rowB);     
    printf("Number of columns in B: ");     
    scanf("%d",&columnB);

    if(rowA != rowB || columnA != columnB)
    {
        printf("Invalid matrix dimensions");
        return 0;
    }

    for(int i=0;i<rowA;i++){         
        for(int j=0;j<columnA;j++)         
        {             
            printf("A[%d][%d]: ",i, j);            
            scanf("%d",&A[i][j]);         
        }     
    }     
    printf("\n"); 

    for(int i=0;i<rowB;i++)     
    {         
        for(int j=0;j<columnB;j++)         
        {             
            printf("B[%d][%d]: ",i, j);             
            scanf("%d",&B[i][j]);         
        }     
    } 

    for (int i = 0; i < rowA;i++)
    {
        for (int j = 0; j < columnA;j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    for (int i = 0; i < rowA;i++)
    {
        for (int j = 0; j < columnA;j++)
        {
            printf("\n%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}