#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para criptografar o texto usando a cifra de César
void criptografar(char texto[], int chave) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if (isalpha(c)) { // Verifica se é uma letra
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + chave) % 26 + base;
        }

        texto[i] = c;
    }
}

// Função para descriptografar o texto
void descriptografar(char texto[], int chave) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - chave + 26) % 26 + base;
        }

        texto[i] = c;
    }
}

int main() {
    char texto[256];
    int chave, opcao;

    printf("===== Cifra de César =====\n");
    printf("1 - Criptografar\n");
    printf("2 - Descriptografar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // limpa o buffer

    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0'; // remove o \n do final

    printf("Digite a chave (numero de deslocamentos): ");
    scanf("%d", &chave);

    if (opcao == 1) {
        criptografar(texto, chave);
        printf("\nTexto criptografado: %s\n", texto);
    } else if (opcao == 2) {
        descriptografar(texto, chave);
        printf("\nTexto descriptografado: %s\n", texto);
    } else {
        printf("Opcao invalida.\n");
    }

    return 0;
}
