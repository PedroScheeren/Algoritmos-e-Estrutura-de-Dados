#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PESSOA (100 + sizeof(int) + 100)

#define TAM_PTR         (*(int*)buffer)
#define QTD_PTR         (*(int*)(buffer + sizeof(int)))
#define TMP_INT         (*(int*)(buffer + 2*sizeof(int)))          // leitura de inteiros (MENU TAMBÉM!)
#define TMP_TEXTO       ((char*)(buffer + 3*sizeof(int)))          // leitura de nomes/emails
#define PESSOAS_PTR     (buffer + 200)                             // área fixa para pessoas


void *AddPessoa( void *buffer );
void Listar( void *buffer );
void Buscar( void *buffer );
void *RemoverPessoa( void *buffer );


int main() {

    void *buffer = malloc( 200 ); 

    if ( !buffer ) {
        printf( "Erro ao alocar memoria" );
        exit( 1 );
    }
    
    TAM_PTR = TAM_PESSOA;
    QTD_PTR = 0;

    do {
        printf( "\n===== MENU =====\n" );
        printf( "1 - Adicionar pessoa\n" );
        printf( "2 - Remover pessoa\n" );
        printf( "3 - Buscar pessoa\n" );
        printf( "4 - Listar todos\n" );
        printf( "5 - Sair\n" );
        printf( "Opcao -> " );
        scanf( "%d", &TMP_INT );
        getchar();

        switch ( TMP_INT ) {
            case 1: buffer = AddPessoa( buffer ); break;
            case 2: buffer = RemoverPessoa( buffer ); break;
            case 3: Buscar( buffer ); break;
            case 4: Listar( buffer ); break;
        }

    } while ( TMP_INT != 5 );

    free( buffer );
    return 0;
}


void *AddPessoa( void *buffer ) {

    void *novo = realloc( buffer, 200 + ( QTD_PTR + 1 ) * TAM_PTR );
    if ( !novo ) {
        return buffer;
    }
    buffer = novo;

    void *pessoa = PESSOAS_PTR + QTD_PTR * TAM_PTR;

    printf( "Nome: " );
    scanf( "%[^\n]", TMP_TEXTO ); getchar();
    strcpy( ( char* )pessoa, TMP_TEXTO );

    printf( "Idade: " );
    scanf( "%d", &TMP_INT ); getchar();
    *( int* )( pessoa + 100 ) = TMP_INT;

    printf( "Email: " );
    scanf( "%[^\n]", TMP_TEXTO ); getchar();
    strcpy( ( char* )( pessoa + 100 + sizeof( int ) ), TMP_TEXTO );

    QTD_PTR++;
    return buffer;
}


void Listar( void *buffer ) {

    if ( QTD_PTR == 0 ) {
        printf( "Nenhuma pessoa cadastrada.\n" );
        return;
    }

    TMP_INT = 0;
    while ( TMP_INT < QTD_PTR ) {

        void *pessoa = PESSOAS_PTR + TMP_INT * TAM_PTR;

        printf( "\n--- Pessoa %d ---\n", TMP_INT );
        printf( "Nome: %s\n", ( char* )pessoa );
        printf( "Idade: %d\n", *( int* )( pessoa + 100 ) );
        printf( "Email: %s\n", ( char* )( pessoa + 100 + sizeof( int ) ) );

        TMP_INT++;
    }
}

void Buscar( void *buffer ) {

    if ( QTD_PTR == 0 ) {
        printf( "Nenhuma pessoa cadastrada.\n" );
        return;
    }

    printf( "Nome para buscar: " );
    scanf( "%[^\n]", TMP_TEXTO ); getchar();

    TMP_INT = 0;
    while ( TMP_INT < QTD_PTR ) {

        void *pessoa = PESSOAS_PTR + TMP_INT * TAM_PTR;

        if ( strcmp( ( char* )pessoa, TMP_TEXTO ) == 0 ) {

            printf( "\n=== ENCONTRADO ===\n" );
            printf( "Nome: %s\n", ( char* )pessoa );
            printf( "Idade: %d\n", *( int* )( pessoa + 100 ) );
            printf( "Email: %s\n", ( char* )( pessoa + 100 + sizeof( int ) ) );
            return;
        }

        TMP_INT++;
    }

    printf( "Pessoa nao encontrada.\n" );
}


void *RemoverPessoa( void *buffer ) {

    if ( QTD_PTR == 0 ) {
        printf( "Nenhuma pessoa cadastrada.\n" );
        return buffer;
    }

    Listar( buffer );

    printf( "ID para remover: " );
    scanf( "%d", &TMP_INT ); getchar();

    if ( TMP_INT < 0 || TMP_INT >= QTD_PTR ) {
        printf( "ID invalido.\n" );
        return buffer;
    }

    void *pessoaRemovida = PESSOAS_PTR + TMP_INT * TAM_PTR;
    void *proxima  = pessoaRemovida + TAM_PTR;

    memmove( pessoaRemovida, proxima, ( QTD_PTR - TMP_INT - 1 ) * TAM_PTR );

    QTD_PTR--;

    void *novo = realloc( buffer, 200 + QTD_PTR * TAM_PTR );
    if ( !novo ) {
        return buffer; // Retorna o buffer antigo se a realocação falhar
    }

    return novo;
}