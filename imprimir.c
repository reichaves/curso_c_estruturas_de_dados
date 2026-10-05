#include <stdio.h>
#include <stdlib.h>

/* Run this program using the console pauser or add your own getch, getchar();   */

int main(int argc, char *argv[]) {
    printf("Mensagem1\n");
    printf("Mensagem2\n");
    printf("Mensagem3\n");
    printf("Mensagem4\n");
    getchar();

    printf("Oi, tudo bem?\n");

    printf("Valor inteiro: %d.\n", 10);
    printf("Valor real: %f.\n", 3.14159);
    printf("Valor real com apenas duas casas: %.2lf.\n", 3.14159);
    printf("Dado de texto: %c.\n", 'c');
    printf("Dado de texto: %s.\n", "Olá, mundo parte 2!");

    return 0;
}