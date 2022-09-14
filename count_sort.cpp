#include <bits/stdc++.h>

using namespace std;

int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[], int size, int max)
{
    int *arr2 = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        arr2[i] = 0;
    }

    for (int j = 0; j < size; j++)
    {
        arr2[arr[j]]++;
    }
    int i = 0, j = 0;
    while (i < max + 1)
    {
        if (arr2[i] > 0)
        {
            arr[j] = i;
            j++;
            arr2[i]--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[5] = {1, 5, 10, 9, 7};
    int size = 5;

    countsort(arr, size, max(arr, size));

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}