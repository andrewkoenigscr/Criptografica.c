#include <stdio.h>
#include "transposicao.c"

int seletor(int a);

int main()
{
  seletor(0);
}

int seletor(int a)
{
  printf("CRIPTOGRAFICA.C\n");
  printf("0 - Sair\n");
  printf("1 - Criptografar\n");
  printf("2 - Descriptografar\n");
  printf("Escolha uma opção: ");
  scanf("%d", &a);

  switch (a){
  case 0:
    printf("Saindo...\n");
    break;
  case 1:
    printf("CRIPTOGRAFIA:\n");
    printf("0 - Sair\n");
    printf("1 - Cifra de Cesar\n");
    printf("2 - Rafael\n");
    printf("3 - Cifra de Transposição\n");
    printf("Escolha uma opção: ");
    scanf("%d", &a);
    switch (a){
    case 0:
      printf("Saindo...\n");
      break;
    case 1:
      printf("Cifra de Cesar\n");
      break;
    case 2:
      printf("Rafael\n");
      break;
    case 3:
      cripto_trans();
      break;
    default:
      printf("Opção inválida\n");
      break;
    }
    break;
  case 2:
    printf("DESCRIPTOGRAFIA:\n");
    printf("0 - Sair\n");
    printf("1 - Cifra de Cesar\n");
    printf("2 - Rafael\n");
    printf("3 - Cifra de Transposição\n");
    printf("Escolha uma opção: ");
    scanf("%d", &a);
    switch (a){
    case 0:
      printf("Saindo...\n");
      break;
    case 1:
      printf("Cifra de Cesar\n");
      break;
    case 2:
      printf("Rafael\n");
      break;
    case 3:
      descripto_trans();
      break;
    default:
      printf("Opção inválida\n");
      break;
    }
    break;
  default:
    break;
  }
}