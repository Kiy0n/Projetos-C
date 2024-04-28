#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char titulo[40];
    float horas;
}curso;

void atualizaCurso(curso *classe);
void mostraCurso(curso classe);

int main(){
    curso cs1;
    atualizaCurso(&cs1);
    mostraCurso(cs1);

    return 0;
}

void atualizaCurso(curso *classe){
    strcpy(classe->titulo, "AEDS II");
    classe->id = 101;
    classe->horas = 59.5;
}

void mostraCurso(curso classe){
    printf("ID: %d\tTitulo: %s\tHoras: %2.2f\n", classe.id, classe.titulo, classe.horas);
}