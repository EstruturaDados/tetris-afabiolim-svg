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

// Salva peça histórico 
void registrar(Peca p) {
    if (tamHist < TAM_HISTORICO)
        historico[tamHist++] = p;
}

// Desfaz última jogada
void desfazer() {
    if (tamHist == 0) {
        printf("Nada a desfazer.\n");
        return;
    }
    Peca ultima = historico[--tamHist];
    enqueue(ultima);
    printf("Desfez jogada: id=%d tipo=%c\n", ultima.id, ultima.tipo);
}

// Inverte a ordem fila
void inverterFila() {
    if (filaVazia()) return;
    Peca temp[TAM_FILA];

    // Copia a fila para um vetor temporário
    for (int i = 0; i < tamanhoFila; i++) {
        int idx = (frente + i) % TAM_FILA;
        temp[i] = fila[idx];
    }

    // Regrava
    for (int i = 0; i < tamanhoFila; i++) {
        fila[(frente + i) % TAM_FILA] = temp[tamanhoFila - 1 - i];
    }

    printf("Fila invertida!\n");
}


// Troca o topo da pilha
void trocar() {
    if (pilhaVazia() || filaVazia()) {
        printf("Nao ha pecas suficientes para troca.\n");
        return;
    }
    Peca temp = pilha[topo];
    pilha[topo] = fila[frente];
    fila[frente] = temp;
    printf("Trocou topo da pilha com frente da fila!\n");
}


}
int main() {
    srand(time(NULL));
    for (int i = 0; i < TAM_FILA; i++) enqueue(gerarPeca());

    int op;
    do {
        printf("\n=== TETRIS STACK - NIVEL MESTRE ===\n");
        printf("1 - Jogar peca\n");
        printf("2 - Reservar peca\n");
        printf("3 - Usar peca reservada\n");
        printf("4 - Trocar topo da pilha com frente da fila\n");
        printf("5 - Desfazer ultima jogada\n");
        printf("6 - Inverter fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

         if (op == 1) {
            Peca jogada = dequeue();
            if (jogada.id != 0) {
                printf("Jogou peca id=%d tipo=%c\n", jogada.id, jogada.tipo);
                registrar(jogada);
                enqueue(gerarPeca());
            }
        } else if (op == 2) {
            if (!filaVazia()) {
                Peca reservada = dequeue();
                push(reservada);
                enqueue(gerarPeca());
                printf("Reservou peca id=%d tipo=%c\n", reservada.id, reservada.tipo);
            }
            

    return 0;
}