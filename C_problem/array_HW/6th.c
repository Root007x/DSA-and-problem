#include<stdio.h>

int main()
{
    int temp,flag;
    int n = 8; // array size
    int arr[8] = {1, 5, 9, 10, 15,20 ,50 ,100};

    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = n - 1; j > 0 + i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        }

    printf("Top three largers element are : %d %d %d", arr[0], arr[1], arr[2]);

    return 0;
}