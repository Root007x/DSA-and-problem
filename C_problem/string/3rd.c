#include<stdio.h>

void count(char arr[]);

int main()
{
    char str[50];
    printf("Enter string(lowercase) : ");
    gets(str);
    count(str);
    return 0;
}

void count(char arr[]){
    char vowels[5] = "aeiou";
    char cons[21] = "bcdfghjklmnpqrstvwxyz";

    int i = 0, v = 0;

    while(arr[i] != '\0'){
        for (int j = 0; j < 5;j++)
        {
            if(arr[i] == vowels[j]){
                v++;
            }
        }
        i++;
    }
    printf("Vowels : %d \n", v);
    printf("Consonants : %d", i - v);
}