#include<stdio.h>

typedef struct MovieStar{
    char name[20];
    int rating;
    int total_fan;
} MovieStar;

int main()
{
    MovieStar star[5];

    for (int i = 0; i < 5;i++){
        printf("%dst Movie star name : ", i+1);
        gets(star[i].name);
        printf("Rating : ");
        scanf("%d", &star[i].rating);
        printf("Total Fan : ");
        scanf("%d", &star[i].total_fan);
    }
    printf("\n");
    for (int j = 0; j < 5;j++){
        printf("%s\n", star[j].name);
        printf("%d\n", star[j].rating);
        printf("%d\n", star[j].total_fan);
    }
        return 0;
}