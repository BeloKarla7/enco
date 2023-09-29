#include <stdio.h>
#include <stdlib.h>

#include "conta.h"

void menu1() {
  int opc;

  do {
    printf("\nBanco ENCO\n");
    printf("\nCadastros\n");
    printf("1. Incluir\n");
    printf("2. Pesquisar\n");
    printf("3. Retornar\n");
    printf("\nEscolha sua opção: ");

    scanf("%d", &opc);

    switch (opc) {
      case 1:
        inserirNovaConta();
        break;
      case 2:
        consultarConta();
        break;
      case 3:
        break;
      default:
        printf("\nOpção inválida. Tente novamente\n");
        break;
    }
  } while (opc != 3);
}

void menu() {
  int opc;

  do {
    printf("\nBanco ENCO\n");
    printf("1. Cadastros\n");
    printf("2. Transações\n");
    printf("4. Listagem\n");
    printf("5. Encerrar\n");
    printf("\nEscolha sua opção: ");

    scanf("%d", &opc);

    switch (opc) {
      case 1:
        menu1();
        break;
      case 5:
        break;
      default:
        printf("\nOpção inválida. Tente novamente\n");
        break;
    }
  } while (opc != 5);
}
