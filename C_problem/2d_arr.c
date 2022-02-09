#include<stdio.h>

int main()
{
    int row, coloum,coloum_key,sum;
    sum = 0;
    printf("Enter number of row: ");
    scanf("%d", &row);
    printf("Enter number of coloum : ");
    scanf("%d", &coloum);
    int arr_2d[row][coloum];
    printf("Enter Element \n");
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < coloum; j++)
        {
            printf("Array[%d][%d] : ",i,j);
            scanf("%d", &arr_2d[i][j]);
            
        }
    }
    printf("Enter which coloum to find sum : ");
    scanf("%d", coloum_key);

    for (int i = 0; i < row;i++)
    {
        sum += arr_2d[i][coloum_key-1];
    }

    printf("sum of coloum %d: %d", coloum_key,sum);
    return 0;
}



