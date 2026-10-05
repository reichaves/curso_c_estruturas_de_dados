# Estudos de C para Estruturas de Dados

Diretório de estudos para a disciplina **SIN5013 – Análise de Algoritmos e Estruturas de Dados** (pós-graduação em Sistemas de Informação, EACH-USP), ministrada pelo Prof. Dr. Luciano Antonio Digiampietri no 2º semestre de 2026.

O foco aqui é a linguagem C aplicada a estruturas de dados, seguindo o material do professor em [each.usp.br/digiampietri/ed](https://www.each.usp.br/digiampietri/ed/) e a apostila **ACH2023 – Algoritmos e Estruturas de Dados I** (Willian Yukio Honda e Ivandré Paraboni), incluída neste repositório como `ACH2023.pdf`.

## Links da disciplina

| Recurso | Link |
|---|---|
| Página da disciplina SIN5013 | https://www.each.usp.br/digiampietri/SIN5013/ |
| Aulas de Estruturas de Dados em C (slides e códigos) | https://www.each.usp.br/digiampietri/ed/ |
| Videoaulas (UNIVESP) | [Playlist "Estrutura de Dados"](https://www.youtube.com/playlist?list=PLxI8Can9yAHf8k8LrUePyj0y3lLpigGcl) |
| Códigos em HTML | http://www.each.usp.br/digiampietri/ACH2023/javaec/javaec.htm#ed |

## Conteúdo deste repositório

### Exercícios de introdução ao C

| Arquivo | O que pratica |
|---|---|
| `hello.c` | Primeiro programa: `printf` e `getchar()` para pausar o console |
| `helloworld.cpp` | Mesmo "Hello, World!" em C, salvo com extensão `.cpp` |
| `idade.c` | Declaração e atribuição de variável `int`, impressão com `%d` |
| `imprimir.c` | Especificadores de formato do `printf`: `%d`, `%f`, `%.2lf`, `%c`, `%s` |
| `inserir_idade.c` | Leitura de inteiro com `scanf("%d", &idade)` |
| `atribuicao_constancia.c` | Constantes com `#define` e leitura de `int`, `float` e `char[]` com `scanf` |
| `achemenormaior.c` | Vetores, `sizeof` para calcular o tamanho, laço `for` e busca do maior e do menor valor |
| `main.cpp` | Comparação com C++: `iostream`, `cout` e soma de dois inteiros |

`achemenormaior.c` é o único arquivo com comentários linha a linha. Ele também mostra o padrão `sizeof(v) / sizeof(v[0])`, usado o tempo todo nas estruturas sequenciais.

### Material de referência

- **`ACH2023.pdf`**: apostila de 55 páginas com os algoritmos em C de todas as estruturas vistas no curso (detalhes abaixo).
- **`.vscode/tasks.json`**: tarefa de build padrão do VS Code. Compila o arquivo aberto com `clang -g` e gera o executável na mesma pasta.

Os executáveis (`hello`, `idade`, ...) e as pastas `*.dSYM/` (símbolos de depuração do macOS) saem da compilação e não precisam ir para o Git. Veja a sugestão de `.gitignore` no fim deste arquivo.

## Como compilar e executar

No macOS, o compilador é o `clang` (instalado com `xcode-select --install`).

```bash
# Programas em C
clang -g idade.c -o idade
./idade

# Programa em C++
clang++ -g main.cpp -o main
./main
```

No VS Code, abra um arquivo `.c` e use **Terminal → Executar Tarefa de Build** (`⇧⌘B`). A tarefa definida em `.vscode/tasks.json` compila o arquivo ativo.

Opções úteis para estudar:

```bash
clang -Wall -Wextra -std=c11 -g arquivo.c -o arquivo   # mostra mais avisos
clang -fsanitize=address -g arquivo.c -o arquivo        # detecta erros de memória (útil a partir das listas dinâmicas)
```

## Roteiro das aulas de Estruturas de Dados em C

Sequência das aulas publicadas em [digiampietri/ed](https://www.each.usp.br/digiampietri/ed/). Cada aula tem um PDF de slides e os códigos-fonte correspondentes.

| Aula | Tema | Códigos |
|---|---|---|
| 01 | Introdução ao curso | `HelloWorld.c` |
| 02 | Primeira estrutura de dados (`struct`) | `testaEstrutura.c`, `EstruturaSimples.c`, `EstruturaSimples2.c` |
| 03 | Lista sequencial | `listaSequencial.c` |
| 04 | Lista sequencial ordenada (sentinela, busca binária) | `listaSequencialOrdenada.c` |
| 05 | Lista ligada – implementação estática | `listaLigada.c`, `usaListaLigadaInterativo.c` |
| 06 | Lista ligada – implementação dinâmica | `exemploDoisRetornos.c`, `listaLigadaD.c`, `usaListaLigadaInterativoD.c` |
| 07 | Lista ligada circular com nó-cabeça | `listaLigadaCabCirc.c`, `usaListaLigadaInterativoCC.c` |
| 08 | Pilha – implementação estática | `pilhaEstatica.c`, `usaPilhaEstatica.c` |
| 09 | Pilha – implementação dinâmica | `pilhaDinamica.c`, `usaPilhaDinamica.c` |
| 10 | Deque – implementação dinâmica | `dequeDinamico.c`, `usaDequeDinamico.c` |
| 11 | Fila – implementação estática | `filaEstatica.c`, `usaFilaEstatica.c` |
| 12 | Fila – implementação dinâmica | `filaDinamica.c`, `usaFilaDinamica.c` |
| 13 | Duas pilhas em um único vetor | `duasPilhasEstaticas.c`, `usaDuasPilhasEstaticas.c` |
| 14 | Matriz esparsa | `matrizSimples.c`, `esparsasArranjoDeListas.c`, `usaEsparsasArranjoDeListas.c` |

Os arquivos `usa*.c` são programas de teste que fazem `#include` da implementação e chamam suas funções. Um jeito de baixá-los para cá, organizados por aula:

```bash
BASE=https://www.each.usp.br/digiampietri/ed
mkdir -p aula03 && curl -o aula03/listaSequencial.c $BASE/aula03/listaSequencial.c
```

## Programa da SIN5013 (2º semestre de 2026)

Aulas online, provas presenciais. Exige 75% de frequência.

**Parte 1 – Análise de algoritmos**
- Análise de algoritmos e complexidade assintótica (10 a 17/ago)
- Recursão, equações de recorrência e divisão e conquista (24/ago)
- Ordenação: Quicksort, Mergesort, Heapsort e ordenação em tempo linear (31/ago a 14/set)

**Parte 2 – Estruturas de dados**
- Estruturas lineares: listas, filas e pilhas (05/out)
- Árvores binárias e árvores de busca binária (19/out)
- Árvores AVL (26/out)
- Grafos: conceitos, busca em largura, busca em profundidade, árvore geradora mínima e caminhos mínimos (09 a 23/nov)

**Avaliação**
- Prova 1: 28/set
- Prova 2: 30/nov
- Prova substitutiva: 07/dez (para quem faltar a uma das provas)

Datas conferidas na página da disciplina em 05/10/2026. Confira lá antes de cada prova.

## Resumo da apostila ACH2023

A apostila usa duas convenções em todos os códigos:

```c
#define MAX 50            // tamanho máximo do vetor estático
typedef int TIPOCHAVE;    // tipo da chave de busca
```

**Listas lineares**
- **Lista sequencial**: vetor `A[MAX]` com contador `nroElem`. Acesso por índice em O(1) e busca binária em O(log n) se a lista estiver ordenada. Inserir ou excluir no início desloca todos os elementos, O(n). Operações: inicializar, exibir, tamanho, busca sequencial, busca com sentinela, busca binária, inserção ordenada e exclusão.
- **Lista ligada estática**: o vetor guarda duas listas encadeadas por índices, a de elementos (`inicio`) e a de posições livres (`dispo`). O valor `-1` marca o fim da lista.
- **Lista ligada dinâmica**: nós alocados com `malloc` e ligados por ponteiros.
- **Técnicas especiais**: nó-cabeça, sentinela, lista circular e encadeamento duplo.
- **Filas** (FIFO): implementações dinâmica e estática.
- **Deques** (fila de duas pontas): implementação dinâmica.
- **Pilhas** (LIFO): implementações dinâmica e estática, duas pilhas em um vetor, *NP* pilhas em um vetor, e aplicações.
- **Matrizes esparsas**: representação por linhas e por listas cruzadas.
- **Listas generalizadas**.

**Listas não lineares**
- Árvores binárias, árvores de busca binária e árvores AVL.

## Próximos passos sugeridos

1. Reproduzir as aulas 02 a 04 (`struct`, lista sequencial) em arquivos próprios, uma pasta por aula.
2. A partir da aula 06, compilar com `-fsanitize=address` para pegar vazamentos e acessos inválidos de memória.
3. Para cada estrutura, anotar a complexidade de inserção, exclusão e busca. É isso que a Parte 1 da disciplina cobra.

## Sugestão de `.gitignore`

```gitignore
# Executáveis e símbolos de depuração gerados pelo clang
*.dSYM/
*.o
*.out
hello
helloworld
idade
imprimir
inserir_idade
atribuicao_constancia
achemenormaior
main

# Ambiente
.venv/
.DS_Store
```

Outra opção é compilar sempre para uma pasta `bin/` e ignorar só ela.
