// Praticando Struct/Ponteiro

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

Produto produtos[MAX_PRODUTOS];
int contador_produtos = 0;

void inserir_produto();
void listar_produtos();
void comprar_produto();
void finalizar_venda();
void ordenar_produtos(Produto *produtos, int n);

void inserir_produto() {
    if (contador_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novo_produto;
    novo_produto.id = contador_produtos + 1;

    printf("Nome do produto: ");
    scanf(" %[^\n]%*c", novo_produto.nome);
    printf("Descrição do produto: ");
    scanf(" %[^\n]%*c", novo_produto.descricao);
    printf("Preço unitário: ");
    scanf("%f", &novo_produto.preco);
    printf("Quantidade disponível: ");
    scanf("%d", &novo_produto.quantidade);

    produtos[contador_produtos] = novo_produto;
    contador_produtos++;
}

void listar_produtos() {
    ordenar_produtos(produtos, contador_produtos);
    printf("\nLista de produtos:\n");
    for (int i = 0; i < contador_produtos; i++) {
        printf("ID: %d | Nome: %s | Descrição: %s | Preço: %.2f | Quantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao,
               produtos[i].preco, produtos[i].quantidade);
    }
}

void comprar_produto() {
    int id, quantidade;

    printf("Digite o ID ou nome do produto que deseja comprar: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < contador_produtos; i++) {
        if (produtos[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Produto Inexistente\n");
        return;
    }

    printf("Quantos itens deseja comprar?: ");
    scanf("%d", &quantidade);

    if (produtos[index].quantidade < quantidade) {
        printf("Estoque insuficiente\n");
        return;
    }

    produtos[index].quantidade -= quantidade;
    printf("Compra realizada com sucesso!\n");
}

void ordenar_produtos(Produto *produtos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void finalizar_venda() {
    printf("Venda finalizada.\n");
}

int main() {
    int opcao;

    do {
        printf("\n1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("4. Finalizar venda\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir_produto();
                break;
            case 2:
                listar_produtos();
                break;
            case 3:
                comprar_produto();
                break;
            case 4:
                finalizar_venda();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}
