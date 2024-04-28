#include <stdio.h>

typedef struct{
    int h, w, l;
} box;

int main(){
    box boxes[4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    int k, volume;
    for (k = 0; k<4; k++){
        volume = boxes[k].h * boxes[k].w * boxes[k].l;
        printf("box %d volume %d\n", k, volume);
    }
    return 0;
}