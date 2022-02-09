#include<stdio.h>

int length(char str[]);

int main()
{
    char str[50];
    printf("Enter string : ");
    gets(str);
    printf("Lenght is : %d", length(str));
    return 0;
}

int length(char str[]){
    int i = 0, count = 0;
    while(str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}