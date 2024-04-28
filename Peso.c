#include <stdio.h>

int  baggage(int peso) {
    int total;
    if(peso <= 23) {
        total = 0;
    } else {
        total = (peso-23)*12;
    }

    return total;  
}

int main() {
    int peso;
    scanf("%d", &peso);

    int total = baggage(peso);
    printf("Total: $%d", total);

    return 0;
}