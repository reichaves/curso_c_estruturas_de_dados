/*
 * EstruturaSimples2.c - Aula 02: a mesma struct, agora alocada dinamicamente
 *
 * Código original: Prof. Luciano Digiampietri (each.usp.br/digiampietri/ed).
 * Comentários didáticos acrescentados para quem está começando em C.
 *
 * Leia antes o EstruturaSimples.c. Este programa faz a mesma coisa, mas em vez
 * de declarar a struct diretamente, guarda apenas um PONTEIRO para ela e pede
 * a memória ao sistema durante a execução, com malloc.
 *
 * O que este programa ensina:
 *   - o que é um ponteiro (uma variável que guarda um endereço);
 *   - por que um ponteiro não inicializado é perigoso;
 *   - como reservar memória em tempo de execução com malloc e sizeof;
 *   - como acessar os campos de uma struct através de um ponteiro (->);
 *   - a diferença entre a memória da pilha (variáveis locais) e a do heap
 *     (memória alocada com malloc);
 *   - como devolver a memória ao sistema com free.
 *
 * Este é o mecanismo usado nas estruturas DINÂMICAS das próximas aulas
 * (listas ligadas, pilhas, filas), em que cada elemento é criado com malloc.
 *
 * Os printf com o prefixo ">>" foram acrescentados para explicar na tela, passo
 * a passo, o que o programa está fazendo. Os printf originais do professor
 * continuam lá, sem o prefixo. As mensagens não têm acentos de propósito: o
 * terminal do Windows nem sempre mostra acentos corretamente.
 *
 * Como compilar e executar (Windows, PowerShell, a partir da pasta do projeto):
 *   gcc -std=c17 aula02\EstruturaSimples2.c -o aula02\EstruturaSimples2.exe
 *   .\aula02\EstruturaSimples2.exe
 * O compilador pode avisar que pessoa1 é usada sem ser inicializada. O aviso é
 * correto e o erro é proposital (veja a explicação na linha do primeiro printf).
 */

// stdio.h: biblioteca de entrada e saída, de onde vem o printf.
#include <stdio.h>
// stdlib.h: biblioteca de utilidades gerais ("standard library"). É dela que
// vêm malloc (reservar memória) e free (devolver memória).
#include <stdlib.h>
// Constante criada pelo pré-processador: toda ocorrência de alturaMaxima vira
// 225 antes da compilação. Detalhes no EstruturaSimples.c.
#define alturaMaxima 225

// Mesmo tipo do programa anterior: uma struct com dois campos inteiros,
// apelidada de PesoAltura pelo typedef. Ocupa 8 bytes (2 ints de 4 bytes).
typedef struct
{
  int peso;   // peso em quilogramas
  int altura; // altura em centimetros
} PesoAltura;

