#include<stdio.h>

int main()
{
    int number_of_persone = 15;
    int ages[number_of_persone];
    int count = 0;

    int j = 1;
    while(j <= number_of_persone)
    {
        printf("Enter %dth persone age : ",j);
        scanf("%d",&ages[j - 1]);
        j++;
    }

    int i = 0;
    while(i < 15){
        if(ages[i] >= 40 && ages[i] <= 60)
        {
            count++;
        }
        i++;
        continue;
    }
    printf("\nNumber of persone age between 40-60 are : %d", count);
}