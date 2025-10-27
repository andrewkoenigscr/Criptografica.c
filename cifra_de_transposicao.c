#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 10000
#define MAX_KEY 100
#define PADDING 'X'

// Remove espaços e coloca em maiúsculas
void formatar_texto(char texto[]) {
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!isspace((unsigned char)texto[i]))
            texto[j++] = toupper((unsigned char)texto[i]);
    }
    texto[j] = '\0';
}

// Gera a ordem das colunas da chave
void gerar_ordem(char chave[], int colunas, int ordem[]) {
    int usado[MAX_KEY] = {0};
    for (int i = 0; i < colunas; i++) {
        int pos_min = -1;
        for (int j = 0; j < colunas; j++) {
            if (!usado[j]) {
                if (pos_min == -1 || chave[j] < chave[pos_min])
                    pos_min = j;
            }
        }
        ordem[pos_min] = i;
        usado[pos_min] = 1;
    }
}

// Criptografa usando a cifra de transposição
void criptografia_trans(char texto[], char chave[]) {
    formatar_texto(texto);
    formatar_texto(chave);

    int colunas = strlen(chave);
    int n = strlen(texto);
    int linhas = (n + colunas - 1) / colunas;
    int ordem[MAX_KEY];
    gerar_ordem(chave, colunas, ordem);

    char matriz[linhas][colunas];
    int pos = 0;

    // Preenche a matriz com padding
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (pos < n)
                matriz[i][j] = texto[pos++];
            else
                matriz[i][j] = PADDING;
        }
    }

    // Lê coluna por coluna
    pos = 0;
    for (int k = 0; k < colunas; k++) {
        for (int j = 0; j < colunas; j++) {
            if (ordem[j] == k) {
                for (int i = 0; i < linhas; i++)
                    texto[pos++] = matriz[i][j];
            }
        }
    }
    texto[pos] = '\0';
}

// Descriptografa usando a cifra de transposição
void descriptografia_trans(char texto[], char chave[]) {
    formatar_texto(texto);
    formatar_texto(chave);

    int colunas = strlen(chave);
    int n = strlen(texto);
    int linhas = n / colunas;
    int ordem[MAX_KEY];
    gerar_ordem(chave, colunas, ordem);

    char matriz[linhas][colunas];
    int pos = 0;

    // Preenche matriz coluna por coluna
    for (int k = 0; k < colunas; k++) {
        for (int j = 0; j < colunas; j++) {
            if (ordem[j] == k) {
                for (int i = 0; i < linhas; i++)
                    matriz[i][j] = texto[pos++];
            }
        }
    }

    // Lê matriz linha por linha
    pos = 0;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            texto[pos++] = matriz[i][j];
    }
    texto[pos] = '\0';
}

// Menu estilo cifra de César
int cifra_de_transposicao() {
    char texto[MAX_TEXT];
    char chave[MAX_KEY];
    int opcao;

    printf("\n===== Cifra de Transposicao =====\n");
    printf("\n1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // limpa buffer

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    printf("Digite a chave: ");
    fgets(chave, sizeof(chave), stdin);
    chave[strcspn(chave, "\n")] = '\0';

    if (opcao == 1) {
        criptografia_trans(texto, chave);
        printf("\nTexto criptografado: %s\n", texto);
    } else if (opcao == 2) {
        descriptografia_trans(texto, chave);
        printf("\nTexto descriptografado: %s\n", texto);
    } else {
        printf("Comando nao reconhecido.\n");
    }

    return 0;
}
