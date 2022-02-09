#include <stdio.h>

void perfect_number(int n1, int n2);

int  main(){
  int n1,n2;
  printf("Starting range or number : ");
  scanf("%d",&n1);
  printf("Ending range of number : ");
  scanf("%d",&n2);
  perfect_number(n1, n2);
  return 0;
}

void perfect_number(int n1,int n2){

    int sum;
    printf("The Perfect numbers within the given range : ");
    for(int i = n1;i <= n2; i++){
    int j = 1;
    sum = 0;

    while(j < i){
      if(i % j == 0)
        sum=sum+j;
        j++;
    }

    if(sum == i)
      printf("%d ",i);
  }
      printf("\n");
}
