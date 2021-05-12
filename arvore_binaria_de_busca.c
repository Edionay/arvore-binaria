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

// Teste de execução
int main(int argc, char const *argv[])
{
    arvore minhaArvore;

	celula *menorCelula = menorChave(minhaArvore);

    // printf("Menor chave: %d \n", &menorCelula->chave);

    printf("Sem erros!");

    return 0;
}