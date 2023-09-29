
// Definição da estrutura de conta bancária

#define numContas 15

struct conta {
    int ativa;
    int numeroConta;
    int agencia;
    int tipoConta;
    char cpfCliente[12];
    double saldo;
};

struct conta contas[numContas];
