#include<stdio.h>
#include<math.h>

int main()

{
    int a,sum;
    float s1, s2;
     s1 = 0;
     s2 = 0;

    printf("Enter a number : ");
    scanf("%d", &a);

     for (int i = 0; i <= a;i++)
    {
        if(i % 2 == 0)
        {
            s1 = pow((a - i), 2) + s1;
        }
        else
        {
            s2 = pow((a - i), 2) + s2;
        }
        
    }

    sum = s1 - s2;
    printf("The sum is : %d", sum);

    return 0;
}