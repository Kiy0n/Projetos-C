#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes para melhor desenvolvimento do programa.
#define MAX_CONTATOS 100
#define TAM_NOME 25
#define TAM_TELEFONE 9
#define TAM_EMAIL 50
#define TAM_ENDERECO 100

//Registro principal do programa.
struct Contato {
    char nome[TAM_NOME + TAM_NOME];
    char telefone[TAM_TELEFONE + TAM_TELEFONE];
    char email[TAM_EMAIL];
    char endereco[TAM_ENDERECO + TAM_ENDERECO];

};

//Função para adcionar contatos
void adcionarContato(struct Contato *lista, int *numContatos){
    //Captura o nome do Contato.
    printf("Informe o nome: ");
    getchar();
    fgets(lista[*numContatos].nome, sizeof(lista[*numContatos].nome), stdin); //Utilizando fgets para poder capturar o espaco para receber nome + sobrenome.

    size_t lenNome = strlen(lista[*numContatos].nome);
    if (lenNome > 0 && lista[*numContatos].nome[lenNome - 1] == '\n') {
        lista[*numContatos].nome[lenNome - 1] = '\0';
    }

    //Cadastra o telefone do Contato.
    printf("Informe o numero de telefone: ");
    fgets(lista[*numContatos].telefone, sizeof(lista[*numContatos].telefone), stdin);

    //Cadastra o e-mail do Contato.
    printf("Informe o e-mail: ");
    fgets(lista[*numContatos].email, sizeof(lista[*numContatos].email), stdin);

    //Cadastra o endereço
    printf("Informe o endereco completo: ");
    fgets(lista[*numContatos].endereco, sizeof(lista[*numContatos].endereco), stdin);

    (*numContatos)++;

}

//Função para exibir contatos
void exibirContatos(struct Contato *lista, int numContatos){
    printf("\nLista de Contatos: \n");

    //Loop para mostrar todos os contatos cadastrados bem como seus dados cadastrados.
    for(int i = 0; i < numContatos; i++){
        printf("Nome: %s\n", lista[i].nome);
        printf("Numero: %s\n", lista[i].telefone);
        printf("E-mail: %s\n", lista[i].email);
        printf("Endereco: %s\n", lista[i].endereco);
        printf("---------\n");
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
    printf("Informe o nome do contato a ser alterado: ");
    getchar();
    fgets(nomeAlterar, sizeof(nomeAlterar), stdin);
    //scanf("%s", nomeAlterar);
    size_t len = strlen(nomeAlterar);

    //Verificando se tem espaço no nome
    if(len > 0 && nomeAlterar[len - 1] == '\n'){
        //Removendo o espaço
        nomeAlterar[len - 1] = '\0';
    }

    int indice = buscarContato(lista, numContatos, nomeAlterar);

    if(indice != -1){
        printf("Informe o novo nome: ");
        //scanf("%s", lista[indice].nome);
        fgets(lista[indice].nome, sizeof(lista[indice].nome), stdin);

        len = strlen(lista[indice].nome);
        if (len > 0 && lista[indice].nome[len - 1] == '\n'){
           lista[indice].nome[len - 1] = '\0';
        }

        printf("Informe o novo telefone: ");
        fgets(lista[indice].telefone, sizeof(lista[indice].telefone), stdin);

        printf("Informe o novo e-mail: ");
        fgets(lista[indice].email, sizeof(lista[indice].email), stdin);

        printf("Informe o novo endereco: ");
        fgets(lista[indice].endereco, sizeof(lista[indice].endereco), stdin);

        printf("Contato alterado com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

void removerContato (struct Contato *lista, int *numContatos) {
    char nomeRemover[TAM_NOME + TAM_NOME];
    printf("Informe o nome do contato a ser removido: ");
    getchar();
    fgets(nomeRemover, sizeof(nomeRemover), stdin);

    size_t len = strlen(nomeRemover);
    if (len > 0 && nomeRemover[len - 1] == '\n') {
        //Removendo o espaço
        nomeRemover[len - 1] = '\0';
    }

    int indice = buscarContato(lista, *numContatos, nomeRemover);

    if (indice != -1) {
        for (int i = indice; i < *numContatos - 1; i++){
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
