#include "conta.h"
#include <stdio.h>

#include "conta.h"
#include "transacao.h"

// Função para realizar um depósito em uma conta
void realizarDeposito(int numeroConta, double valor) {
    int indice = buscarContaPorNumero(numeroConta, contas);

    if (indice != -1) {
        if (valor > 0) {
            contas[indice].saldo += valor;
            printf("Depósito de %.2lf realizado com sucesso na conta %d.\n", valor, contas[indice].numeroConta);
            printf("Novo saldo da conta: %.2lf\n", contas[indice].saldo);
        } else {
            printf("Valor de depósito inválido. O valor deve ser positivo.\n");
        }
    } else {
        printf("Conta não encontrada. Depósito não realizado.\n");
    }
}

// Função para realizar uma entrada em uma conta
void realizarEntrada(int numeroConta, double valor) {
    int indice = buscarContaPorNumero(numeroConta, contas);

    if (indice != -1) {
        if (valor > 0) {
            contas[indice].saldo += valor;
            printf("Entrada de %.2lf realizada com sucesso na conta %d.\n", valor, contas[indice].numeroConta);
            printf("Novo saldo da conta: %.2lf\n", contas[indice].saldo);
        } else {
            printf("Valor de entrada inválido. O valor deve ser positivo.\n");
        }
    } else {
        printf("Conta não encontrada. Entrada não realizada.\n");
    }
}
