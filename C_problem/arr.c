#include<stdio.h>

void search(int arr[],int size,int key)
{
    int count = 0;
    for (int i = 0; i < size;i++)
    {
        if(arr[i]== key)
        {
            count++;
            continue;
        }
    }
    printf("Search Key appears %d times",count);
}

int main()
{
    int size,key;
    printf("Enter Size: ");
    scanf("%d",&size);
    int arr[size];
    
    for (int i = 0; i < size;i++)
    {
        printf("Enter %d index Array Element : ",i);
        scanf("%d", &arr[i]);
    }
    printf("Enter Key: ");
    scanf("%d", &key);

    search(arr, size, key);

    return 0;
} 