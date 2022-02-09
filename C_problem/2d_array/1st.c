#include<stdio.h>

int main()
{
    int n = 6;
    int temp;
    int swepped;
    int arr[6] = {77, 42, 35, 12, 110, 5};

    for (int i = 0; i < n - 1; i++)
    {
        swepped = 0;
        for (int j = 0; j < n - 1 - i;j++)
        {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swepped = 1;
            }
        }
        if(swepped == 0)
        {
            break;
        }
    }
    for (int i = 0; i < n;i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n%d", arr[5]);

    return 0;
}