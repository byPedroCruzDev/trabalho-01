#include <stdio.h>
#include <string.h>

// Funções para cada funcionalidade
void cadastrarProdutos(char descricao[][50], int estoque[][3]);
void retirarProduto(char descricao[][50], int estoque[][3]);
void mostrarEstoqueMinimo(char descricao[][50], int estoque[][3]);
void mostrarValorTotal(int estoque[][3]);

int main() {
    char descricao[6][50];
    int estoque[6][3];  // [0]: Quantidade em estoque, [1]: Quantidade mínima, [2]: Valor unitário

    int opcao;
    do {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Retirar produto do estoque\n");
        printf("3. Mostrar produtos abaixo do estoque mínimo\n");
        printf("4. Mostrar valor total dos produtos em estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProdutos(descricao, estoque);
                break;
            case 2:
                retirarProduto(descricao, estoque);
                break;
            case 3:
                mostrarEstoqueMinimo(descricao, estoque);
                break;
            case 4:
                mostrarValorTotal(estoque);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void cadastrarProdutos(char descricao[][50], int estoque[][3]) {
    printf("\nCadastro de produtos:\n");
    for (int i = 0; i < 6; i++) {
        printf("Produto %d:\n", i+1);
        printf("Descrição: ");
        scanf("%s", descricao[i]);

        do {
            printf("Quantidade em estoque: ");
            scanf("%d", &estoque[i][0]);
            printf("Quantidade mínima exigida: ");
            scanf("%d", &estoque[i][1]);
        } while (estoque[i][0] < estoque[i][1]);

        do {
            printf("Valor unitário: ");
            scanf("%f", &estoque[i][2]);
        } while (estoque[i][2] <= 0);
    }
}

void retirarProduto(char descricao[][50], int estoque[][3]) {
    char produtoDesejado[50];
    int quantidadeDesejada;

    printf("\nRetirar produto do estoque:\n");
    printf("Nome do produto desejado: ");
    scanf("%s", produtoDesejado);

    int indiceProduto = -1;
    for (int i = 0; i < 6; i++) {
        if (strcmp(descricao[i], produtoDesejado) == 0) {
            indiceProduto = i;
            break;
        }
    }

    if (indiceProduto == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    printf("Quantidade desejada: ");
    scanf("%d", &quantidadeDesejada);

    if (estoque[indiceProduto][0] >= quantidadeDesejada) {
        estoque[indiceProduto][0] -= quantidadeDesejada;
        printf("Produto retirado com sucesso.\n");
    } else {
        printf("Estoque insuficiente.\n");
    }
}

void mostrarEstoqueMinimo(char descricao[][50], int estoque[][3]) {
    printf("\nProdutos abaixo do estoque mínimo:\n");
    for (int i = 0; i < 6; i++) {
        if (estoque[i][0] < estoque[i][1]) {
            printf("Produto: %s\n", descricao[i]);
        }
    }
}

void mostrarValorTotal(int estoque[][3]) {
    int valorTotal = 0;
    for (int i = 0; i < 6; i++) {
        valorTotal += estoque[i][0] * estoque[i][2];
    }
    printf("\nValor total dos produtos em estoque: R$%d\n", valorTotal);
}
