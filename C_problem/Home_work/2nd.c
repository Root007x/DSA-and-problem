#include<stdio.h>

void ListNumberAsc(int start,int end)
{
    if(start < end){
    for (int i = start; i <= end; i++)
    {
        printf("%d ", i);
    }
    }
    else{
        for (int i = end; i <= start; i++)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int start, end;
    printf("Start : ");
    scanf("%d", &start);
    printf("End : ");
    scanf("%d", &end);
    ListNumberAsc(start, end);
    return 0;
}
