#include<stdio.h>

int main(){
    char c[] = "Hello,Boss,FOO";
    char *p;
    p = strtok(c, ",");
    while(p != NULL){
        printf("%s\n", p);
        p = strtok(NULL, ",");
    }
}