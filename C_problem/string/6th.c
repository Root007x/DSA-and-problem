#include<stdio.h>

void replace(char arr[], char oldChar, char newChar);

int main()
{
    char str[50],oldChar,newChar;
    printf("Enter string : ");
    gets(str);
    printf("Enter old char : ");
    scanf(" %c", &oldChar);
    printf("Enter new char : ");
    scanf(" %c", &newChar);
    replace(str, oldChar, newChar);
    return 0;
}

void replace(char arr[],char oldChar,char newChar){
    int i = 0;

    while(arr[i] != '\0'){
        if(arr[i] == oldChar){
            arr[i] = newChar;
        }
        i++;
    }
    printf("Modified String : ");
    puts(arr);
}