#include<stdio.h>

int main()
{
    int temp, flag, n, a_and_b_size;

    printf("Enter A and B array size : ");
    scanf("%d", &a_and_b_size);

    n = a_and_b_size * 2;
    int a[a_and_b_size], b[a_and_b_size], arr[n];

    for (int i = 0; i < a_and_b_size;i++)
    {
        printf("A[%d] array elements : ",i);
        scanf("%d", &a[i]);
        printf("B[%d] array elements : ",i);
        scanf("%d", &b[i]);
    }

        for (int i = 0; i < a_and_b_size; i++)
        {
            arr[i] = a[i];
            arr[n-1-i] = b[i];

    }

    printf("Merge Array: ");
    for (int i = 0; i < n;i++)
    {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        }

    printf("\nSort Array : ");
    for (int i = 0; i < n;i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}