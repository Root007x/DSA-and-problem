#include<stdio.h>

int length(char *prt){
    int i = 0,count = 0;
    while(prt[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    char str[] = "Hello World!!";
    char *ptr = NULL;

    printf("Length of String : %d",length(str));
}
