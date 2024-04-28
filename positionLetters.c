#include <stdio.h>

int main() {
    char word[50];
    int position;
    
    fgets(word, 50, stdin);
    scanf("%d", &position);

    printf("%c", word[position]);

    return 0;
}