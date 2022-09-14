#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    int weight[] = {0, 3, 4, 5, 6}; // sorted
    int profit[] = {0, 2, 3, 4, 1};
    int i = 4;
    int w = 8; // capacity
    int arr[i + 1][w + 1];

    for (int row = 0; row <= i; row++)
    {
        for (int col = 0; col <= w; col++)
        {
            if (row == 0 || col == 0)
            {
                arr[row][col] = 0;
            }
            else if (weight[row] > col)
            {
                arr[row][col] = arr[row - 1][col];
            }
            else
            {
                arr[row][col] = max(arr[row - 1][col], arr[row - 1][col - weight[row]] + profit[row]);
            }
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Maximum Profit : " << arr[i][w];
    return 0;
}