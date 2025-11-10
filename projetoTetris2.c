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