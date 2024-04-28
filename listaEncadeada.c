#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *ListaInserir(Lista *l, int v){
    Lista *Novo = (Lista*)malloc(sizeof(Lista));
    Novo->info = v;
    Novo->prox = l;

    return Novo;
}

void ListaImprimir(Lista *l){
    for(Lista *p = l; p != NULL; p = p->prox){
        printf("%d\n", p->info);
    }
}

Lista* UltimoDaLista(Lista *l){
    Lista *p;
    for(p = l; p != NULL; p = p->prox){
        if(p->prox == NULL) break;
    }

    return p;
}

Lista *ListaConcatena(Lista *l1, Lista *l2){
    Lista *p;
    for(p = l1; p != NULL; p = p->prox){
        if (p->prox == NULL){
            p->prox == l2;
        }
    }

    return p;
}

int main(){
    Lista *l1 = NULL;
    Lista *l2 = NULL;

    l1 = ListaInserir(l1, 1);
    l1 = ListaInserir(l1, 4);
    l1 = ListaInserir(l1, 2);
    l2 = ListaInserir(l2, 9);
    l2 = ListaInserir(l2, 7);
    l2 = ListaInserir(l2, 8);

    ListaImprimir(l1);
    ListaImprimir(l2);
    ListaConcatena(l1, l2);
    ListaImprimir(l1);

    return 0;
}