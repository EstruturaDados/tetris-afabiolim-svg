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

// Funções auxiliares
int filaVazia() { return tamanhoFila == 0; }
int filaCheia() { return tamanhoFila == TAM_FILA; }
int pilhaVazia() { return topo == -1; }
int pilhaCheia() { return topo == TAM_PILHA - 1; }

//gerarPeca
Peca gerarPeca() {
    char tipos[] = {'I','O','T','L','S','Z','J'};
    int idx = rand() % 7;
    Peca p;
    p.id = proximoId++;
    p.tipo = tipos[idx];
    return p;
}