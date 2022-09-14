#include<stdio.h>
#include<conio.h>

void func(int arr[],int size){
        int i = 0,j = size - 1, x = 3;
        int sum1 = 0,sum2 = 0,left = 0,right = 0;
        for(int k = 0;k < 4;k++){  
            while(true){
                    sum1 = sum1 + arr[i];
                    sum2 = sum2 + arr[j];
                    i++; j--;
                    if(x == 0) break;
                    x--;
                }
            printf("%d %d\n",sum1,sum2);
            (sum1 > sum2)?left++:right++;
            sum1 = 0,sum2 = 0;
            x = 2 - k;
            }
        (left > right)?printf("Left Win!!"):printf("Right Win");
        }

int main(){
    int arr[20] = {1,2,11,4,5,6,77,8,9,10,1,2,55,4,31,6,7,8,9,10};
    func(arr,20);
    return 0;
}