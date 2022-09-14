#include <bits/stdc++.h>

#define ROW 3
#define COL 8

using namespace std;

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
    int arr[3][8] = {{1, 2, 3, 4, 5, 6, 7, 8},    // items
                     {10, 6, 25, 6, 4, 3, 3, 28}, // profit
                     {4, 3, 5, 6, 1, 2, 1, 7}};   // weight

    float profit_weight[COL] = {0.0};
    int capacity = 20; // bag size
    float total_profit = 0;

    for (int i = 0; i < COL; i++)
    {
        profit_weight[i] = (float)arr[1][i] / arr[2][i];
    }

    Sort(profit_weight, arr, COL);

    printf("Items : ");
    int i = 0;
    while (true)
    {
        capacity = capacity - arr[2][i]; // weight
        if (capacity >= 0)
        {
            total_profit = total_profit + arr[1][i]; // profit
            cout << arr[0][i] << " ";
            if (capacity == 0)
                break;
        }
        else
        {
            float val = capacity + arr[2][i];
            total_profit = total_profit + ((val / arr[2][i]) * arr[1][i]);
            cout << arr[0][i] << " ";
            break;
        }
        i++;
    }

    cout << "\n"
         << "Total Profit : " << total_profit;

    return 0;
}