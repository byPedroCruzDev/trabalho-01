#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PRODUTOS 6
float valor_total = 0.0;

char descricao_produtos[MAX_PRODUTOS][50] = {
    "Pao com Gergilin",
    "Alface Americana",
    "Tomate",
    "Queijo Cheddar",
    "Hamburguer",
    "Nuggets"
};

int quantidade_estoque[MAX_PRODUTOS] = {0, 0, 0, 0, 0, 0};
int quantidade_minima[MAX_PRODUTOS] = {5, 8, 4, 15, 60, 50};
float valor_unitario[MAX_PRODUTOS] = {1.2, 2.3, 2.7, 30.5, 3.1, 2.8};

void cadastrar_produto(int *total_produtos) {
    if (*total_produtos >= MAX_PRODUTOS) {
        printf("Erro: Não é possível cadastrar mais produtos.\n");
        return;
    }

    printf("Escolha o produto a cadastrar:\n");
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("%d. %s\n", i + 1, descricao_produtos[i]);
    }

    int escolha;
    printf("Digite o número correspondente ao produto desejado: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > MAX_PRODUTOS) {
        printf("Opção inválida.\n");
        return;
    }

    escolha--; 

    printf("Digite a quantidade em estoque para %s: ", descricao_produtos[escolha]);
    scanf("%d", &quantidade_estoque[escolha]);

   (*total_produtos)++;
    printf("Produto cadastrado com sucesso!\n");

}

void retirar_produto(int total_produtos) {
    printf("Escolha o produto a ser retirado do estoque:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("%d. %s\n", i + 1, descricao_produtos[i]);
    }

    int escolha;
    printf("Digite o número correspondente ao produto desejado: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > total_produtos) {
        printf("Opção inválida.\n");
        return;
    }

    escolha--;

    int quantidade_desejada;
    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade_desejada);

    if (quantidade_estoque[escolha] >= quantidade_desejada) {
        quantidade_estoque[escolha] -= quantidade_desejada;
        printf("Produto retirado do estoque com sucesso!\n");
    } else {
        printf("Estoque insuficiente.\n");
    }
}
void mostrar_produtos_abaixo_minimo(int total_produtos) {
    printf("Produtos com estoque abaixo do mínimo exigido:\n");
    for (int i = 0; i < total_produtos; i++) {
        if (quantidade_estoque[i] < quantidade_minima[i]) {
            printf("%s\n", descricao_produtos[i]);
        }
    }
}

void calcular_valor_total(int total_produtos) {
    for (int i = 0; i < MAX_PRODUTOS ; i++) {
        
        valor_total += quantidade_estoque[i] * valor_unitario[i];
    }
    printf("Valor total dos produtos em estoque: R$%.2f\n", valor_total);
}


int main() {
    int total_produtos = 0;
    int opcao;

    while (true) {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Retirar produto do estoque\n");
        printf("3. Mostrar produtos abaixo do estoque mínimo\n");
        printf("4. Calcular valor total do estoque\n");
        printf("5. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_produto(&total_produtos);
                break;
            case 2:
                retirar_produto(total_produtos);
                break;
            case 3:
                mostrar_produtos_abaixo_minimo(total_produtos);
                break;
            case 4:
                calcular_valor_total(total_produtos);
                break;
            case 5:
                printf("Saindo do sistema. Até mais!\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}