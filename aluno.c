#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aluno.h"

bool matricula_igual(Aluno* lista_alunos, int matricula)
{
	Aluno* aux;
	for (aux = lista_alunos; aux != NULL; aux = aux->prox)
		if (aux->matricula == matricula)
			return true;
	return false;
}

Aluno* cria_lista_alunos()
{
	return NULL;
}

Aluno* insere_aluno(Aluno* lista_alunos, int matricula, char* curso, char* nome)
{
	Aluno* aux;
	Aluno* ant = NULL;
	Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
	novo_aluno->matricula = matricula;
	strcpy(novo_aluno->curso, curso);
	strcpy(novo_aluno->nome, nome);
	if (lista_alunos == NULL)
		novo_aluno->prox = lista_alunos;
	else
	{
		for (aux = lista_alunos; aux != NULL; aux = aux->prox)
		{
			if (aux->matricula > matricula)
				break;
			ant = aux;
		}
		if (ant == NULL)
		{
			lista_alunos = novo_aluno;
			novo_aluno->prox = aux;
		} else {
			ant->prox = novo_aluno;
			novo_aluno->prox = aux;
			return lista_alunos;
		}
	}
	return novo_aluno;
}

Aluno* exclui_aluno(Aluno* lista_alunos, int matricula)
{
	Aluno* aux;
	Aluno* ant = NULL;
	for (aux = lista_alunos; aux != NULL; aux = aux->prox)
	{
		if (aux->matricula == matricula)
		{
			if (ant == NULL)
			{
				lista_alunos = aux->prox;
				break;
			} else {
				ant->prox = aux->prox;
				break;
			}
		}
		ant = aux;
	}
	printf("\nAluno %s removido do sistema!\n", aux->nome);
	free(aux);
	return lista_alunos;
}

void imprime_dados_aluno(Aluno* aluno_alvo)
{
	printf("----------ALUNO----------\nNome: %s\nMatricula: %d\nCurso: %s\n", aluno_alvo->nome, aluno_alvo->matricula, aluno_alvo->curso);
}

Aluno* busca_aluno(Aluno* lista_alunos, int matricula)
{
	Aluno* aux;
	for (aux = lista_alunos; aux != NULL; aux = aux->prox)
		if (aux->matricula == matricula)
			return aux;
	return NULL;
}

void imprime_lista_alunos(Aluno* lista_alunos)
{
	Aluno* aux;
	for (aux = lista_alunos; aux != NULL; aux = aux->prox)
		imprime_dados_aluno(aux);
}

Aluno* cadastro_aluno(Aluno* lista_alunos)
{
	int matricula_aluno;
	char curso_aluno[50];
	char nome[50];

	printf("Inserindo um aluno no sistema!\n");
	do
	{
		printf("Informe a sua matricula:\n");
		scanf("%d", &matricula_aluno);
		if (matricula_igual(lista_alunos, matricula_aluno))
			printf("Matricula ja cadastrada! Digite uma nova matricula para o aluno!\n");
	} while (matricula_igual(lista_alunos, matricula_aluno));
	fflush(stdin);
	printf("Curso do aluno:\n");
	gets(curso_aluno);
	printf("Nome do aluno:\n");
	gets(nome);
	lista_alunos = insere_aluno(lista_alunos, matricula_aluno, curso_aluno, nome);

	return lista_alunos;
}