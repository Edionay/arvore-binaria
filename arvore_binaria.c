#include <stdio.h>

typedef struct registro 
{
    int chave;
    struct registro *esquerdo;
    struct registro *direito;    
} celula;

typedef celula *arvore;

// Complexidade de tempo Θ(n) e de espaço Θ(h)
int tamanho(arvore raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        return tamanho(raiz->esquerdo) + 1 + tamanho(raiz->direito);
    }    
}

// Complexidade de tempo Θ(n) e de espaço Θ(h)
int altura(arvore raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int alturaEsquerda = altura(raiz->esquerdo);
        int alturaDireita = altura(raiz->direito);
        if (alturaEsquerda < alturaDireita)
        {
            return alturaDireita + 1;
        }
        else
        {
            return alturaEsquerda + 1;
        }     
    }
}

// 1. Visitar a raiz
// 2. Percorrer sua subárvore esquerda em pré-ordem
// 3. Visitar a subárvore direita em pré-ordem
void preOrdem(arvore raiz)
{
    if (raiz != NULL)
    {
        printf("%d \n", raiz->chave);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

// 1. Percorrer sua subárvore esquerda em em-ordem
// 2. Visitar a raiz
// 3. Visitar a subárvore direita em em-ordem
void emOrdem(arvore raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerdo);
        printf("%d \n", raiz->chave);
        emOrdem(raiz->direito);
    }
}

// Teste de execução
int main(int argc, char const *argv[])
{
    arvore minhaArvore;

    printf("Tamanho: %d \n", tamanho(minhaArvore));
    printf("Altura: %d \n", altura(minhaArvore));

    preOrdem(minhaArvore);
    emOrdem(minhaArvore);

    return 0;
}