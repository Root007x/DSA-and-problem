#include<stdio.h>

int main()
{
    int arr[5] = {1, 2, 2, 4, 4};
    int array_size = 5;

    for (int i = 0; i < array_size;i++){
        for (int j = i + 1; j < array_size;j++){
            if(arr[i] == arr[j]){
                printf("Value : %d ,index : %d, %d \n", arr[i], i, j);
            }
        }
    }
    return 0;
}