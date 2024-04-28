#include <stdio.h>

int main() {
    int inicio, fim, i;
    scanf("%d", &inicio);
    scanf("%d", &fim);

    if (inicio > fim) {
        for(i = inicio; i>=fim; i--) {
        printf("%d ", i);
        }
    } else {
        for(i = inicio; i<=fim; i++) {
        printf("%d ", i);
        }
    }

    return 0;
}