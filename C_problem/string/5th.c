#include<stdio.h>

int compare(char str1[], char str2[]);

int main()
{
    char str1[50], str2[50];
    printf("Enter string 1 : ");
    gets(str1);
    printf("Enter string 2 : ");
    gets(str2);
    printf("%d",compare(str1, str2));
    return 0;
}

int compare(char str1[],char str2[]){
    int flag1 = 0, flag2 = 0,i = 0;

    while(str1[i] != '\0'){
        if(str1[i] == str2[i]){
            flag1 = 1;
        }
        else{
            flag2 = 1;
        }
        i++;
    }
    if(flag1 == flag2){
        return -1;
    }
    else{
        return 1;
    }
}