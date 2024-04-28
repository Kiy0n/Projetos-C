#include <stdio.h>

//create the swap() function here
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main() {
    int x, y;

    scanf("%d %d", &x, &y);

    printf("x is %d, y is %d\n", x, y); 
    swap(&x, &y);
    printf("x is %d, y is %d\n", x, y); 

    return 0;
}