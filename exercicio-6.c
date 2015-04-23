#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

int eh_avl(node *arvore);
int altura_da_arvore(node *arvore);
int abs(int numero);

int main()
{
    node *arvore;

    inserir_chave(&arvore, 10);
    inserir_chave(&arvore, 13);
    inserir_chave(&arvore, 8);
    inserir_chave(&arvore, 9);
    inserir_chave(&arvore, 5);
    inserir_chave(&arvore, 70);
    inserir_chave(&arvore, 3);
    inserir_chave(&arvore, 7);
    // inserir_chave(&arvore, 1);
    // inserir_chave(&arvore, 50);
    // inserir_chave(&arvore, 30);

    if(eh_avl(arvore))
        puts("É uma árvore AVL!");
    else
        puts("Não é uma árvore AVL!");

    return 0;
}

int eh_avl(node *arvore)
{
    int alturaDaArvoreEsquerda, alturaDaArvoreDireita;

    if(arvore == NULL)
        return 1;

    alturaDaArvoreEsquerda = altura_da_arvore(arvore->E);
    alturaDaArvoreDireita = altura_da_arvore(arvore->D);

    if(abs(alturaDaArvoreDireita - alturaDaArvoreEsquerda) > 1)
        return 0;

    if(eh_avl(arvore->E) == 0)
        return 0;

    return eh_avl(arvore->D);
}

int altura_da_arvore(node *arvore)
{
    int alturaDaArvoreEsquerda, alturaDaArvoreDireita, maior;

    if(arvore == NULL)
        return -1;

    alturaDaArvoreEsquerda = altura_da_arvore(arvore->E) + 1;
    alturaDaArvoreDireita = altura_da_arvore(arvore->D) + 1;

    maior = (alturaDaArvoreDireita > alturaDaArvoreEsquerda) ? alturaDaArvoreDireita : alturaDaArvoreEsquerda;

    return maior;
}

int abs(int numero)
{
    return numero < 0 ? -numero : numero;
}
