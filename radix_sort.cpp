#include <bits/stdc++.h>

using namespace std;

void sortarray(int arr[], int size, int pos);
void radixsort(int arr[], int size);
int maxval(int arr[], int size);

int maxval(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void radixsort(int arr[], int size)
{
    int max = maxval(arr, size);
    int pos;
    for (pos = 1; (max / pos) > 0; pos = pos * 10)
    {
        sortarray(arr, size, pos);
    }
}

void sortarray(int arr[], int size, int pos)
{
    int count[10] = {0};
    int output[size];

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (int j = 1; j < 10; j++)
    {
        count[j] = count[j - 1] + count[j];
    }

    for (int k = size - 1; k >= 0; k--)
    {
        output[--count[(arr[k] / pos) % 10]] = arr[k];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {97, 208, 57, 734, 125, 699};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}