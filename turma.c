#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"

Turma* cria_lista_turmas()
{
	return NULL;
}

bool numero_turma_igual(Turma* lista_turmas, int numero_turma)
{
	Turma* aux;
	for (aux = lista_turmas; aux != NULL; aux = aux->prox)
		if (aux->numero == numero_turma)
			return true;
	return false;
}

ProfTurma* insere_professor_turma(Turma* nova_turma, Professor* lista_professores, int siape)
{
	ProfTurma* novo_professor = (ProfTurma*) malloc(sizeof(ProfTurma));
	novo_professor->professor = busca_professor(lista_professores, siape);
	novo_professor->prox = nova_turma->professores;
	return novo_professor;
}

AlunoTurma* insere_aluno_turma(Turma* nova_turma, Aluno* lista_alunos, int matricula)
{
	AlunoTurma* novo_aluno = (AlunoTurma*) malloc(sizeof(AlunoTurma));
	novo_aluno->num_presencas = 0;
	novo_aluno->avaliacao = NULL;
	novo_aluno->aluno = busca_aluno(lista_alunos, matricula);
	novo_aluno->prox = nova_turma->alunos;
	return novo_aluno;
}

Turma* insere_turma(Turma* lista_turmas, int numero_turma, Disciplina* turma_disciplina, ListaProfTurma* professoresT, ListaAlunoTurma* alunosT, Professor* lista_professores, Aluno* lista_alunos)
{
	Turma* aux;
	Turma* ant;
	ListaProfTurma* profAux;
	ListaAlunoTurma* alunoAux;
	Turma* nova_turma = (Turma*) malloc(sizeof(Turma));
	nova_turma->numero = numero_turma;
	nova_turma->numero_aulas = 0;
	nova_turma->disciplina = turma_disciplina;
	nova_turma->professores = NULL;
	nova_turma->alunos = NULL;
	nova_turma->aulas = NULL;

	for (profAux = professoresT; profAux != NULL; profAux = profAux->prox)
		nova_turma->professores = insere_professor_turma(nova_turma, lista_professores, profAux->siape);

	for (alunoAux = alunosT; alunoAux != NULL; alunoAux = alunoAux->prox)
		nova_turma->alunos = insere_aluno_turma(nova_turma, lista_alunos, alunoAux->matricula);

	if (lista_turmas == NULL)
		nova_turma->prox = lista_turmas;
	else
	{
		for (aux = lista_turmas; aux != NULL; aux = aux->prox)
		{
			if (aux->numero > numero_turma)
				break;
			ant = aux;
		}
		if (ant == NULL)
		{
			lista_turmas = nova_turma;
			nova_turma->prox = aux;
		} else {
			ant->prox = nova_turma;
			nova_turma->prox = aux;
			return lista_turmas;
		}
	}
	return nova_turma;
}

Turma* exclui_turma(Turma* lista_turmas, int numero_turma)
{
	Turma* aux;
	Turma* ant = NULL;
	for (aux = lista_turmas; aux != NULL; aux = aux->prox)
	{
		if (aux->numero == numero_turma)
		{
			if (ant == NULL)
			{
				lista_turmas = aux->prox;
				break;
			} else {
				ant->prox = aux->prox;
				break;
			}
		}
		ant = aux;
	}
	printf("Turma %d de %s removida do sistema!\n", aux->numero, aux->disciplina->nome);
	free(aux);
	return lista_turmas;
}

void imprime_dados_turma(Turma* turma_alvo)
{
	printf("----------TURMA----------\nNumero: %d\nDisciplina: %s\n", turma_alvo->numero, turma_alvo->disciplina->nome);
}

void imprime_lista_turmas(Turma* lista_turmas)
{
	int i;
	Turma* turmaAux;
	ProfTurma* profAux;
	AlunoTurma* alunoAux;
	for (turmaAux = lista_turmas; turmaAux != NULL; turmaAux = turmaAux->prox)
	{
		imprime_dados_turma(turmaAux);
		printf("Professores:\n");
		for (profAux = lista_turmas->professores; profAux != NULL; profAux = profAux->prox)
			printf(" %s (%s)\n", profAux->professor->nome, profAux->professor->area_atuacao);
		printf("Alunos:\n");
		for (alunoAux = lista_turmas->alunos, i = 1; alunoAux != NULL; alunoAux = alunoAux->prox, i++)
			printf(" %d. %s\n", i, alunoAux->aluno->nome);
	}
}

Turma* busca_turma(Turma* lista_turmas, int numero_turma)
{
	Turma* aux;
	for (aux = lista_turmas; aux != NULL; aux = aux->prox)
		if (aux->numero == numero_turma)
			return aux;
	return NULL;
}

ListaProfTurma* insere_professor_lista_turma(ListaProfTurma* professoresT, int siape)
{
	ListaProfTurma* novo_professor = (ListaProfTurma*) malloc(sizeof(ListaProfTurma));
	novo_professor->siape = siape;
	novo_professor->prox = professoresT;
	return novo_professor;
}

