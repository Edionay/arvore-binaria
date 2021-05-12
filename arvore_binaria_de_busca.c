#include <stdio.h>

typedef struct registro
{
	int chave;
	struct registro *esquerdo;
	struct registro *direito;
} celula;

typedef celula *arvore;

// Navega até o nó mais à esquerda da árvore
celula *menorChave(arvore raiz)
{
	if (raiz->esquerdo == NULL)
	{
		return raiz;
	}
	else
	{
		return menorChave(raiz->esquerdo);
	}
}

// Navega até o nó mais à direita da árvore
celula *maiorChave(arvore raiz)
{
	if (raiz->direito == NULL)
	{
		return raiz;
	}
	else
	{
		return maiorChave(raiz->direito);
	}
}

arvore busca(arvore raiz, int chave)
{
	if (raiz == NULL || raiz->chave == chave)
	{
		return raiz;
	}
	if (raiz->chave > chave)
	{
		return busca(raiz->esquerdo, chave);
	}
	else
	{
		return busca(raiz->direito, chave);
	}	
}

arvore inserir(arvore raiz, celula *novoNo)
{
	if (raiz == NULL)
	{
		return novoNo;
	}
	if (raiz->chave > novoNo->chave)
	{
		raiz->esquerdo = inserir(raiz->esquerdo, novoNo);
	}
	else
	{
		raiz->direito = inserir(raiz->direito, novoNo);
	}
	return raiz;	
}

// Teste de execução
int main(int argc, char const *argv[])
{
    arvore minhaArvore;

	celula *menorCelula = menorChave(minhaArvore);

    // printf("Menor chave: %d \n", &menorCelula->chave);

    printf("Sem erros!");

    return 0;
}