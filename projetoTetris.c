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

// Variáveis da fila
Peca fila[TAM_FILA];
int frente = 0;
int tamanho = 0;
int proximoId = 1;
