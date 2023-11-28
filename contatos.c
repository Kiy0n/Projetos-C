#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes para melhor desenvolvimento do programa.
#define MAX_CONTATOS 100
#define TAM_NOME 25
#define TAM_TELEFONE 18
#define TAM_EMAIL 50
#define TAM_ENDERECO 100

//Struct principal do programa.
struct Contato {
    char nome[TAM_NOME + TAM_NOME];
    char telefone[TAM_TELEFONE];
    char email[TAM_EMAIL];
    char endereco[TAM_ENDERECO + TAM_ENDERECO];

};

//Função para adcionar contatos
void adcionarContato(struct Contato *lista, int *numContatos){
    //Captura o nome do Contato.
    printf("Informe o nome: \n");
    getchar(); // Limpa o buffer
    fgets(lista[*numContatos].nome, sizeof(lista[*numContatos].nome), stdin); //Utilizando fgets para poder capturar o espaco para receber nome + sobrenome.

    //Cadastra o telefone do Contato.
    printf("Informe o numero de telefone: \n");
    scanf("%s", lista[*numContatos].telefone);

    //Cadastra o e-mail do Contato.
    printf("Informe o e-mail: \n");
    scanf("%s", lista[*numContatos].email);

    //Cadastra o endereço
    printf("Informe o endereco completo: \n");
    getchar();
    fgets(lista[*numContatos].endereco, sizeof(lista[*numContatos].endereco), stdin);

    (*numContatos)++;

}

//Função para exibir contatos
void exibirContatos(struct Contato *lista, int numContatos){
    printf("\n ----- Lista de Contatos ----- \n");

    //Loop para mostrar todos os contatos cadastrados bem como seus dados cadastrados.
    for(int i = 0; i < numContatos; i++){
        printf("Nome: %s\n", lista[i].nome);
        printf("Numero: %s\n", lista[i].telefone);
        printf("E-mail: %s\n", lista[i].email);
        printf("Endereco: %s\n", lista[i].endereco);
        printf("---------------------\n");
    }
}

//Função auxiliar para a função de alterar e remover os contatos.
int buscarContato(const struct Contato *lista, int numContatos, const char *nome){
    //Loop para buscar o contato informado.
    for(int i = 0; i < numContatos; i++){
        //Verificando se o contato existe, se retornar 0 = true, -1 = false (contato não existe)
        if (strcmp(lista[i].nome, nome) == 0){
            return i;
        }
    }
    return -1;
}

//Função para alterar o contato existente
void alterarContato(struct Contato *lista, int numContatos){
    char nomeAlterar[TAM_NOME + TAM_NOME];
    printf("Informe o nome do contato a ser alterado: \n");
    getchar();
    fgets(lista);
    //scanf("%s", nomeAlterar);

    int indice = buscarContato(lista, numContatos, nomeAlterar);

    if(indice != -1){
        printf("Informe o novo nome: ");
        scanf("%s", lista[indice].nome);

        printf("Informe o novo telefone: ");
        scanf("%s", lista[indice].telefone);

        printf("Informe o novo e-mail: ");
        scanf("%s", lista[indice].email);

        printf("Informe o novo endereco: ");
        scanf("%s", lista[indice].endereco);

        printf("Contato alterado com sucesso!");
    } else {
        printf("Contato nao encontrado. \n");
    }
}

void removerContato (struct Contato *lista, int *numContatos){
    char nomeRemover[TAM_NOME + TAM_NOME];
    printf("Informe o nome do contato a ser removido: ");
    scanf("%s", nomeRemover);

    int indice = buscarContato(lista, *numContatos, nomeRemover);

    if(indice != -1){
        for (int i = 0; i < *numContatos - 1; i++){
            lista[i] = lista[i + 1];
        }
        (*numContatos)--;
        printf("Contato removido com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

int main (){
    struct Contato listaContatos[MAX_CONTATOS];
    int numContatos = 0;
    int opcao;

    //Menu para desejar a opção
    do{
        printf("\nMENU\n");
        printf("1 - Adicionar um contato \n");
        printf("2 - Exibir contatos \n");
        printf("3 - Alterar um contato \n");
        printf("4 - Remover um contato \n");
        printf("5 - Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                adcionarContato(listaContatos, &numContatos);
                break;
            case 2:
                exibirContatos(listaContatos, numContatos);
                break;
            case 3:
                alterarContato(listaContatos, numContatos);
                break;
            case 4:
                removerContato(listaContatos, &numContatos);
                break;
            case 5:
                printf("Saindo do programa. \n");
                break;
            default:
                printf("Opcao invalida tente novamente. \n");
        }
    } while (opcao != 5);

    return 0;
}