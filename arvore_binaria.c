#include "arvore_binaria.h"
#include <stdlib.h>


static node * new_node(int chave)
{
    node *node;

    node = malloc(sizeof(node));
    if(node == NULL)
        return NULL;

    node->E = NULL;
    node->D = NULL;
    node->chave = chave;

    return node;
}

static int free_node(node * node)
{
    node->E = NULL;
    node->D = NULL;
    // node->chave = 0;
    free(node);

    return TREE_SUCCESS;
}

int inserir_chave(node **arvore, int chave)
{
    if(*arvore == NULL)
    {
        *arvore = new_node(chave);
        return TREE_SUCCESS;
    }

    // se já existe a chave retorna um erro
    if((*arvore)->chave == chave)
        return TREE_ERROR;

    // inserir na árvore esquerda
    if(chave < (*arvore)->chave)
        return inserir_chave(&(*arvore)->E, chave);

    // inserir na árvore direita
    return inserir_chave(&(*arvore)->D, chave);
}

int excluir_chave(node **root, int chave)
{

}
