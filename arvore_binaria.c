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

int main(int argc, char const *argv[])
{
    arvore minhaArvore;
    printf("Tamanho: %d \n", tamanho(minhaArvore));
    printf("Altura: %d \n", altura(minhaArvore));

    return 0;
}