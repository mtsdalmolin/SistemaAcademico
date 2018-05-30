#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "professor.h"

bool siape_igual(Professor* lista_professores, int siape)
{
	Professor* aux;
	for (aux = lista_professores; aux != NULL; aux = aux->prox)
		if (aux->siape == siape)
			return true;
	return false;
}

Professor* cria_lista_professores()
{
	return NULL;
}

Professor* insere_professor(Professor* lista_professores, int siape, char* titulacao, char* nome, char* area_atuacao)
{
	Professor* aux;
	Professor* ant = NULL;
	Professor* novo_professor = (Professor*) malloc(sizeof(Professor));
	novo_professor->siape = siape;
	strcpy(novo_professor->titulacao, titulacao);
	strcpy(novo_professor->nome, nome);
	strcpy(novo_professor->area_atuacao, area_atuacao);
	if (lista_professores == NULL)
		novo_professor->prox = lista_professores;
	else
	{
		for (aux = lista_professores; aux != NULL; aux = aux->prox)
		{
			if (aux->siape > siape)
				break;
			ant = aux;
		}
		if (ant == NULL)
		{
			lista_professores = novo_professor;
			novo_professor->prox = aux;
		} else {
			ant->prox = novo_professor;
			novo_professor->prox = aux;
			return lista_professores;
		}
	}
	return novo_professor;
}

Professor* exclui_professor(Professor* lista_professores, int siape)
{
	Professor* aux;
	Professor* ant = NULL;
	for (aux = lista_professores; aux != NULL; aux = aux->prox)
	{
		if (aux->siape == siape)
		{
			if (ant == NULL)
			{
				lista_professores = aux->prox;
				break;
			} else {
				ant->prox = aux->prox;
				break;
			}
		}
		ant = aux;
	}
	printf("\nProfessor %s removido do sistema!\n", aux->nome);
	free(aux);
	return lista_professores;
}

Professor* busca_professor(Professor* lista_professores, int siape)
{
	Professor* aux;
	for (aux = lista_professores; aux != NULL; aux = aux->prox)
		if (aux->siape == siape)
			return aux;
	return NULL;
}

void imprime_dados_professor(Professor* professor_alvo)
{
	printf("----------PROFESSOR----------\nNome: %s\nSiape: %d\nTitulacao: %s\nArea de atuacao: %s\n", professor_alvo->nome, professor_alvo->siape, professor_alvo->titulacao, professor_alvo->area_atuacao);
}

void imprime_lista_professores(Professor* lista_professores)
{
	Professor* aux;
	for (aux = lista_professores; aux != NULL; aux = aux->prox)
		imprime_dados_professor(aux);
}

Professor* cadastro_professor(Professor* lista_professores)
{
	int siape_professor;
	char titulacao[50];
	char area_atuacao[50];
	char nome[50];

	printf("Insira um professor na lista.\n");
	do{
		printf("Informe o seu siape:\n");
		scanf("%d", &siape_professor);
		if (siape_igual(lista_professores, siape_professor))
			printf("Siape ja cadastrado! Digite um novo siape para o professor!\n");
	} while (siape_igual(lista_professores, siape_professor));
	fflush(stdin);
	printf("Titulacao do professor:\n");
	gets(titulacao);
	printf("Nome do professor:\n");
	gets(nome);
	printf("Area de atuacao do professor:\n");
	gets(area_atuacao);
	lista_professores = insere_professor(lista_professores, siape_professor, titulacao, nome, area_atuacao);

	return lista_professores;
}