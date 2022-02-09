#include<stdio.h>

struct complex{
    float real;
    float imag;
};

struct complex add(struct complex n1, struct complex n2);

int main(){
    struct complex n1, n2,result;
    printf("Enter 1st real and imag number : ");
    scanf("%f %f", &n1.real, &n1.imag);
    printf("Enter 2nd real and imag number : ");
    scanf("%f %f", &n2.real, &n2.imag);

    result = add(n1,n2);

    printf("Sum of two complex number = %.1f + %.1fi", result.real, result.imag);
    return 0;
}

struct complex add(struct complex n1,struct complex n2){
    struct complex result;
    result.real = n1.real + n2.real;
    result.imag = n1.imag + n2.imag;
    return result;
}