int main() {
  // Inteiro declarado só para compararmos endereços no final.
  int x;

  // PONTEIRO
  // O asterisco na declaração muda tudo: pessoa1 NÃO é uma struct, é um
  // PONTEIRO PARA uma struct PesoAltura. Um ponteiro é uma variável que guarda
  // um endereço de memória, ou seja, "onde" algo está, e não o próprio dado.
  //
  // Analogia: a struct é uma casa; o ponteiro é um papel com o endereço da
  // casa escrito. Declarar o ponteiro cria só o papel. A casa ainda não existe.
  //
  // Nesta linha o ponteiro ocupa 8 bytes (em sistemas de 64 bits) e nenhuma
  // struct foi criada ainda.
  PesoAltura* pessoa1;

  printf(">> PASSO 1: declaramos 'PesoAltura* pessoa1', um PONTEIRO.\n");
  printf(">>   Um ponteiro guarda um endereco de memoria, nao o dado em si.\n");
  printf(">>   Tamanho do ponteiro: %zu bytes. Tamanho da struct: %zu bytes.\n",
         sizeof(pessoa1), sizeof(PesoAltura));
  printf(">>   Ainda NAO existe nenhuma struct: so o ponteiro foi criado.\n\n");

  // PONTEIRO NÃO INICIALIZADO (erro proposital, para fins didáticos)
  // pessoa1 ainda não recebeu nenhum valor, então guarda lixo: um endereço
  // qualquer, que pode apontar para lugar nenhum. Ler esse valor é
  // comportamento indefinido em C: cada compilador e cada execução pode dar um
  // resultado diferente. O professor obteve (nil), que significa endereço nulo,
  // mas isso foi coincidência, não garantia.
  //
  // Exemplo de execução no Windows (gcc):
  //   Valor inicial do endereco: 0000006036FFFDE0
  // Repare que esse número é muito parecido com os endereços de x e de
  // pessoa1 impressos no final (0000006036FFFDBC e 0000006036FFFDB0). Ou seja,
  // o "lixo" era um endereço da PILHA que sobrou de algum uso anterior daquela
  // posição de memória. Não aponta para nenhuma PesoAltura.
  //
  // Lição: sempre inicialize ponteiros, nem que seja com NULL
  // (PesoAltura* pessoa1 = NULL;), e nunca acesse campos por um ponteiro que
  // não aponta para uma memória válida.
  printf(">> PASSO 2: imprimindo o valor do ponteiro ANTES de inicializa-lo.\n");
  printf(">>   O valor abaixo e LIXO: o que estava naquela posicao de memoria.\n");
  printf(">>   Pode ser (nil), 0000000000000000 ou um numero qualquer.\n");
  printf("Valor inicial do endereco: %p\n\n", pessoa1);

  // ALOCAÇÃO DINÂMICA COM malloc
  // Agora a "casa" é construída. Lendo de dentro para fora:
  //
  //   sizeof(PesoAltura)
  //     Operador que devolve quantos bytes um tipo ocupa (aqui, 8). Usar
  //     sizeof em vez de escrever 8 deixa o código correto em qualquer
  //     computador e continua certo se a struct ganhar novos campos.
  //
  //   malloc(8)
  //     "memory allocation". Pede ao sistema um bloco de 8 bytes livres numa
  //     região da memória chamada HEAP e devolve o endereço do início do
  //     bloco. Se não houver memória disponível, devolve NULL. Programas
  //     reais devem testar isso: if (pessoa1 == NULL) { ... }.
  //
  //   (PesoAltura*)
  //     CONVERSÃO DE TIPO (cast). malloc devolve um void*, um "endereço
  //     genérico" que não diz o que existe lá. O cast diz: "trate esse
  //     endereço como o de uma PesoAltura". Em C o cast é opcional (a
  //     conversão de void* é automática), mas é comum vê-lo; em C++ ele é
  //     obrigatório.
  //
  //   pessoa1 = ...
  //     O endereço devolvido é guardado no ponteiro. Agora o "papel" tem o
  //     endereço de uma casa que existe de verdade.
  pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));

  printf(">> PASSO 3: malloc(sizeof(PesoAltura)) reservou %zu bytes no HEAP.\n",
         sizeof(PesoAltura));
  printf(">>   Agora pessoa1 aponta para uma struct de verdade, no endereco %p.\n",
         pessoa1);
  printf(">>   Mas malloc NAO limpa a memoria: os campos ainda contem lixo.\n");
  printf(">>   Veja os valores dos campos antes de atribuirmos qualquer coisa:\n");

  // OPERADOR SETA (->)
  // Quando temos um PONTEIRO para struct, acessamos os campos com -> em vez
  // de ponto. pessoa1->peso significa "o campo peso da struct para a qual
  // pessoa1 aponta". É uma forma abreviada de escrever (*pessoa1).peso, onde
  // *pessoa1 quer dizer "a struct que está no endereço guardado em pessoa1".
  //
  // Regra prática:
  //   variável struct  -> use ponto:  pessoa.peso
  //   ponteiro p/ struct -> use seta: pessoa->peso
  //
  // MEMÓRIA NÃO INICIALIZADA: malloc reserva a memória mas NÃO limpa o que
  // havia nela. Os campos ainda não receberam valor, então o conteúdo é
  // indeterminado. O professor viu "Peso: 0, Altura 0" porque, no Linux, o
  // sistema costuma entregar memória zerada no início do programa.
  //
  // No Windows o resultado foi outro:
  //   Peso: 1110491616, Altura 562.
  // Esses números não são peso nem altura: são restos de dados que o próprio
  // gerenciador de memória do Windows deixou naquele bloco. Curiosidade: em
  // hexadecimal, 562 = 0x232 e 1110491616 = 0x4230C1E0. Juntando os dois
  // (altura são os 4 bytes de cima, peso os 4 de baixo) obtemos
  // 0x000002324230C1E0, um endereço da mesma região do HEAP (compare com o
  // pessoa1 = 0000023242309CB0 impresso no final). Ou seja, o lixo era um
  // PONTEIRO que o gerenciador de memória usava para controlar blocos livres.
  // Por isso nunca se deve usar um campo antes de atribuir um valor a ele.
  // Se precisar de memória zerada, use calloc(1, sizeof(PesoAltura)).
  printf("Peso: %i, Altura %i.\n\n", pessoa1->peso, pessoa1->altura);

  // Agora sim os campos recebem valores, através do ponteiro.
  pessoa1->peso = 80;
  pessoa1->altura = 185;

  printf(">> PASSO 4: atribuimos valores aos campos usando o operador seta:\n");
  printf(">>   pessoa1->peso = 80;   pessoa1->altura = 185;\n");
  printf(">>   (pessoa1->peso e o mesmo que (*pessoa1).peso)\n");

  // Mesma impressão e mesmo teste do EstruturaSimples.c, trocando . por ->.
  printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);
  if (pessoa1->altura>alturaMaxima) {
    printf("Altura acima da maxima.\n");
  }
  else printf("Altura abaixo da maxima.\n");
  printf(">>   Como %i <= %i (alturaMaxima), caiu no 'else'.\n\n",
         pessoa1->altura, alturaMaxima);

  // TRÊS ENDEREÇOS DIFERENTES
  //   &x        -> endereço da variável x.
  //   &pessoa1  -> endereço da VARIÁVEL PONTEIRO (onde o "papel" está
  //                guardado). Não confunda com o endereço da struct.
  //   pessoa1   -> o VALOR do ponteiro, isto é, o endereço da struct criada
  //                por malloc (onde a "casa" está).
  //
  // Na saída do professor (Linux, final do arquivo):
  //   &x       = 0x7ffde9c33f74  \  números grandes e vizinhos: x e pessoa1
  //   &pessoa1 = 0x7ffde9c33f78  /  são variáveis locais, guardadas na PILHA
  //   pessoa1  = 0x1f50010          número bem diferente: a struct está no
  //                                 HEAP, a região usada pelo malloc.
  //
  // Numa execução no Windows (gcc):
  //   &x       = 0000006036FFFDBC  \  de novo vizinhos (diferença de 12
  //   &pessoa1 = 0000006036FFFDB0  /  bytes): ambos na PILHA
  //   pessoa1  = 0000023242309CB0     região bem diferente: o HEAP
  // Diferenças em relação ao Linux:
  //   - o Windows imprime %p com 16 dígitos hexadecimais e sem o "0x";
  //   - aqui x ficou num endereço MAIOR que pessoa1; no Linux foi o contrário.
  //     A ordem das variáveis locais na pilha é decisão do compilador, e o
  //     programa não deve depender dela.
  //
  // PILHA x HEAP
  //   Pilha (stack): onde ficam as variáveis locais de uma função. São criadas
  //   quando a função começa e destruídas automaticamente quando ela termina.
  //   Heap: memória pedida explicitamente com malloc. Continua existindo até
  //   o programa chamar free, mesmo depois que a função que a criou terminou.
  //   É isso que permite criar elementos de uma lista ligada dentro de uma
  //   função e usá-los depois.
  printf(">> PASSO 5: comparando tres enderecos (na ordem: &x, &pessoa1, pessoa1).\n");
  printf("Enderecos: %p %p %p\n", &x, &pessoa1, pessoa1);
  printf(">>   &x       = %p -> endereco da variavel x (PILHA)\n", &x);
  printf(">>   &pessoa1 = %p -> endereco da variavel ponteiro (PILHA)\n", &pessoa1);
  printf(">>   pessoa1  = %p -> valor do ponteiro = endereco da struct (HEAP)\n", pessoa1);
  printf(">>   Os dois primeiros sao vizinhos (variaveis locais, na pilha).\n");
  printf(">>   O terceiro esta em outra regiao: a memoria criada por malloc.\n\n");

  // LIBERANDO A MEMÓRIA
  // O programa original não chamava free(pessoa1). Toda memória obtida com
  // malloc deve ser devolvida com free quando não for mais usada; caso
  // contrário ocorre um VAZAMENTO DE MEMÓRIA (memory leak). Num programa tão
  // curto não haveria problema prático, porque o sistema operacional recupera
  // tudo quando o programa termina, mas em programas longos a memória se
  // esgota. Por isso a linha abaixo foi acrescentada.
  //
  // Depois do free, pessoa1 continua guardando o mesmo endereço, mas aquela
  // memória não pertence mais ao programa (ponteiro "pendurado", dangling
  // pointer). Atribuir NULL evita que ela seja usada por engano.
  free(pessoa1);
  pessoa1 = NULL;
  printf(">> PASSO 6: free(pessoa1) devolveu os %zu bytes ao sistema.\n",
         sizeof(PesoAltura));
  printf(">>   Em seguida, pessoa1 = NULL para nao usarmos memoria liberada.\n");
  printf(">>   Valor final do ponteiro: %p\n", pessoa1);
  return 0;
}

/*
Saída obtida pelo professor, antes dos printf explicativos (os endereços e a
primeira linha podem ser diferentes na sua máquina, pelos motivos explicados
acima):

Valor inicial do endereço: (nil)
Peso: 0, Altura 0. Peso: 80, Altura 185. Altura abaixo da maxima.
Endereços: 0x7ffde9c33f74 0x7ffde9c33f78 0x1f50010

Saída da versão original numa execução no Windows (gcc):

Valor inicial do endereco: 0000006036FFFDE0
Peso: 1110491616, Altura 562. Peso: 80, Altura 185. Altura abaixo da maxima.
Enderecos: 0000006036FFFDBC 0000006036FFFDB0 0000023242309CB0
*/
