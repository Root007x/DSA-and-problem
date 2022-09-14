#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

int main()
{
    int arr[5] = {11, 2, 5, 66, 7};
    selection_sort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}