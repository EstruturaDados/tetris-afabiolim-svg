#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char tipo;
} Peca;

#define TAM_FILA 5
#define TAM_PILHA 3
#define TAM_HISTORICO 10


Peca fila[TAM_FILA];
int frente = 0, tamanhoFila = 0;

Peca pilha[TAM_PILHA];
int topo = -1;

Peca historico[TAM_HISTORICO];
int tamHist = 0;

int proximoId = 1;

int filaCheia() { return tamanhoFila == TAM_FILA; }
int filaVazia() { return tamanhoFila == 0; }
int pilhaCheia() { return topo == TAM_PILHA - 1; }
int pilhaVazia() { return topo == -1; }

Peca gerarPeca() {
    char tipos[] = {'I','O','T','L','S','Z','J'};
    int idx = rand() % 7; // Escolhe um tipo aleatório
    Peca p = { proximoId++, tipos[idx] };
    return p;
}
 
// peça no fim da fila
void enqueue(Peca p) {
    if (filaCheia()) return; // Se estiver cheia, não faz nada
    int pos = (frente + tamanhoFila) % TAM_FILA; // Calcula posição circular
    fila[pos] = p;
    tamanhoFila++;
}
int main() {

    return 0;
}