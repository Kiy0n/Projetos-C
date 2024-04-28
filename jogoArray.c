#include <stdio.h>

int main() {
    float results[] = {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1};
    int valor;
    for(int i = 0; i<sizeof(results); i++){
        if (results[i] == 1){
            valor++;
        }
    }

    printf("%d", valor);
    
    return 0;
}