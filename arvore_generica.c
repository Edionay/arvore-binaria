#include <stdlib.h>
#include <stdio.h>

typedef struct registro
{
    int chave;
    struct registro *pai;
    struct registro *filho;
    struct registro *irmao;
} celula;

typedef celula *arvore;

arvore retornaPai(arvore raiz)
{
    return raiz->pai;
}

int ehRaiz(arvore raiz)
{
    // Verifica se o pai é nulo
    if (retornaPai(raiz) == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ehFolha(arvore raiz)
{
    // Verifica a lista de filhos
    // Se é vazia, então é folha
    if (raiz->filho == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

arvore construirArvore(int chave)
{
    arvore raiz;
    raiz = (arvore)malloc(sizeof(celula));
    raiz->pai = NULL;
    raiz->chave = chave;
    raiz->filho = NULL;
    raiz->irmao = NULL;
    return raiz;
}

// Adiciona um filho ao nó raiz
void criarFilho(arvore raiz, int chave)
{
    arvore filho;
    filho = (arvore)malloc(sizeof(celula));
    filho->pai = raiz;
    filho->chave = chave;
    filho->filho = NULL;
    filho->irmao = raiz->filho;
    raiz->filho = filho;
}

int numeroDeFilhos(arvore raiz)
{
    int totalDeFilhos = 0;
    if (raiz != NULL)
    {
        raiz = raiz->filho;
        if (raiz->filho != NULL)
        {
            totalDeFilhos++;
        }
        while (raiz->irmao != NULL)
        {
            totalDeFilhos++;
            raiz = raiz->irmao;
        }
    }
    return totalDeFilhos;
}

arvore kEsimoFilho(arvore raiz, int k)
{
    if (k < 0 || k > (numeroDeFilhos(raiz)))
    {
        return NULL;
    }
    raiz = raiz->filho;

    for (int i = 1; i < k; i++)
    {
        raiz = raiz->irmao;
    }
    return raiz;
}

void inserir(arvore raiz, int chave)
{
    arvore filho;
    filho = (arvore)malloc(sizeof(celula));
    filho->pai = raiz;
    filho->chave = chave;
    filho->filho = NULL;
    filho->irmao = raiz->filho;
    raiz->filho = filho;
}

int profundidade(arvore raiz)
{
    if (raiz == NULL || raiz->pai == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + profundidade(raiz->pai);
    }
}

int profundidadeSemRecursao(arvore raiz)
{
    int profundidade = 0;
    if (raiz != NULL)
    {
        while (raiz->pai != NULL)
        {
            profundidade++;
            raiz = raiz->pai;
        }
    }
    return profundidade;
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("Hello, world!");

    arvore minhaArvore;
    minhaArvore = construirArvore(10);
    // criarFilho(minhaArvore, 2);
    // criarFilho(minhaArvore, 4);
    // criarFilho(minhaArvore, 6);

    arvore filhoQualquer = kEsimoFilho(minhaArvore, 1);
    // printf("K-ésimo filho: %d", filhoQualquer->chave);
    printf("Número de filhos: %d", numeroDeFilhos(minhaArvore));

    return 0;
}
