#include<stdio.h>

int main(){
    int i = 50, j = 70, *pi = &i, *pj = &j;
    *pj = j + 5;
    i = *pj + 5;
    printf("%d %d %d \n", i, j, *pj);
    *pi = i + j;
    printf("%d %d %d %d", i, j, *pi);
}