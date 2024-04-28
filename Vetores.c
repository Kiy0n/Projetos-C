#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main () {
    char palavra[32];
    int len, totalVogais;

    printf("Informe uma palavra: \n");
    scanf("%31s[^\n]", palavra);

    //Quantas letras tem a palavra.
    len = strlen(palavra);

    //Verificando quantas vogais existem.
    for (int i = 0; i < len; i++) {
        
        //Convertendo tudo para minusculo.
        palavra[i] = tolower(palavra[i]);

        //Verificando a quantidade de vogais.
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u') {
            totalVogais++;
        }
    }

    palavra[0] = toupper(palavra[0]);
    printf("O total de vogais presente na palavra %s eh: %d", palavra, totalVogais);
    
}