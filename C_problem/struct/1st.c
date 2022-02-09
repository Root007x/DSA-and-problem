#include<stdio.h>

struct Shape{
    double length;
    double width;
};

int findArea(struct Shape R);
int findPerimeter(struct Shape R);

int main(){
    int len, wid;
    struct Shape Rectangle;
    printf("Length: ");
    scanf("%d", &len);
    printf("Width : ");
    scanf("%d", &wid);
    Rectangle.length = len;
    Rectangle.width = wid;
    printf("Area : %d\n", findArea(Rectangle));
    printf("Perimeter : %d", findPerimeter(Rectangle));
    return 0;
}

int findArea(struct Shape R){
    return R.length * R.width;
}

int findPerimeter(struct Shape R){
    return 2 * (R.length + R.width);
}