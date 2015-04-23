#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

int soma_arvore(node *arvore);
node * maior_chave(node *arvore);
int altura_da_arvore(node *arvore);
int numero_de_nodos_folhas(node *arvore);
int nivel_de_um_nodo(node *arvore, int chave);
node * pai_de_um_nodo(node *arvore, int chave);
int eh_uma_arvore_de_pesquisa(node *arvore);


int main()
{
    node *arvore;

    inserir_chave(&arvore, 10);
    inserir_chave(&arvore, 13);
    inserir_chave(&arvore, 9);
    inserir_chave(&arvore, 5);
    inserir_chave(&arvore, 70);
    inserir_chave(&arvore, 3);
    inserir_chave(&arvore, 7);
    inserir_chave(&arvore, 50);
    inserir_chave(&arvore, 30);

    printf("soma: %i\n", soma_arvore(arvore));
    printf("maior: %i\n", maior_chave(arvore)->chave);
    printf("altura da árvore: %i\n", altura_da_arvore(arvore));
    printf("número de nodos folhas: %i\n", numero_de_nodos_folhas(arvore));
    printf("nível do nodo 70: %i\n", nivel_de_um_nodo(arvore, 70));
    printf("nível do nodo 9: %i\n", nivel_de_um_nodo(arvore, 9));
    printf("nível do nodo 3: %i\n", nivel_de_um_nodo(arvore, 3));
    printf("nível do nodo 30: %i\n", nivel_de_um_nodo(arvore, 30));
    printf("nível de um nodo inexistente: %i\n", nivel_de_um_nodo(arvore, 465));
    printf("pai do nodo raiz: %p\n", pai_de_um_nodo(arvore, 10));
    printf("pai do nodo 9: %i\n", pai_de_um_nodo(arvore, 9)->chave);
    printf("pai do nodo 30: %i\n", pai_de_um_nodo(arvore, 30)->chave);
    
    if(eh_uma_arvore_de_pesquisa(arvore))
        puts("É uma árvore de pesquisa!");
    else
        puts("Não é uma árvore de pesquisa!");

    return 0;
}

// ex1: Dada uma árvore binária, apontada por T, implemente em C ou pseudocódigo funções para retornar:

// a) A soma dos valores de todas as chaves.

int soma_arvore(node *arvore)
{
    if(arvore == NULL)
        return 0;

    return arvore->chave + soma_arvore(arvore->E) + soma_arvore(arvore->D);
}

// b) Um ponteiro para nodo que possui a maior chave.

node * maior_chave(node *arvore)
{
    node *maiorDaEsquerda, *maiorDaDireita, *maior;

    if(arvore == NULL)
        return NULL;

    maiorDaEsquerda = maior_chave(arvore->E);
    maiorDaDireita = maior_chave(arvore->D);

    if(maiorDaEsquerda == NULL && maiorDaDireita == NULL)
        return arvore;

    if(maiorDaEsquerda == NULL)
        return arvore->chave > maiorDaDireita->chave ? arvore : maiorDaDireita;

    if(maiorDaDireita == NULL)
        return arvore->chave > maiorDaEsquerda->chave ? arvore : maiorDaEsquerda;

    maior = maiorDaEsquerda->chave > maiorDaDireita->chave ? maiorDaEsquerda : maiorDaDireita;

    return arvore->chave > maior->chave ? arvore : maior;
}

// c) A altura da árvore.

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

// d) O número de nodos folhas.

int numero_de_nodos_folhas(node *arvore)
{
    int numeroDeNodosFolhaDaArvoreEsquerda, numeroDeNodosFolhaDaArvoreDireita;

    if(arvore == NULL)
        return 0;

    numeroDeNodosFolhaDaArvoreEsquerda = numero_de_nodos_folhas(arvore->E);
    numeroDeNodosFolhaDaArvoreDireita = numero_de_nodos_folhas(arvore->D);

    if(numeroDeNodosFolhaDaArvoreEsquerda == 0 && numeroDeNodosFolhaDaArvoreDireita == 0)
        return 1;

    return numeroDeNodosFolhaDaArvoreEsquerda + numeroDeNodosFolhaDaArvoreDireita;
}

// e) O nível de um nodo N.

int nivel_de_um_nodo(node *arvore, int chave)
{
    int nivelNoLadoEsquerdo, nivelNoLadoDireito;

    if(arvore == NULL)
        return -1;

    if(arvore->chave == chave)
        return 0;

    nivelNoLadoEsquerdo = nivel_de_um_nodo(arvore->E, chave);
    if(nivelNoLadoEsquerdo >= 0)
        return nivelNoLadoEsquerdo + 1;

    nivelNoLadoDireito = nivel_de_um_nodo(arvore->D, chave);
    if(nivelNoLadoDireito >= 0)
        return nivelNoLadoDireito + 1;

    return -1;
}

// f) O nodo pai de um nodo N.

node * pai_de_um_nodo(node *arvore, int chave)
{
    node *paiDoNodo;

    if(arvore == NULL)
        return NULL;

    if(arvore->E && arvore->E->chave == chave)
        return arvore;

    if(arvore->D && arvore->D->chave == chave)
        return arvore;

    paiDoNodo = pai_de_um_nodo(arvore->E, chave);
    if(paiDoNodo != NULL)
        return paiDoNodo;

    return pai_de_um_nodo(arvore->D, chave);
}

// g) Verdadeiro se T for uma árvore binária de pesquisa, ou falso, caso contrário.

int eh_uma_arvore_de_pesquisa(node *arvore)
{
    if(arvore == NULL)
        return 1;

    if(eh_uma_arvore_de_pesquisa(arvore->E) == 0)
        return 0;

    if(arvore->E && arvore->E->chave > arvore->chave)
        return 0;

    if(eh_uma_arvore_de_pesquisa(arvore->D) == 0)
        return 0;

    if(arvore->D && arvore->D->chave < arvore->chave)
        return 0;

    return 1;
}
