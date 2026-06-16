#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *ptrProduto, float percentual) {
    ptrProduto->preco = ptrProduto->preco * (1.0 - percentual / 100.0);
}

int main() {
    Produto produto = {1, 100.0};

    printf("Produto ID: %d\n", produto.id);
    printf("Preco original: R$ %.2f\n", produto.preco);

    aplicar_desconto(&produto, 10.0);

    printf("Preco depois do desconto de 10%%: R$ %.2f\n", produto.preco);

    return 0;
}