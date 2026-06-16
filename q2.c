#include <stdio.h>

void aplicar_desconto(float *ptrPreco, float percentual) {
    *ptrPreco = *ptrPreco * (1.0 - percentual / 100.0);
}

int main() {
    float preco = 100.0;

    printf("Preco original: R$ %.2f\n", preco);

    aplicar_desconto(&preco, 10.0);

    printf("Preco depois do desconto de 10%%: R$ %.2f\n", preco);

    return 0;
}