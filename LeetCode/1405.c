#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int count;
    char ch;
} Node;

typedef struct {
    Node heap[4];  // só precisamos no máximo de 3 elementos
    int size;
} MaxHeap;

// Funções da heap
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapPush(MaxHeap *h, int count, char ch) {
    h->heap[++h->size].count = count;
    h->heap[h->size].ch = ch;

    int i = h->size;
    while (i > 1 && h->heap[i].count > h->heap[i/2].count) {
        swap(&h->heap[i], &h->heap[i/2]);
        i /= 2;
    }
}

Node heapTop(MaxHeap *h) {
    return h->heap[1];
}

void heapPop(MaxHeap *h) {
    h->heap[1] = h->heap[h->size--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i + 1, largest = i;
        if (left <= h->size && h->heap[left].count > h->heap[largest].count)
            largest = left;
        if (right <= h->size && h->heap[right].count > h->heap[largest].count)
            largest = right;
        if (largest == i) break;

        swap(&h->heap[i], &h->heap[largest]);
        i = largest;
    }
}

char* longestDiverseString(int a, int b, int c) {
    MaxHeap pq = { .size = 0 };

    if (a > 0) heapPush(&pq, a, 'a');
    if (b > 0) heapPush(&pq, b, 'b');
    if (c > 0) heapPush(&pq, c, 'c');

    char *ans = (char*) malloc(400 * sizeof(char));
    int len = 0;

    while (pq.size > 0) {
        Node p = heapTop(&pq);
        heapPop(&pq);

        int count = p.count;
        char ch = p.ch;

        // verificar se cria "xxx"
        if (len >= 2 && ans[len-1] == ch && ans[len-2] == ch) {
            if (pq.size == 0) break;
            
            Node temp = heapTop(&pq);
            heapPop(&pq);

            ans[len++] = temp.ch;

            if (temp.count - 1 > 0)
                heapPush(&pq, temp.count - 1, temp.ch);

            // recoloca o maior
            heapPush(&pq, count, ch);
        } else {
            ans[len++] = ch;
            count--;

            if (count > 0)
                heapPush(&pq, count, ch);
        }
    }

    ans[len] = '\0';
    return ans;
}

// Teste
int main() {
    printf("%s\n", longestDiverseString(1, 1, 7)); // Exemplo 1
    printf("%s\n", longestDiverseString(7, 1, 0)); // Exemplo 2
    return 0;
}
