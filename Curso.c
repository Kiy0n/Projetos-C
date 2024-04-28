#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
    int id;
    char titulo[40];
    float horas;
}curso;

void atualizaCurso(curso *classe);
void mostraCurso(curso classe);

int main(){
    setlocale(LC_ALL, "Portuguese");

    curso cs;
    atualizaCurso(&cs);
    mostraCurso(cs);

    return 0;
}

void atualizaCurso(curso *classe){
    printf("Digite o ID do curso: ");
    scanf("%d", &classe->id);

    printf("Digite o título du curso: ");
    scanf("%s", classe->titulo);

    printf("Digite a duração do curso: ");
    scanf("%f", &classe->horas);
}

void mostraCurso(curso classe){
    printf("ID: %d\nTitulo: %s\nHoras: %2.2f\n", classe.id, classe.titulo, classe.horas);
}