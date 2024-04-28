//Partes comentadas sao para versao do struct e a utilizada é typedef.
#include <stdio.h>

/*
struct estudante{
    char nome[50];
    int numero, idade;
};
*/

typedef struct{
    char nome[50];
    int numero, idade;
} estudante;

//void mostraEstudanteData(struct estudante *est){
    void mostraEstudanteData(estudante *est){
    printf("\nEstudante:\n");
    /*
    printf("Nome: %s\n", est->nome);
    printf("Numero: %d\n", est->numero);
    printf("Idade: %d\n", est->idade);
    */
    printf("Nome: %s\n", (*est).nome);
    printf("Numero: %d\n", (*est).numero);
    printf("Idade: %d\n", (*est).idade);
}

int main (){
    //struct estudante est1 = {"Gabriel", 0, 24};
    //struct estudante est2 = {"Crowley", 1, 600};
    estudante est1 = {"Gabriel", 0, 24};
    estudante est2 = {"Crowley", 1, 600};

    mostraEstudanteData(&est1);
    mostraEstudanteData(&est2);

    return 0;
}