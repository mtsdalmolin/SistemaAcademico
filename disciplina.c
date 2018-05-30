#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "disciplina.h"

bool codigo_igual(Disciplina* lista_disciplinas, int codigo)
{
	Disciplina* aux;
	for (aux = lista_disciplinas; aux != NULL; aux = aux->prox)
		if (aux->codigo == codigo)
			return true;
	return false;
}

Disciplina* cria_lista_disciplinas()
{
	return NULL;
}

Disciplina* insere_disciplina(Disciplina* lista_disciplinas, int codigo, int carga_horaria, char* curso, char* nome, Lista_Prerrequisitos* lista_prerrequisitos)
{
	Disciplina* aux;
	Disciplina* ant = NULL;
	Lista_Prerrequisitos* aux2;
	Disciplina* nova_disciplina = (Disciplina*) malloc(sizeof(Disciplina));
	nova_disciplina->codigo = codigo;
	nova_disciplina->carga_horaria = carga_horaria;
	strcpy(nova_disciplina->curso, curso);
	strcpy(nova_disciplina->nome, nome);
	nova_disciplina->prerrequisitos = NULL;

	if (lista_prerrequisitos != NULL)
		for (aux2 = lista_prerrequisitos; aux2 != NULL; aux2 = aux2->prox)
			nova_disciplina->prerrequisitos = inserir_prerrequisito(nova_disciplina, lista_disciplinas, aux2->codigo);

	if (lista_disciplinas == NULL)
		nova_disciplina->prox = lista_disciplinas;
	else
	{
		for (aux = lista_disciplinas; aux != NULL; aux = aux->prox)
		{
			if (aux->codigo > codigo)
				break;
			ant = aux;
		}
		if (ant == NULL)
		{
			lista_disciplinas = nova_disciplina;
			nova_disciplina->prox = aux;
		} else {
			ant->prox = nova_disciplina;
			nova_disciplina->prox = aux;
			return lista_disciplinas;
		}
	}
	return nova_disciplina;
}

Disciplina* exclui_disciplina(Disciplina* lista_disciplinas, int codigo)
{
	Disciplina* aux;
	Disciplina* ant = NULL;
	for (aux = lista_disciplinas; aux != NULL; aux = aux->prox)
	{
		if (aux->codigo == codigo)
		{
			if (ant == NULL)
			{
				lista_disciplinas = aux->prox;
				break;
			} else {
				ant->prox = aux->prox;
				break;
			}
		}
		ant = aux;
	}
	printf("\nDisciplina de %s removido do sistema!\n", aux->nome);
	free(aux);
	return lista_disciplinas;
}

Disciplina* busca_disciplina(Disciplina* lista_disciplinas, int codigo)
{
	Disciplina* aux;
	for (aux = lista_disciplinas; aux != NULL; aux = aux->prox)
		if (aux->codigo == codigo)
			return aux;
	return NULL;
}

void imprime_dados_disciplina(Disciplina* disciplina_alvo)
{
	printf("----------DISCIPLINA----------\nNome: %s\nCodigo: %d\nCurso: %s\nCarga horaria (horas): %d\n", disciplina_alvo->nome, disciplina_alvo->codigo, disciplina_alvo->curso, disciplina_alvo->carga_horaria);
}

void imprime_lista_disciplinas(Disciplina* lista_disciplinas)
{
	Disciplina* aux;
	Prerrequisito* aux2;
	for (aux = lista_disciplinas; aux != NULL; aux = aux->prox)
	{
		imprime_dados_disciplina(aux);
		for(aux2 = aux->prerrequisitos; aux2 != NULL; aux2 = aux2->prox)
			printf("\t----------PRERREQUISITO----------\n\tNome: %s\n\tCodigo: %d\n\tCurso: %s\n\tCarga horaria (horas): %d\n", aux2->disc->nome, aux2->disc->codigo, aux2->disc->curso, aux2->disc->carga_horaria);
	}
}

