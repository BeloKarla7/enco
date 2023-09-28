
// Definição da estrutura de conta bancária

struct _conta {
    int ativa;
    int numeroConta;
    int agencia;
    int tipoConta;
    char cpfCliente[12];
    double saldo;
};

typedef struct _conta *conta;

int numContas = 15;

conta contas;
