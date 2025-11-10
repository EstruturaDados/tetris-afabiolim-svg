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

//gerar Pecas
Peca gerarPeca() {
    char tipos[] = {'I','O','T','L','S','Z','J'};
    int idx = rand() % 7;
    Peca p;
    p.id = proximoId++;
    p.tipo = tipos[idx];
    return p;
}

// Operações da Fila 
void enqueue(Peca p) {
    if (filaCheia()) return;
    int pos = (frente + tamanhoFila) % TAM_FILA;
    fila[pos] = p;
    tamanhoFila++;
}

Peca dequeue() {
    Peca vazia = {0, '-'};
    if (filaVazia()) return vazia;
    Peca removida = fila[frente];
    frente = (frente + 1) % TAM_FILA;
    tamanhoFila--;
    return removida;
}

void mostrarFila() {
    printf("\nFILA (frente -> tras):\n");
    if (filaVazia()) { printf("[vazia]\n"); return; }
    for (int i = 0; i < tamanhoFila; i++) {
        int idx = (frente + i) % TAM_FILA;
        printf("  id=%d tipo=%c\n", fila[idx].id, fila[idx].tipo);
    }
}


// Operações da Pilha 
void push(Peca p) {
    if (pilhaCheia()) {
        printf("Reserva cheia! Não é possível guardar mais peças.\n");
        return;
    }
    pilha[++topo] = p;
}

Peca pop() {
    Peca vazia = {0, '-'};
    if (pilhaVazia()) {
        printf("Reserva vazia! Nada para usar.\n");
        return vazia;
    }
    return pilha[topo--];
}

void mostrarPilha() {
    printf("\nPILHA (topo -> base):\n");
    if (pilhaVazia()) { printf("[vazia]\n"); return; }
    for (int i = topo; i >= 0; i--) {
        printf("  id=%d tipo=%c\n", pilha[i].id, pilha[i].tipo);
    }
}