ListaAlunoTurma* insere_aluno_lista_turma(ListaAlunoTurma* alunosT, int matricula)
{
	ListaAlunoTurma* novo_aluno = (ListaAlunoTurma*) malloc(sizeof(ListaAlunoTurma));
	novo_aluno->matricula = matricula;
	novo_aluno->prox = alunosT;
	return novo_aluno;
}

Turma* cadastro_turma(Turma* lista_turmas, Disciplina* lista_disciplinas, Professor* lista_professores, Aluno* lista_alunos)
{
	int sair = 0;
	int codigo_disciplina;
	int siape_professor;
	int matricula_aluno;
	int turma_numero;
	int limite_turma = 0;
	bool matricular;
	char confirma;
	Disciplina* turma_disciplina = NULL;
	Professor* turma_professor = NULL;
	Aluno* turma_aluno = NULL;
	ListaProfTurma* professoresT = NULL;
	ListaAlunoTurma* alunosT = NULL;
	ListaProfTurma* profAux;
	ListaAlunoTurma* alunoAux;

	printf("Insira uma turma no sistema:\n");
	do
	{
		printf("Informe o numero da turma:\n");
		scanf("%d", &turma_numero);
		if (numero_turma_igual(lista_turmas, turma_numero))
			printf("Numero da turma ja cadastrado! Digite um novo numero para a turma!\n");
	} while (numero_turma_igual(lista_turmas, turma_numero));

	printf("LISTA DE DISCIPLINAS CADASTRADAS NO SISTEMA\n");
	imprime_disciplinas_sem_prerrequisitos(lista_disciplinas);
	printf("Informe o codigo da disciplina da turma:\n");
	do
	{
		scanf("%d", &codigo_disciplina);
		turma_disciplina = busca_disciplina(lista_disciplinas, codigo_disciplina);
		if (turma_disciplina == NULL)
			printf("Disciplina nao cadastrada no sistema! Digite um codigo valido!\n");
	} while (turma_disciplina == NULL);

	do
	{
		matricular = true;
		printf("LISTA DE PROFESSORES CADASTRADOS NO SISTEMA\n");
		imprime_lista_professores(lista_professores);
		do
		{
			printf("Informe o codigo siape do professor da disciplina:\n");
			scanf("%d", &siape_professor);
			turma_professor = busca_professor(lista_professores, siape_professor);
			if (turma_professor == NULL)
			{
				printf("Professor nao cadastrado no sistema! Digite um siape valido!\n");
				matricular = false;
			}
			else if (professor_ja_matriculado(professoresT, siape_professor))
			{
				printf("Professor ja matriculado na turma!\n");
				matricular = false;
			}
		} while (turma_professor == NULL);

		if (matricular)
			professoresT = insere_professor_lista_turma(professoresT, siape_professor);

		do
		{
			printf("A disciplina tem mais algum professor? (s/n)\n");
			scanf(" %c", &confirma);
			if (toupper(confirma) != 'S' && toupper(confirma) != 'N')
				printf("Entrada invalida! Digite novamente!\n");
		} while (toupper(confirma) != 'S' && toupper(confirma) != 'N');
	} while (toupper(confirma) == 'S');

	do
	{
		matricular = true;
		printf("LISTA DE ALUNOS CADASTRADOS NO SISTEMA\n");
		imprime_lista_alunos(lista_alunos);
		do
		{
			printf("Informe a matricula do aluno para inserir na disciplina:\n");
			scanf("%d", &matricula_aluno);
			turma_aluno = busca_aluno(lista_alunos, matricula_aluno);
			if (turma_aluno == NULL)
			{
				printf("Aluno nao cadastrado no sistema! Digite uma matricula valida!\n");
				matricular = false;
			}
			else if (aluno_ja_matriculado(alunosT, matricula_aluno))
			{
				printf("Aluno ja matriculado na turma!\n");
				matricular = false;
			}
		} while (turma_aluno == NULL);

		if (matricular)
		{
			alunosT = insere_aluno_lista_turma(alunosT, matricula_aluno);
			limite_turma++;
		}

		do
		{
			printf("Cadastrar mais alunos na turma? (s/n)\n");
			scanf(" %c", &confirma);
			if (toupper(confirma) != 'S' && toupper(confirma) != 'N')
				printf("Entrada invalida! Digite novamente!\n");
		} while (toupper(confirma) != 'S' && toupper(confirma) != 'N');
	} while (toupper(confirma) == 'S' && limite_turma <= 50);

	lista_turmas = insere_turma(lista_turmas, turma_numero, turma_disciplina, professoresT, alunosT, lista_professores, lista_alunos);

	return lista_turmas;
}

bool aluno_ja_matriculado(ListaAlunoTurma* alunosT, int matricula_aluno)
{
	ListaAlunoTurma* alunoAux;
	for (alunoAux = alunosT; alunoAux != NULL; alunoAux = alunoAux->prox)
		if (alunoAux->matricula == matricula_aluno)
			return true;
	return false;
}

bool professor_ja_matriculado(ListaProfTurma* professoresT, int siape_professor)
{
	ListaProfTurma* profAux;
	for (profAux = professoresT; profAux != NULL; profAux = profAux->prox)
		if (profAux->siape == siape_professor)
			return true;
	return false;
}