#include<stdio.h>

int main()
{
    int min, sec,sum_sec;
    printf("Minute : ");
    scanf("%d", &min);
    printf("Second : ");
    scanf("%d", &sec);

    sum_sec = (min * 60) + sec;
    printf("Seconds : %d", sum_sec);
    return 0;
}