#include<stdio.h>
#include<stdlib.h>

int max(int *p,int size){
    for (int i = 1; i < size;i++)
    {
        if(p[0] < p[i])
        {
            p[0] = p[i];
        }
    }
    return p[0];
}

int main()
{
    int arr_size;
    int *ptr = NULL;
    printf("Enter array size : ");
    scanf("%d", &arr_size);
    ptr = (int *)malloc(arr_size * sizeof(int));

    for (int i = 0; i < arr_size;i++)
    {
        printf("Array[%d] : ", i);
        scanf("%d", ptr + i);
    }

    printf("%d", max(ptr,arr_size));
    return 0;
}