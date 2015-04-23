#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

node * criar_arvore_balanceada(int *n, int quantidade);
int eh_avl(node *arvore);
int altura_da_arvore(node *arvore);
int abs(int numero);
void imprimir(node *arvore, int nivel);

int main()
{
    int quantidade = 15, i;
    int *n = malloc(sizeof(int) * quantidade);

    for(i = 0; i < quantidade; i++)
        n[i] = i + 1;

    node *arvore = criar_arvore_balanceada(n, quantidade);
    printf("eh avl: %i\n\n", eh_avl(arvore));
    imprimir(arvore, 0);

    return 0;
}

void imprimir(node *arvore, int nivel)
{
    int i;

    if(arvore == NULL)
        return;

    imprimir(arvore->D, nivel + 1);
    for(i = 0; i < nivel; i++){
        printf("       ");
    }
    printf("  ----> %i\n", arvore->chave);

    imprimir(arvore->E, nivel + 1);
}


node * criar_arvore_balanceada(int *n, int quantidade)
{
    if(quantidade == 0)
        return NULL;

    node *arvore;
    int posicaoDoMeio;
    int *vetorDaArvoreEsquerda, quantidadeDaArvoreEsquerda;
    int *vetorDaArvoreDireita, quantidadeDaArvoreDireita;

    posicaoDoMeio = (quantidade / 2) + 1;

    vetorDaArvoreEsquerda = n;
    quantidadeDaArvoreEsquerda = posicaoDoMeio - 1;
    vetorDaArvoreDireita = n + posicaoDoMeio;
    quantidadeDaArvoreDireita = quantidade - 1 - quantidadeDaArvoreEsquerda;

    arvore = malloc(sizeof(node));
    arvore->chave = *(n + (posicaoDoMeio - 1));
    arvore->E = criar_arvore_balanceada(vetorDaArvoreEsquerda, quantidadeDaArvoreEsquerda);
    arvore->D = criar_arvore_balanceada(vetorDaArvoreDireita, quantidadeDaArvoreDireita);

    return arvore;
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
