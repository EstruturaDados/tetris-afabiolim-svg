#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desafio Tetris Stack
// Estrutura que representa uma peça
typedef struct {
    int id;
    char tipo;
} Peca;

#define TAM_FILA 5
#define TAM_PILHA 3

// Variáveis Tamanho (fila e pilha)
Peca fila[TAM_FILA];
int frente = 0, tamanhoFila = 0;
Peca pilha[TAM_PILHA];
int topo = -1;
int proximoId = 1;