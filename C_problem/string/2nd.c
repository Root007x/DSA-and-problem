#include<stdio.h>

void search(char arr[], char key);

int main()
{
    char str[50], key;
    printf("Enter string : ");
    gets(str);
    printf("Enter key : ");
    scanf("%c", &key);
    search(str, key);
    return 0;
}

void search(char arr[],char key){
    int i = 0;
    while(arr[i] != '\0')
    {
        if(arr[i] == key){
            printf("Found");
            return;
        }
        i++;
    }
    printf("Not Found");
}