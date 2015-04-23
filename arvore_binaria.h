#define TREE_SUCCESS 0
#define TREE_ERROR 1


typedef struct node {
    struct node *E;
    struct node *D;
    int chave;
} node;


int inserir_chave(node **arvore, int chave);
// int tree_search();
int excluir_chave(node **arvore, int chave);
