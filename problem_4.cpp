#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shiftarray(int arr[], int size)
{
    int count = 3;
    int i;
    for (int j = 1; j != 4; j++)
    {
        i = size - 1; // 6,5
        while (true)
        {
            swap(arr[i], arr[i - 1]);
            i--;
            if (count == 0)
            {
                break;
            }
            count--;
        }
        count = 3 - j;
        i = size;
    }
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    shiftarray(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}