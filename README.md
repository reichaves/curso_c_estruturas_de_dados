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
- **`.vscode/tasks.json`**: tarefa de build padrão do VS Code. Compila o arquivo aberto com `clang -g` e gera o executável `.out` na mesma pasta (ex.: `aula01/HelloWorld.out`), que o `.gitignore` já ignora.

### Códigos das aulas

As pastas `aula01/` a `aula14/` têm todos os códigos do professor, baixados de [digiampietri/ed](https://www.each.usp.br/digiampietri/ed/). O roteiro completo está mais abaixo.

Os executáveis (`hello`, `idade`, ...) e as pastas `*.dSYM/` (símbolos de depuração do macOS) saem da compilação e ficam fora do Git pelo `.gitignore` (veja o fim deste arquivo).

## Como compilar e executar

As instruções abaixo são para macOS (`clang`). No Windows, veja [No Windows (gcc)](#no-windows-gcc).

### Pré-requisito

No macOS, o compilador C é o `clang`, que vem com as ferramentas de linha de comando do Xcode. Se `clang --version` responder "command not found", instale com:

```bash
xcode-select --install
```

### O passo a passo, com o Hello World da aula 01

O arquivo `aula01/HelloWorld.c` só imprime `Hello World!`. Rode estes comandos no terminal, a partir da pasta do projeto:

```bash
cd /Users/abrajimac/Documents/Code/curso_c_estruturas_de_dados

# compilar
clang aula01/HelloWorld.c -o aula01/HelloWorld.out

# executar
./aula01/HelloWorld.out
```

A saída esperada é:

```
Hello World!
```

Para que serve cada parte:

- **`clang`**: o compilador C do macOS. Ele transforma o arquivo `.c` em um programa executável.
- **`-o aula01/HelloWorld.out`**: define o nome do executável. Sem essa opção, o clang cria um `a.out` na pasta onde você está.
- **`./`**: indica "nesta pasta". É obrigatório quando o executável está na pasta atual (`./main.out`). Sem ele, o terminal procura o programa nas pastas do sistema e responde `command not found`. Para caminhos com subpasta (`aula01/HelloWorld.out`) a barra já basta, mas usar `./` sempre é um bom hábito.
- **Extensão `.out`**: o `.gitignore` ignora `*.out`, então o executável não aparece no `git status`.

### A regra geral

Para qualquer arquivo com função `main`:

```bash
clang caminho/arquivo.c -o caminho/arquivo.out
./caminho/arquivo.out
```

O que muda é **qual arquivo** compilar. Nas aulas há três tipos:

| Tipo | Arquivos | Como compilar |
|---|---|---|
| Programa completo (tem `main`) | `aula01/HelloWorld.c`, os três de `aula02/`, `aula03/listaSequencial.c`, `aula04/listaSequencialOrdenada.c`, `aula06/exemploDoisRetornos.c`, `aula14/matrizSimples.c` e os exercícios da raiz (`hello.c`, `idade.c`, ...) | Compile o próprio arquivo |
| Implementação da estrutura (sem `main`) | `listaLigada.c`, `listaLigadaD.c`, `listaLigadaCabCirc.c`, `pilhaEstatica.c`, `pilhaDinamica.c`, `dequeDinamico.c`, `filaEstatica.c`, `filaDinamica.c`, `duasPilhasEstaticas.c`, `esparsasArranjoDeListas.c` | **Não compile direto.** Esses arquivos são incluídos pelo `usa*.c` da mesma pasta |
| Programa de teste (`usa*.c`) | Aulas 05 a 14 | Compile o `usa*.c`. Ele faz `#include` da implementação, então um comando só basta |

Exemplos:

```bash
# aula 03: programa completo
clang aula03/listaSequencial.c -o aula03/listaSequencial.out
./aula03/listaSequencial.out

# aula 08: compile o usa*.c, não o pilhaEstatica.c
clang aula08/usaPilhaEstatica.c -o aula08/usaPilhaEstatica.out
./aula08/usaPilhaEstatica.out

# exercício C++ da raiz: use clang++ em vez de clang
clang++ main.cpp -o main.out
./main.out
```

### Usando os programas interativos (`usa*.c`)

Os programas `usa*.c` mostram uma lista de comandos e esperam você digitar, um por linha. Por exemplo, na pilha da aula 08:

```
i 3      insere a chave 3
i 7      insere a chave 7
p        imprime a pilha  ->  Pilha: " 7 3 "
e        exclui o topo
l        mostra o número de elementos e o tamanho em bytes
h        mostra a ajuda
q        sai
```

Cada programa tem seus próprios comandos, e o `h` mostra a lista. Para testar sem digitar, mande os comandos por um pipe:

```bash
printf 'i 3\ni 7\np\nq\n' | ./aula08/usaPilhaEstatica.out
```

A matriz esparsa (`aula14/usaEsparsasArranjoDeListas.c`) funciona de outro jeito. Ela lê duas matrizes: primeiro `linhas colunas`, depois um `linha coluna valor` por linha, e termina cada matriz com uma linha começando em `-1`.

```bash
printf '3 4\n0 1 2.5\n1 3 4\n-1 -1 0\n3 4\n0 1 1.5\n2 2 7\n-1 -1 0\n' | ./aula14/usaEsparsasArranjoDeListas.out
```

Esse programa termina com erro por causa de um bug no código original (veja "Pontos de atenção" mais abaixo).

### Pelo VS Code

Abra o arquivo e aperte `⇧⌘B` (**Terminal → Executar Tarefa de Build**). A tarefa em `.vscode/tasks.json` compila o arquivo aberto com `clang -g` e gera `<nome>.out` na mesma pasta. Depois execute no terminal, por exemplo `./aula01/HelloWorld.out`.

Nas aulas 05 a 14, deixe aberto o `usa*.c` antes de apertar `⇧⌘B`.

### Opções úteis para estudar

```bash
# mostra mais avisos do compilador
clang -Wall -Wextra -g aula01/HelloWorld.c -o aula01/HelloWorld.out

# detecta erros de memória em tempo de execução (útil a partir das listas dinâmicas, aula 06)
clang -fsanitize=address -g aula09/usaPilhaDinamica.c -o aula09/usaPilhaDinamica.out
```

O `-g` inclui informações de depuração. No macOS ele cria uma pasta `<nome>.out.dSYM/` ao lado do executável, que o `.gitignore` também ignora.

### Erros comuns

| Mensagem | Causa | O que fazer |
|---|---|---|
| `clang: command not found` | Ferramentas do Xcode não instaladas | `xcode-select --install` |
| `Undefined symbols for architecture ...` / `linker command failed` | Você compilou um arquivo de implementação, que não tem `main` | Compile o `usa*.c` da mesma pasta |
| `fatal error: 'malloc.h' file not found` | Cabeçalho que só existe no Linux | Troque por `#include <stdlib.h>`. Os arquivos deste repositório já estão corrigidos |
| `warning: '/*' within block comment` | Comentário fechado com `* /` em vez de `*/` no código original | É só um aviso; o programa compila normalmente |
| `zsh: command not found: main.out` | Faltou o `./` antes de um executável da pasta atual | Rode `./main.out` |
| `zsh: no such file or directory: ./aula03/...` | Caminho errado ou o arquivo ainda não foi compilado | Confira o nome com `ls aula03` e compile antes de executar |

### Limpar os executáveis

```bash
find . -name "*.out" -not -path "./.venv/*" -delete
find . -name "*.dSYM" -type d -not -path "./.venv/*" -exec rm -rf {} +
```

### No Windows (gcc)

No Windows, o compilador usado é o `gcc` (MinGW-w64, instalado por exemplo pelo [MSYS2](https://www.msys2.org/)). Confira se ele está no PATH com `gcc --version`.

Rode os comandos no PowerShell, a partir da pasta do projeto:

```powershell
cd E:\Code\curso_c_estruturas_de_dados

# compilar
gcc -std=c17 aula01\HelloWorld.c -o aula01\HelloWorld.exe

# executar
.\aula01\HelloWorld.exe
```

Para que serve cada parte:

- **`-std=c17`**: as versões recentes do gcc usam C23 por padrão. Em C23, `bool` é palavra reservada, e os arquivos das aulas que declaram `typedef int bool;` (como `aula08/pilhaEstatica.c`) não compilam. Com `-std=c17` compilam normalmente. Use sempre.
- **`-o ...\arquivo.exe`**: nome do executável. Sem essa opção, o gcc cria um `a.exe` na pasta atual.
- **`.\`**: o PowerShell só executa programas da pasta atual com esse prefixo. No Prompt de Comando (cmd) ele não é necessário: `aula01\HelloWorld.exe`.

A regra geral é a mesma do macOS: compile o arquivo que tem `main`. Nas aulas 05 a 14, compile o `usa*.c`, que já faz `#include` da implementação (veja a tabela em [A regra geral](#a-regra-geral)).

```powershell
# aula 08: compile o usa*.c, não o pilhaEstatica.c
gcc -std=c17 aula08\usaPilhaEstatica.c -o aula08\usaPilhaEstatica.exe
.\aula08\usaPilhaEstatica.exe

# exercício C++ da raiz: use g++ em vez de gcc
g++ main.cpp -o main.exe
.\main.exe

# mais avisos e informações de depuração
gcc -std=c17 -Wall -Wextra -g aula01\HelloWorld.c -o aula01\HelloWorld.exe
```

Para testar um programa interativo sem digitar, mande os comandos pelo pipe do PowerShell. O `` `n `` é a quebra de linha:

```powershell
"i 3`ni 7`np`nq" | .\aula08\usaPilhaEstatica.exe
```

O `-fsanitize=address` não funciona com o gcc do MinGW. Para usá-lo no Windows, use o `clang` do ambiente CLANG64 do MSYS2 ou o WSL.

O `.gitignore` atual não ignora arquivos `.exe`. Para não mandar executáveis ao GitHub por engano, apague-os antes do commit:

```powershell
Get-ChildItem -Recurse -Filter *.exe | Where-Object { $_.FullName -notmatch '\\\.venv\\' } | Remove-Item
```

O filtro deixa de fora a pasta `.venv\`, que no Windows tem executáveis do Python.

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

Os arquivos `usa*.c` são programas de teste que fazem `#include` da implementação. Veja em [Como compilar e executar](#como-compilar-e-executar) qual arquivo compilar em cada aula.

As 14 aulas já estão baixadas nas pastas `aula01/` a `aula14/`. Se o professor publicar uma versão nova de algum arquivo, dá para baixar de novo assim:

```bash
BASE=https://www.each.usp.br/digiampietri/ed
curl -o aula09/pilhaDinamica.c $BASE/aula09/pilhaDinamica.c
```

### Ajustes feitos nos códigos baixados

- Arquivos convertidos de ISO-8859-1 para UTF-8 e de CRLF (Windows) para LF, para os acentos aparecerem certos no VS Code.
- `#include <malloc.h>` trocado por `#include <stdlib.h>` em `aula02/testaEstrutura.c`, `aula02/EstruturaSimples2.c`, `aula06/listaLigadaD.c`, `aula07/listaLigadaCabCirc.c`, `aula08/pilhaEstatica.c`, `aula09/pilhaDinamica.c`, `aula10/dequeDinamico.c`, `aula12/filaDinamica.c`, `aula14/esparsasArranjoDeListas.c` e `aula14/usaEsparsasArranjoDeListas.c`. O `malloc.h` só existe no Linux; o `stdlib.h` é o cabeçalho padrão e compila no macOS.

Fora isso, o código está como o professor publicou. Todos os programas foram compilados com `clang -Wall` e testados no macOS; das aulas 09 a 14 também com `-fsanitize=address`.

### Pontos de atenção (bons exercícios)

| Arquivo | O que acontece | Por quê |
|---|---|---|
| `aula02/EstruturaSimples2.c` | Aviso de ponteiro não inicializado | Proposital: imprime `pessoa1` antes do `malloc` para mostrar o lixo de memória |
| `aula04/listaSequencialOrdenada.c` | `inserirElemListaOrdSemDup` insere na posição errada quando a chave é menor que a primeira (inserindo 5, 9, 3, 1 resulta em `5 1 3 9`) | O laço usa `while(pos>0 ...)`; deveria ser `pos>=0`. A `main` não chama essa função |
| `aula07/listaLigadaCabCirc.c` | Com a lista vazia, o comando `0` mostra `Primeiro elemento 1 ...` (lixo) | `retornarPrimeiro` devolve o nó-cabeça em vez de `NULL` quando a lista está vazia |
| `aula14/esparsasArranjoDeListas.c` | O programa aborta no fim (`exit 134` no macOS; o AddressSanitizer acusa *heap-use-after-free*) | Em `reinicializarMatriz`, o laço faz `free(atual)` depois de avançar, quando deveria ser `free(apagar)`: libera o nó seguinte e lê memória já liberada. A soma das matrizes sai certa antes do erro |
| `aula14/usaEsparsasArranjoDeListas.c` | Imprime `Valor inserido (-1,-1,...)` ao final da leitura | O `if (i>=0)` em `LeMatriz` não tem chaves, então o `printf` roda também para a linha que encerra a entrada |
| `aula12/filaDinamica.c` | `buscaSeqSent1` compara `pos` com o ponteiro `sentinela` depois do `free` | Funciona na prática, mas usar o valor de um ponteiro já liberado é comportamento indefinido em C. `buscaSeqSent2`, com a sentinela na pilha de execução, evita isso |
| `aula07/listaLigadaCabCirc.c`, `aula08/pilhaEstatica.c`, `aula09/pilhaDinamica.c`, `aula13/duasPilhasEstaticas.c` | Avisos `'/*' within block comment` | Comentários fechados com `* /` em vez de `*/`; inofensivo |

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
2. A partir da aula 06, compilar com `-fsanitize=address` para pegar acessos inválidos de memória. Foi assim que apareceu o bug da aula 14.
3. Para cada estrutura, anotar a complexidade de inserção, exclusão e busca. É isso que a Parte 1 da disciplina cobra.

## `.gitignore`

O repositório ignora:

- executáveis gerados pelo `clang` (`*.out`, `*.o` e os nomes dos exercícios da raiz, como `hello` e `idade`);
- pastas `*.dSYM/` com símbolos de depuração do macOS;
- `.venv/` e `.DS_Store`.

Ao compilar os códigos das aulas, use `-o nome.out` para o executável não aparecer no `git status`.
