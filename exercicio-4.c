#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

int arvore_eh_estritamente_binaria(node *arvore);

int main()
{
    node *arvore;

    inserir_chave(&arvore, 10);
    inserir_chave(&arvore, 13);
    inserir_chave(&arvore, 8);
    inserir_chave(&arvore, 9);
    inserir_chave(&arvore, 5);
    // inserir_chave(&arvore, 70);
    // inserir_chave(&arvore, 3);
    // inserir_chave(&arvore, 7);
    // inserir_chave(&arvore, 50);
    // inserir_chave(&arvore, 30);

    if(arvore_eh_estritamente_binaria(arvore))
        puts("A árvore é estritamente binaria!");
    else
        puts("A árvore não é esritamente binária!");

    return 0;
}

int arvore_eh_estritamente_binaria(node *arvore)
{
    if(arvore == NULL)
        return 1;

    if((!arvore->E && arvore->D) || (arvore->E && !arvore->D))
        return 0;

    if(arvore_eh_estritamente_binaria(arvore->E) == 0)
        return 0;

    if(arvore_eh_estritamente_binaria(arvore->D) == 0)
        return 0;

    return 1;
}
