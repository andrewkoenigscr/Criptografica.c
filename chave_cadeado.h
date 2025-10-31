#ifndef CHAVE_CADEADO_H
#define CHAVE_CADEADO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definição da estrutura chaveiro
typedef struct chaveiro {
    char nameChave[20];
    char chave[53][2];
} chaveiro;

// Protótipos das funções
void limpeza();
void functionChave(char chave[53][2], char name[20]);
void codificador(char cadeado[53][2]);
void decodificador(char cadeado[53][2]);
void menuCvCd();

#endif
