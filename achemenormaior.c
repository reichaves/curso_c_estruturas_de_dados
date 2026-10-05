// Importa uma biblioteca padrão de entrada e saída
#include <stdio.h>

// Declara a função principal do programa
int main() {
    // Declara e inicializa um vetor de inteiros com 5 elementos
    int v[] = {12, 5, 23, 8, 1, 19};
    // Calcula o tamanho do vetor 
    // sizeof(v) retorna a quantidade de bytes ocupados pelo vetor v
    // sizeof(v[0]) retorna a quantidade de bytes ocupados pelo primeiro elemento do vetor v
    int n = sizeof(v) / sizeof(v[0]);

    // Declara uma variável de maior valor e inicializa com o primeiro elemento do vetor
    int maior = v[0];
    // Declara uma variável de menor valor e inicializa com o primeiro elemento do vetor
    int menor = v[0];

    // Percorre o vetor a partir do segundo elemento até o último (índice n-1)
    // int i = 1 é inicialização, declara a variável de controle do loop
    // i < n é a condição de permanência do loop, enquanto i form menor que n
    // i++ é o incremento da variável controle
    for (int i = 1; i <n; i++) {
        // Avalia se o elemento atual do vetor é maior do que o valor armazenado na variável maior
        if (v[i] > maior) {
            // Atualiza a variável
            maior = v[i];
        // Caso não seja maior, avalia se o elemento atual do vetor é menor do que o valor armazenado
        } else if (menor > v[i]) {
            // Atualiza a variável
            menor = v[i];
        
        }

    }
    // Exibe no terminal o maior valor encontrado
    printf("Maior valor: %d\n", maior);
    // Exibe o menor valor
    printf("Menor valor: %d\n", menor);

    // Retorna 0 para indicar ao SO que a execução foi bem-sucedida
    return 0;
}