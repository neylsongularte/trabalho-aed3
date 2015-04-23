#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

void percorre_em_pre_ordem(node *arvore, void (*callback)(int chave));
void percorre_em_ordem(node *arvore, void (*callback)(int chave));
void percorre_em_pos_ordem(node *arvore, void (*callback)(int chave));
void callback(int chave);

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

    printf("Pré ordem: ");
    percorre_em_pre_ordem(arvore, callback);

    printf("\nEm ordem: ");
    percorre_em_ordem(arvore, callback);

    printf("\nPós ordem: ");
    percorre_em_pos_ordem(arvore, callback);

    puts("");

    return 0;
}

void callback(int chave)
{
    printf("%i ", chave);
}

void percorre_em_pre_ordem(node *arvore, void (*callback)(int chave))
{
    if(arvore == NULL)
        return;

    (*callback)(arvore->chave);
    percorre_em_pre_ordem(arvore->E, callback);
    percorre_em_pre_ordem(arvore->D, callback);
}

void percorre_em_ordem(node *arvore, void (*callback)(int chave))
{
    if(arvore == NULL)
        return;

    percorre_em_ordem(arvore->E, callback);
    (*callback)(arvore->chave);
    percorre_em_ordem(arvore->D, callback);
}

void percorre_em_pos_ordem(node *arvore, void (*callback)(int chave))
{
    if(arvore == NULL)
        return;

    percorre_em_pos_ordem(arvore->E, callback);
    percorre_em_pos_ordem(arvore->D, callback);
    (*callback)(arvore->chave);
}
