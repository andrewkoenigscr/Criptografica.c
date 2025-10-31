#include <stdio.h>
#include "cifra_de_cesar.h"
#include "cifra_de_transposicao.h"
#include "chave_cadeado.h"


void seletor(){
  int a;
  printf("\nCRIPTOGRAFA.C\n");
  printf("\n0 - Sair\n1 - Cifra de Cesar\n2 - Transposição\n3 - Chave e Cadeado\n");
  printf("\nComando: ");
  scanf("%d", &a);
  switch (a){
    case 0:
      printf("Saindo...");
      break;
    
    case 1:
      cifra_de_cesar();
      break;
    
    case 2:
      cifra_de_transposicao();
      break;
    
    case 3:
      menuCvCd();
      break;
    
    default:
      printf("Comando não reconhecido. Voltando a tela inicial\n");
      seletor();
      break;
  }
}

int main(){
  seletor();
}
