#include <stdio.h>
#include <stdlib.h>

void menu1() {

    int opc;

    printf("\nBanco ENCO\n");
    printf("\nCadastros\n");
    printf("1. Incluir\n");
    printf("2. Pesquisar\n");
    printf("\nEscolha sua opção: ");

    scanf("%d",&opc);

    switch(opc)
    {
        case 1:
	    printf("Opcao 1\n");
        case 2:
	    printf("Opcao 1\n");
        default:
	    printf("\nOpção inválida. Tente novamente\n");break;
    }

}

void menu() {

    int opc;

    printf("\nBanco ENCO\n");
    printf("1. Cadastros\n");
    printf("2. Transações\n");
    printf("4. Listagem\n");
    printf("5. Encerrar\n");
    printf("\nEscolha sua opção: ");

    scanf("%d",&opc);

    switch(opc)
    {
        case 1:
	    menu1();
        default:
	    printf("\nOpção inválida. Tente novamente\n");break;
    }

}
