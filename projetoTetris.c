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

// Funçao auxiliares
int isFull() { return tamanho == TAM_FILA; }
int isEmpty() { return tamanho == 0; }


// Peça aleatória
Peca gerarPeca() {
    char tipos[] = {'I','O','T','L','S','Z','J'};
    int indice = rand() % 7;
    Peca p;
    p.id = proximoId++;
    p.tipo = tipos[indice];
    return p;
}

// funçao Nova peça
void enqueue(Peca p) {
    if (isFull()) {
        printf("Fila cheia! Nao e possivel adicionar nova peca.\n");
        return;
    }
    int pos = (frente + tamanho) % TAM_FILA;
    fila[pos] = p;
    tamanho++;
}

// Remove peça da frente
Peca dequeue() {
    Peca vazia = {0, '-'};
    if (isEmpty()) {
        printf("Fila vazia! Nao ha pecas para jogar.\n");
        return vazia;
    }
    Peca removida = fila[frente];
    frente = (frente + 1) % TAM_FILA;
    tamanho--;
    return removida;
}

// Estado atual da fila
void mostrarFila() {
    printf("\n---FILA DE PECAS ---\n");
    if (isEmpty()) {
        printf("[vazia]\n");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        int idx = (frente + i) % TAM_FILA;
        printf("[%d] id=%d tipo=%c\n", i+1, fila[idx].id, fila[idx].tipo);
    }
    printf("-----------------\n\n");
}

// Fução principal do projeto
int main() {
    srand(time(NULL));

    // Inicializa fila com 5 peças
    for (int i = 0; i < TAM_FILA; i++) {
        enqueue(gerarPeca());
    }

    int opc;
    do {
        printf("===TETRIS STACK / NIVEL NOVATO ===\n");
        printf("1 - Jogar peca (remove e gera nova)\n");
        printf("2 - Inserir nova peca manual\n");
        printf("3 - Mostrar fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        if (opc == 1) {
            Peca jogada = dequeue();
            if (jogada.id != 0) {
                printf("Voce jogou a peca: id=%d tipo=%c\n", jogada.id, jogada.tipo);
                Peca nova = gerarPeca();
                enqueue(nova);
                printf("Nova peca gerada: id=%d tipo=%c\n", nova.id, nova.tipo);
            }
        } else if (opc == 2) {
            enqueue(gerarPeca());
        } else if (opc == 3) {
            mostrarFila();
        }

    } while (opc != 0);

    printf("Encerrando o jogo...\n");
    return 0;
}