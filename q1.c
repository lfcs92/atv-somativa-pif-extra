#include <stdio.h>

int main() {    
    float preco = 100.0;
    
    float *ptrPreco = &preco;    
    
    printf("Preco original: R$ %.2f\n", preco);

    *ptrPreco= *ptrPreco * 1.10;
    
    printf("Preco depois do aumento de 10%%: R$ %.2f\n", preco);    

    return 0;
}