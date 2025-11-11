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
    int pos = (frente + tamanhoFila) % TAM_FILA; 
    fila[pos] = p;
    tamanhoFila++;


// Remove a peça da frente da fila
Peca dequeue() {
    Peca vazia = {0, '-'}; // Peça vazia
    if (filaVazia()) return vazia;

    Peca r = fila[frente]; // peça da frente
    frente = (frente + 1) % TAM_FILA; 
    tamanhoFila--;
    return r;
}

void push(Peca p) {
    if (!pilhaCheia()) pilha[++topo] = p;
}

// peça do topo
Peca pop() {
    Peca vazia = {0,'-'};
    if (pilhaVazia()) return vazia;
    return pilha[topo--];
}


// Mostra a fila
void mostrarFila() {
    printf("\nFILA:\n");
    if (filaVazia()) printf("[vazia]\n");
    else for (int i = 0; i < tamanhoFila; i++) {
        int idx = (frente + i) % TAM_FILA; 
        printf("id=%d tipo=%c\n", fila[idx].id, fila[idx].tipo);
    }
}


// Mostra pilha
void mostrarPilha() {
    printf("\nPILHA:\n");
    if (pilhaVazia()) printf("[vazia]\n");
    else for (int i = topo; i >= 0; i--)
        printf("id=%d tipo=%c\n", pilha[i].id, pilha[i].tipo);
}




}
int main() {

    return 0;
}