#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

int eh_uma_arvore_de_pesquisa(node *arvore);

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

    if(eh_uma_arvore_de_pesquisa(arvore))
        puts("É uma árvore de pesquisa!");
    else
        puts("Não é uma árvore de pesquisa!");

    return 0;
}

int eh_uma_arvore_de_pesquisa(node *arvore)
{
    if(arvore == NULL)
        return 1;

    if(arvore->E && arvore->E->chave > arvore->chave)
        return 0;

    if(eh_uma_arvore_de_pesquisa(arvore->E) == 0)
        return 0;

    if(arvore->D && arvore->D->chave < arvore->chave)
        return 0;

    return eh_uma_arvore_de_pesquisa(arvore->D);
}
