#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"
#include "aula.h"

Aula* cria_lista_aulas()
{
	return NULL;
}

Aula* insere_aula(Aula* lista_aulas, Data* data_aula, char* conteudo_ministrado)
{
	Aula* aux;
	Aula* ant = NULL;
	Aula* nova_aula = (Aula*) malloc(sizeof(Aula));
	nova_aula->data_aula.dia = data_aula->dia;
	nova_aula->data_aula.mes = data_aula->mes;
	nova_aula->data_aula.ano = data_aula->ano;
	strcpy(nova_aula->conteudo_ministrado, conteudo_ministrado);
	
	if (lista_aulas == NULL)
		nova_aula->prox = lista_aulas;
	else
	{
		for (aux = lista_aulas; aux != NULL; aux = aux->prox)
		{
			if (aux->data_aula.ano > data_aula->ano)
				break;
			ant = aux;
		}
		if (ant == NULL)
		{
			lista_aulas = nova_aula;
			nova_aula->prox = aux;
		} else {
			ant->prox = nova_aula;
			nova_aula->prox = aux;
			return lista_aulas;
		}
	}
	return nova_aula;
}

Aula* exclui_aula(Aula* lista_aulas, Data* data_aula)
{
	Aula* aux;
	Aula* ant = NULL;
	for (aux = lista_aulas; aux != NULL; aux = aux->prox)
	{
		if (aux->data_aula.dia == data_aula->dia && aux->data_aula.mes == data_aula->mes && aux->data_aula.ano == data_aula->ano)
		{
			if (ant == NULL)
			{
				lista_aulas = aux->prox;
				break;
			} else {
				ant->prox = aux->prox;
				break;
			}
		}
		ant = aux;
	}
	printf("Aula sobre %s do dia %d/%d/%d removida do sistema!\n", aux->conteudo_ministrado, aux->data_aula.dia, aux->data_aula.mes, aux->data_aula.ano);
	free(aux);
	return lista_aulas;
}

void tira_presenca(Turma* turma_alvo)
{
	AlunoTurma* aux;
	for (aux = turma_alvo->alunos; aux != NULL; aux = aux->prox)
		aux->num_presencas--;
}

void presenca_alunos(Aula* aula_alvo, Turma* turma_alvo)
{
	char confirmacao;
	AlunoTurma* aux;
	for (aux = turma_alvo->alunos; aux != NULL; aux = aux->prox)
	{
		do
		{
			printf("Aluno %s estava presente na aula sobre %s do dia %d/%d/%d? (s/n)\n", aux->aluno->nome, aula_alvo->conteudo_ministrado, aula_alvo->data_aula.dia, aula_alvo->data_aula.mes, aula_alvo->data_aula.ano);
			scanf(" %c", &confirmacao);
			if (toupper(confirmacao) != 'S' && toupper(confirmacao) != 'N')
				printf("Entrada invalida!\n");
		} while (toupper(confirmacao) != 'S' && toupper(confirmacao) != 'N');
		if (toupper(confirmacao) == 'S')
			aux->num_presencas++;
	}
}

void imprime_dados_aula(Aula* aula_alvo)
{
	printf("----------AULA----------\nData: %d/%d/%d\nConteudo ministrado: %s\n", aula_alvo->data_aula.dia, aula_alvo->data_aula.mes, aula_alvo->data_aula.ano, aula_alvo->conteudo_ministrado);
}

Aula* busca_aula(Aula* lista_aulas, Data* data_aula)
{
	Aula* aux;
	for (aux = lista_aulas; aux != NULL; aux = aux->prox)
		if (aux->data_aula.dia == data_aula->dia && aux->data_aula.mes == data_aula->mes && aux->data_aula.ano == data_aula->ano)
			return aux;
	return NULL;
}

void imprime_lista_aulas(Aula* lista_aulas)
{
	Aula* aux;
	for (aux = lista_aulas; aux != NULL; aux = aux->prox)
		imprime_dados_aula(aux);
}

Aula* cadastro_aula(Turma* turma_alvo)
{
	int codigo_turma;
	char conteudo_ministrado[50];
	Data data_aula;
	Aula* aula_alvo;

	printf("Inserindo uma aula na turma %d!\n", turma_alvo->numero);
	do
	{
		printf("Informe a data da aula:\nDia: ");
		scanf("%d", &data_aula.dia);
		if (data_aula.dia <= 0 || data_aula.dia > 31)
			printf("Dia invalido!\n");
	} while (data_aula.dia <= 0 || data_aula.dia > 31);
	do
	{
		printf("Mes: ");
		scanf("%d", &data_aula.mes);
		if (data_aula.mes <= 0 || data_aula.mes > 12)
			printf("Mes invalido!\n");
	} while (data_aula.mes <= 0 || data_aula.mes > 31);

	do
	{
		printf("Ano: ");
		scanf("%d", &data_aula.ano);
		if (data_aula.ano <= 0 || data_aula.ano > 2018)
			printf("Ano invalido!\n");
	} while (data_aula.ano <= 0 || data_aula.ano > 2018);

	fflush(stdin);
	printf("Conteudo ministrado:\n");
	gets(conteudo_ministrado);

	turma_alvo->aulas = insere_aula(turma_alvo->aulas, &data_aula, conteudo_ministrado);

	aula_alvo = busca_aula(turma_alvo->aulas, &data_aula);
	presenca_alunos(aula_alvo, turma_alvo);

	return turma_alvo->aulas;
}