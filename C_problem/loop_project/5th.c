#include <stdio.h>

int main()
{
   int lines;
   printf("Enter lines : ");
   scanf("%d",&lines);

    for(int i = 0; i <= lines; i++)
   {
     for(int j = 1;j <= lines-i ;j++){
         printf(" ");
     }       
     for(int j = 1 ; j <= 2*i-1; j++){
         printf("*");
     }       
     printf("\n");
   }
   return 0;
}
