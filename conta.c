#include <stdio.h>
#include "enco.h"

// Função para inicializar todas as contas como inativas

void inicializarContas() {
    for (int i = 0; i < numContas; i++) {
        contas[i].ativa = 0;
    }
}

// Função para encontrar o próximo índice disponível na matriz de contas

int encontrarProximoIndiceDisponivel() {
    for (int i = 0; i < numContas; i++) {
        if (contas[i].ativa == 0) { // Verifica se a conta está inativa
            return i; // Retorna o índice do próximo elemento disponível
        }
    }
    return -1; // Retorna -1 se não houver mais lugar disponível
}

// Função para inserir uma nova conta na matriz de contas

void inserirNovaConta() {
    int indice = encontrarProximoIndiceDisponivel();
    
    if (indice != -1) { // Se houver um índice disponível
	printf("\nIndice: %d\n", indice);

        printf("Digite o número da conta: ");
        scanf("%d", &contas[indice].numeroConta);
        
        printf("Digite o número da agência: ");
        scanf("%d", &contas[indice].agencia);
        
        printf("Digite o tipo de conta (1 para corrente, 2 para poupança): ");
        scanf("%d", &contas[indice].tipoConta);
        
        printf("Digite o CPF do cliente: ");
        scanf("%s", contas[indice].cpfCliente);
        
        printf("Digite o saldo inicial: ");
        scanf("%lf", &contas[indice].saldo);
        
        contas[indice].ativa = 1; // Ativa a conta
        
        printf("Conta criada com sucesso!\n");
    } else {
        printf("Não há mais lugares disponíveis para criar uma nova conta.\n");
    }
}

// Função para ordenar uma cópia da matriz de contas com base no número da conta usando Bubble Sort
void ordenarContas(struct conta* copiaContas) {
    for (int i = 0; i < numContas - 1; i++) {
        for (int j = 0; j < numContas - i - 1; j++) {
            if (copiaContas[j].numeroConta > copiaContas[j + 1].numeroConta) {
                // Troca as contas se estiverem fora de ordem
                struct conta temp = copiaContas[j];
                copiaContas[j] = copiaContas[j + 1];
                copiaContas[j + 1] = temp;
            }
        }
    }
}

// Função para encontrar uma conta por número usando busca binária e retornar o índice
int buscarContaPorNumero(int numero, struct conta* copiaContas) {
    int esquerda = 0;
    int direita = numContas - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (copiaContas[meio].numeroConta == numero) {
            return meio;
        }
        if (copiaContas[meio].numeroConta < numero) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    // Se a conta não for encontrada, retorna -1
    return -1;
}

// Método para consultar uma conta por número
void consultarConta() {
    // Faz uma cópia da matriz de contas
    struct conta copiaContas[numContas];
    for (int i = 0; i < numContas; i++) {
        copiaContas[i] = contas[i];
    }

    // Ordena a cópia das contas com base no número da conta
    ordenarContas(copiaContas);

    int numero;
    printf("Digite o número da conta que deseja consultar: ");
    scanf("%d", &numero);

    int indice = buscarContaPorNumero(numero, copiaContas);

    if (indice != -1) {
        printf("Conta encontrada:\n");
        printf("Número da Conta: %d\n", copiaContas[indice].numeroConta);
        printf("Agência: %d\n", copiaContas[indice].agencia);
        printf("Tipo de Conta: %d\n", copiaContas[indice].tipoConta);
        printf("CPF do Cliente: %s\n", copiaContas[indice].cpfCliente);
        printf("Saldo: %.2lf\n", copiaContas[indice].saldo);
    } else {
        printf("Conta não encontrada.\n");
    }
}
