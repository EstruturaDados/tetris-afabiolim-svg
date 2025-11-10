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


// Função Principal 
int main() {
    srand(time(NULL));

    for (int i = 0; i < TAM_FILA; i++)
        enqueue(gerarPeca());

    int op;
    do {
        printf("\n=== TETRIS STACK / NIVEL AVENTUREIRO ===\n");
        printf("1 - Jogar peca (remove da fila e gera nova)\n");
        printf("2 - Reservar peca (envia para pilha)\n");
        printf("3 - Usar peca reservada (tira da pilha e coloca na fila)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);


         if (op == 1) {
            Peca jogada = dequeue();
            if (jogada.id != 0) {
                printf("Jogou peca id=%d tipo=%c\n", jogada.id, jogada.tipo);
                enqueue(gerarPeca());
            }
        } else if (op == 2) {
            if (!filaVazia()) {
                Peca reservada = dequeue();
                push(reservada);
                printf("Reservou peca id=%d tipo=%c\n", reservada.id, reservada.tipo);
                enqueue(gerarPeca());
            }
        } else if (op == 3) {
            Peca usada = pop();
            if (usada.id != 0) {
                enqueue(usada);
                printf("Usou peca reservada id=%d tipo=%c\n", usada.id, usada.tipo);
            }
        }

        mostrarFila();
        mostrarPilha();

    } while (op != 0);

    printf("Encerrando...\n");
    return 0;
}