#include<stdio.h>

int main()
{
    int array_size = 10, data;
    int arr[10] = {1, 2, 4, 6, 7, 15, 17, 20, 26, 30}; // sorted array
    data = 16;
    int index_left, index_right;
    index_left = 0;
    index_right = array_size - 1;

    while(index_left <= index_right)
    {
        int index_middle;
        index_middle = (index_left + index_right) / 2;

        if(arr[index_middle] == data)
        {
            printf("Data index positon : %d", index_middle);
            break;
        }
        else if(data < arr[index_middle])
        {
            index_right = index_middle - 1;
        }
        else
        {
            index_left = index_middle + 1;
        }
        
    }
    if(index_left > index_right)
    {
        printf("Element is not present in array");
    }

    return 0;
}