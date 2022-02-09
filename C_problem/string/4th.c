#include<stdio.h>
#include<string.h>

void reverse(char arr[]);

int main()
{
    char str[50] = "heol";
    printf("Enter string : ");
    gets(str);
    reverse(str);
    return 0;
}

void reverse(char arr[]){
    int len = strlen(arr);
    char rev[50] = {0};
    
    for (int i = len - 1,j = 0; i < 0,j < len;i--,j++){
        rev[j] = arr[i];
    }
    printf("Reverse order : ");
    puts(rev);
}