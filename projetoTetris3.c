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




int main() {

    return 0;
}