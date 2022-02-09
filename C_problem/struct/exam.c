#include<stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    if(num == 61){
        printf("Brasilia");
    }
    else if(num == 71){
        printf("Salvodor");
    }
    else if(num == 11){
        printf("Sao Paulo");
    }
    else if (num == 21){
        printf("Rio de Janeiro");
    }
    else if (num == 32){
        printf("Juiz de Fora");
    }
    else if(num == 19){
        printf("Campinas");
    }
    else if (num == 27){
        printf("Vitoria");
    }
    else if (num == 31){
        printf("Belo Horizonte");
    }
    else{
        printf("DDD nao cadastrado (DDD not found)");
    }
    return 0;
}