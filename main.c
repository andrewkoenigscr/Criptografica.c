#include <stdio.h>

int main(){
  int a = 0;

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
    printf("0 - Sair\n");
    printf("1 - Cifra de Cesar\n");
    printf("2 - Rafael\n");
    printf("3 - Andrew\n");
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
      printf("Andrew\n");
      break;
    default:
      printf("Opção inválida\n");
      break;
    }
  default:
    break;
  }
}