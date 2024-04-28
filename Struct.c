#include <stdio.h>

typedef struct{
    int x, y;
} point;

typedef struct{
    float radius;
    point center;
} circle;

int main(){
    point p;
    p.x = 3;
    p.y = 4;

    circle c;
    c.radius = 3.14;
    c.center = p;

    printf("O circulo radius é %.2f, o centro é (%d, %d)", c.radius, c.center.x, c.center.y);

    return 0;
}