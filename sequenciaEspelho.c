#include <stdio.h>

int main(){
    int casos, num1, num2;

    //printf("Quantos testes você gostaria de fazer? ");
    scanf("%d", &casos);

    for (int teste = 1; teste <= casos; teste++){
        //printf("Informe o primeiro número: ");
        scanf("%d", &num1);
        //printf("Informe o segundo número: ");
        scanf("%d", &num2);

        //Seuquência normal
        for (int i = num1; i <= num2; i++){
            printf("%d", i);
        }
        
        //Sequencia espelho
        for (int i = num2; i >= num1; i--){
            int temp = i;
            while (temp > 0){
                printf("%d", temp % 10);
                temp /= 10;
            }
        }
        printf("\n");
    }
    
    return 0;
}