#include <bits/stdc++.h>

using namespace std;

void mergearray(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[100];

    while (i <= mid && j <= ub)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i <= ub; i++)
    {
        arr[i] = b[i];
    }
}

void mergesort(int arr[], int lb, int ub) // lb = lower bound, ub = upper bound
{
    if (lb < ub) // base condition
    {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);      // left part
        mergesort(arr, mid + 1, ub);  // right part
        mergearray(arr, lb, mid, ub); // marge part
    }
}

int main()
{
    int arr[] = {7, 3, 2, 16, 24, 4, 11, 9};
    int size = 8;

    cout << "Before Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    mergesort(arr, 0, size - 1);

    cout << "\n"
         << "After Sort : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}