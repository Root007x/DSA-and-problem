#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int start = low, end = high;
    int pivot = arr[low];
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[end], &arr[low]);
    return end;
}

void quicksort(int arr[], int low, int high)
{
    int end;
    if (low < high)
    {
        end = partition(arr, low, high);
        quicksort(arr, low, end - 1);
        quicksort(arr, end + 1, high);
    }
}

int main()
{
    int arr[9] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int low = 0;
    int high = 8;
    quicksort(arr, low, high);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}