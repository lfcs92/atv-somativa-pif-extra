#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *ptrProduto, float percentual) {
    ptrProduto->preco = ptrProduto->preco * (1.0 - percentual / 100.0);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    printf("%-5s %-10s\n", "ID", "Preco");
    printf("---------------------\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%-5d R$ %.2f\n", (ptr + i)->id, (ptr + i)->preco);
    }
    printf("---------------------\n");
}

int main() {
    Produto estoque[3] = {
        {1, 100.0},
        {2, 250.0},
        {3, 399.9}
    };

    int quantidade = 3;

    printf("=== Estoque original ===\n");
    imprimir_produtos(estoque, quantidade);
    
    for (int i = 0; i < quantidade; i++) {
        aplicar_desconto(estoque + i, 10.0);
    }

    printf("\n=== Estoque apos desconto de 10%% ===\n");
    imprimir_produtos(estoque, quantidade);

    return 0;
}