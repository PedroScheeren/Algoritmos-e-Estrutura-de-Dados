#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} MinHeap;

// -------------------- FUNÇÕES DO MIN HEAP --------------------

MinHeap* criar_heap(int capacidade) {
    MinHeap *h = (MinHeap*) malloc(sizeof(MinHeap));
    h->dados = (int*) malloc(sizeof(int) * (capacidade + 1));  
    h->tamanho = 0;
    h->capacidade = capacidade;
    return h;
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void subir(MinHeap *h, int i) {
    while (i > 1 && h->dados[i/2] > h->dados[i]) {
        trocar(&h->dados[i], &h->dados[i/2]);
        i /= 2;
    }
}

void descer(MinHeap *h, int i) {
    int menor = i;
    int esq = 2*i;
    int dir = 2*i + 1;

    if (esq <= h->tamanho && h->dados[esq] < h->dados[menor]) menor = esq;
    if (dir <= h->tamanho && h->dados[dir] < h->dados[menor]) menor = dir;

    if (menor != i) {
        trocar(&h->dados[i], &h->dados[menor]);
        descer(h, menor);
    }
}

void inserir(MinHeap *h, int valor) {
    if (h->tamanho == h->capacidade) return;
    h->tamanho++;
    h->dados[h->tamanho] = valor;
    subir(h, h->tamanho);
}

int remover_min(MinHeap *h) {
    if (h->tamanho == 0) return -1;
    int menor = h->dados[1];
    h->dados[1] = h->dados[h->tamanho];
    h->tamanho--;
    descer(h, 1);
    return menor;
}

// -------------------- GERENTE DE ASSENTOS --------------------

typedef struct {
    MinHeap *assentos;
} SeatManager;

SeatManager* criarSeatManager(int n) {
    SeatManager *sm = (SeatManager*) malloc(sizeof(SeatManager));
    sm->assentos = criar_heap(n);

    // Inicialmente, todos os assentos estão livres:
    for (int i = 1; i <= n; i++) {
        inserir(sm->assentos, i);
    }
    return sm;
}

int reservar(SeatManager *sm) {
    return remover_min(sm->assentos);
}

void liberar(SeatManager *sm, int assento) {
    inserir(sm->assentos, assento);
}

// -------------------- MAIN PARA TESTES --------------------

int main() {
    int n = 5;
    SeatManager *sm = criarSeatManager(n);

    printf("Reserva 1: %d\n", reservar(sm)); // assento 1
    printf("Reserva 2: %d\n", reservar(sm)); // assento 2

    liberar(sm, 1);

    printf("Reserva 3: %d\n", reservar(sm)); // assento 1 volta
    printf("Reserva 4: %d\n", reservar(sm)); // assento 3

    return 0;
}
