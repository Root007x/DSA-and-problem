#include <stdio.h>

#define ROW 3
#define COL 7

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(float arr[], int arr2[][COL], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swap(arr2[1][j], arr2[1][j + 1]);
                swap(arr2[2][j], arr2[2][j + 1]);
                swap(arr2[0][j], arr2[0][j + 1]);
            }
}

int main()
{
    int arr[3][7] = {{1, 2, 3, 4, 5, 6, 7},    // items
                     {10, 5, 15, 7, 6, 18, 3}, // profit
                     {2, 3, 5, 7, 1, 4, 1}};   // weight

    float profit_weight[7] = {0.0};
    int capacity = 15;
    float total_profit = 0;

    for (int i = 0; i < 7; i++)
    {
        profit_weight[i] = (float)arr[1][i] / arr[2][i];
    }

    Sort(profit_weight, arr, 7);

    printf("Items : ");
    int i = 0;
    while (1)
    {
        capacity = capacity - arr[2][i];
        if (capacity >= 0)
        {
            total_profit = total_profit + arr[1][i];
            printf("%d ", arr[0][i]);
            if (capacity == 0)
                break;
        }
        else
        {
            float val = capacity + arr[2][i];
            total_profit = total_profit + ((val / arr[2][i]) * arr[1][i]);
            printf("%d ", arr[0][i]);
            break;
        }
        i++;
    }

    printf("\nTotal Profit : %.2f", total_profit);

    return 0;
}