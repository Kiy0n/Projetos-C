#include <stdio.h>

int main() {

    int segundosInicial, segundosRestantes, segundosFinais, minutos, horas;
    scanf("%d", &segundosInicial);

    horas = segundosInicial/3600;
    segundosRestantes = segundosInicial%3600;
    minutos = segundosRestantes/60;
    segundosFinais = segundosRestantes%60;

    printf("%d:%d:%d\n", horas, minutos, segundosFinais);
    
    return 0;
}