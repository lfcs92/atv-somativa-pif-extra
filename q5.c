#include <stdio.h>
#include <stdlib.h>

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
    int quantidade;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidade);
    
    Produto *estoque = (Produto *) malloc(quantidade * sizeof(Produto));
    
    if (estoque == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return 1;
    }
    
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("ID   : ");
        scanf("%d", &(estoque + i)->id);
        printf("Preco: ");
        scanf("%f", &(estoque + i)->preco);
    }

    printf("\n=== Estoque cadastrado ===\n");
    imprimir_produtos(estoque, quantidade);
    
    for (int i = 0; i < quantidade; i++) {
        aplicar_desconto(estoque + i, 10.0);
    }

    printf("\n=== Estoque apos desconto de 10%% ===\n");
    imprimir_produtos(estoque, quantidade);
    
    free(estoque);
    estoque = NULL;

    return 0;
}