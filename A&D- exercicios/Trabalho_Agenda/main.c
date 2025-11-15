#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PESSOA (100 + sizeof(int) + 100)

#define TAM_PTR         (*(int*)buffer)
#define QTD_PTR         (*(int*)(buffer + sizeof(int)))
#define TMP_INT         (*(int*)(buffer + 2*sizeof(int)))          // leitura de inteiros (MENU TAMBÉM!)
#define TMP_TEXTO       ((char*)(buffer + 3*sizeof(int)))          // leitura de nomes/emails
#define PESSOAS_PTR     (buffer + 200)                             // área fixa para pessoas

void *addPessoa(void *buffer);
void listar(void *buffer);
void buscar(void *buffer);
void *removerPessoa(void *buffer);

int main() {

    void *buffer = malloc(300); 
    TAM_PTR = TAM_PESSOA;
    QTD_PTR = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar pessoa\n");
        printf("2 - Remover pessoa\n");
        printf("3 - Buscar pessoa\n");
        printf("4 - Listar todos\n");
        printf("5 - Sair\n");
        printf("Opcao -> ");
        scanf("%d", &TMP_INT);
        getchar();

        switch (TMP_INT) {
            case 1: buffer = addPessoa(buffer); break;
            case 2: buffer = removerPessoa(buffer); break;
            case 3: buscar(buffer); break;
            case 4: listar(buffer); break;
        }

    } while (TMP_INT != 5);

    free(buffer);
    return 0;
}

void *addPessoa(void *buffer) {

    void *novo = realloc(buffer, 200 + (QTD_PTR+1)*TAM_PTR);
    if (!novo) return buffer;
    buffer = novo;

    void *pessoa = PESSOAS_PTR + QTD_PTR*TAM_PTR;

    printf("Nome: ");
    scanf("%[^\n]", TMP_TEXTO); getchar();
    strcpy((char*)pessoa, TMP_TEXTO);

    printf("Idade: ");
    scanf("%d", &TMP_INT); getchar();
    *(int*)(pessoa + 100) = TMP_INT;

    printf("Email: ");
    scanf("%[^\n]", TMP_TEXTO); getchar();
    strcpy((char*)(pessoa + 100 + sizeof(int)), TMP_TEXTO);

    QTD_PTR++;
    return buffer;
}

void listar(void *buffer) {

    if (QTD_PTR == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    TMP_INT = 0;
    while (TMP_INT < QTD_PTR) {

        void *pessoa = PESSOAS_PTR + TMP_INT*TAM_PTR;

        printf("\n--- Pessoa %d ---\n", TMP_INT);
        printf("Nome: %s\n", (char*)pessoa);
        printf("Idade: %d\n", *(int*)(pessoa + 100));
        printf("Email: %s\n", (char*)(pessoa + 100 + sizeof(int)));

        TMP_INT++;
    }
}

void buscar(void *buffer) {

    if (QTD_PTR == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    printf("Nome para buscar: ");
    scanf("%[^\n]", TMP_TEXTO); getchar();

    TMP_INT = 0;
    while (TMP_INT < QTD_PTR) {

        void *pessoa = PESSOAS_PTR + TMP_INT*TAM_PTR;

        if (strcmp((char*)pessoa, TMP_TEXTO) == 0) {

            printf("\n=== ENCONTRADO ===\n");
            printf("Nome: %s\n", (char*)pessoa);
            printf("Idade: %d\n", *(int*)(pessoa + 100));
            printf("Email: %s\n", (char*)(pessoa + 100 + sizeof(int)));
            return;
        }

        TMP_INT++;
    }

    printf("Pessoa nao encontrada.\n");
}

void *removerPessoa(void *buffer) {

    if (QTD_PTR == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return buffer;
    }

    listar(buffer);

    printf("ID para remover: ");
    scanf("%d", &TMP_INT); getchar();

    if (TMP_INT < 0 || TMP_INT >= QTD_PTR) {
        printf("ID invalido.\n");
        return buffer;
    }

    void *dest = PESSOAS_PTR + TMP_INT*TAM_PTR;
    void *src  = dest + TAM_PTR;

    memmove(dest, src, (QTD_PTR - TMP_INT - 1)*TAM_PTR);

    QTD_PTR--;

    void *novo = realloc(buffer, 200 + QTD_PTR*TAM_PTR);
    if (!novo) return buffer;

    return novo;
}