Disciplina* cadastro_disciplina(Disciplina* lista_disciplinas)
{
	int codigo_disciplina;
	int carga_horaria;
	int codigo_prerrequisito;
	char curso_disciplina[50];
	char nome[50];
	char confirma_prerrequisito;
	char outro_prerrequisito;
	Disciplina* verifica_disciplina;
	Lista_Prerrequisitos* lista_prerrequisitos = NULL;

	do
	{
		printf("Informe o codigo da disciplina (apenas numeros):\n");
		scanf("%d", &codigo_disciplina);
		if (codigo_igual(lista_disciplinas, codigo_disciplina))
			printf("Codigo invalido! Digite um novo codigo para a disciplina!\n");
	} while (codigo_igual(lista_disciplinas, codigo_disciplina));

	fflush(stdin);
	printf("Nome da disciplina:\n");
	gets(nome);
	printf("Carga horaria da disciplina (horas):\n");
	scanf("%d", &carga_horaria);
	fflush(stdin);
	printf("Curso da disciplina:\n");
	gets(curso_disciplina);

	if (lista_disciplinas != NULL)
		do
		{
			printf("A disciplina apresenta prerrequisitos? (s/n)\n");
			scanf(" %c", &confirma_prerrequisito);
			if (toupper(confirma_prerrequisito) != 'S' && toupper(confirma_prerrequisito) != 'N')
				printf("Entrada invalida! Digite novamente!\n");
		} while (toupper(confirma_prerrequisito) != 'S' && toupper(confirma_prerrequisito) != 'N');
	
	while (toupper(confirma_prerrequisito) == 'S')
	{
		printf("Digite o codigo do prerrequisito:\n");
		scanf("%d", &codigo_prerrequisito);
		verifica_disciplina = busca_disciplina(lista_disciplinas, codigo_prerrequisito);
		if (verifica_disciplina == NULL)
			printf("Codigo da disciplina nao cadastrado no sistema!\n");
		else
			lista_prerrequisitos = adicionar_prerrequisito_lista(lista_prerrequisitos, codigo_prerrequisito);
		printf("A disciplina tem mais algum prerrequisito?\n");
		scanf(" %c", &confirma_prerrequisito);
	}

	lista_disciplinas = insere_disciplina(lista_disciplinas, codigo_disciplina, carga_horaria, curso_disciplina, nome, lista_prerrequisitos);

	//libera_lista_prerrequisitos(lista_prerrequisitos);
	
	imprime_lista_disciplinas(lista_disciplinas);

	return lista_disciplinas;
}

Prerrequisito* inserir_prerrequisito(Disciplina* nova_disciplina, Disciplina* lista_disciplinas, int codigo_prerrequisito)
{
	Prerrequisito* novo_prerrequisito = (Prerrequisito*) malloc(sizeof(Prerrequisito));
	novo_prerrequisito->disc = busca_disciplina(lista_disciplinas, codigo_prerrequisito);
	novo_prerrequisito->prox = nova_disciplina->prerrequisitos;
	return novo_prerrequisito;
}

Lista_Prerrequisitos* adicionar_prerrequisito_lista(Lista_Prerrequisitos* lista_prerrequisitos, int codigo)
{
	Lista_Prerrequisitos* novo_elemento = (Lista_Prerrequisitos*) malloc(sizeof(Lista_Prerrequisitos));
	novo_elemento->codigo = codigo;
	novo_elemento->prox = lista_prerrequisitos;
	return novo_elemento;
}

void libera_lista_prerrequisitos(Lista_Prerrequisitos* lista_prerrequisitos)
{
	Lista_Prerrequisitos* aux;
	Lista_Prerrequisitos* temp;
	for (aux = lista_prerrequisitos; aux != NULL; aux = aux->prox)
	{
		temp = aux;
		temp->prox = aux->prox;
		//aux = aux->prox;
		printf("Liberando %d da lista de prerrequisitos.\n", temp->codigo);
		free(temp);
	}
}

void imprime_disciplinas_sem_prerrequisitos(Disciplina* lista_disciplinas)
{
	Disciplina* aux;
	for (aux = lista_disciplinas; aux != NULL; aux = aux->prox)
		imprime_dados_disciplina(aux);
}