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
    int count[max + 1] = {0};
    int output[size];

    for (int i = 0; i < size; i++) // frequency
    {
        count[arr[i]]++;
    }

    for (int j = 1; j <= max; j++) // cumulative frequency
    {
        count[j] = count[j - 1] + count[j];
    }

    for (int j = size - 1; j >= 0; j--)
    {
        output[--count[arr[j]]] = arr[j];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
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