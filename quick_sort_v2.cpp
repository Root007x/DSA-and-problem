#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub)
{
    int i = lb;
    int j = ub;
    int pivot = arr[lb];
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[lb], &arr[j]);

    return j;
}

void quicksort(int arr[], int lb, int ub)
{
    int j;
    if (lb < ub)
    {
        j = partition(arr, lb, ub);
        quicksort(arr, lb, j - 1);
        quicksort(arr, j + 1, ub);
    }
}

int main()
{
    int arr[] = {5, 3, 4, 6, 8, 1, INT32_MAX};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}