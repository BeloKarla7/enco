#include <stdio.h>
#include <stdlib.h>

#include "enco.h"

int encontrarProximoRegistroDisponivel(conta contas[], int numContas) {
  for (int i = 0; i < numContas; i++) {
    if (contas[i]->ativa == 0) {
      return i;  // Índice da próxima conta disponível
    }
  }

  return -1;  // Nenhuma conta disponível
}

void cadastrarConta(conta contas[], int numContas) {
  int proximoRegistro = encontrarProximoRegistroDisponivel(contas, numContas);
  if (proximoRegistro != -1) {
    int numConta, agencia, tipoConta;
    char cpfCliente[12];
    double saldo;

    printf("Número da Conta: ");
    scanf("%d", &numConta);

    printf("Agência: ");
    scanf("%d", &agencia);

    printf("Tipo da Conta (1 - Conta Corrente, 2 - Conta Poupança): ");
    scanf("%d", &tipoConta);

    printf("CPF do Cliente: ");
    scanf("%s", cpfCliente);

    printf("Saldo Inicial: ");
    scanf("%lf", &saldo);

    contas[proximoRegistro].ativa = 1;  // Marca a conta como ativa
    contas[proximoRegistro].numeroConta = numConta;
    contas[proximoRegistro].agencia = agencia;
    contas[proximoRegistro].tipoConta = tipoConta;
    strcpy(contas[proximoRegistro].cpfCliente, cpfCliente);
    contas[proximoRegistro].saldo = saldo;

    printf("Conta cadastrada com sucesso!\n");
  } else {
    printf("Não há registros disponíveis para cadastrar uma nova conta.\n");
  }
}