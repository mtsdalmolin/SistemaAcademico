#include <stdio.h>
#include <stdbool.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"

bool aluno_matriculado_turma(Turma* lista_turmas, Aluno* aluno_alvo)
{
	Turma* aux;
	for (aux = lista_turmas; aux != NULL; aux = aux->prox)
		if (aluno_alvo->matricula == aux->alunos->aluno->matricula)
			return true;
	return false;
}

bool professor_matriculado_turma(Turma* lista_turmas, Professor* professor_alvo)
{
	Turma* aux;
	for (aux = lista_turmas; aux != NULL; aux = aux->prox)
		if (professor_alvo->siape == aux->professores->professor->siape)
			return true;
	return false;
}

bool disciplina_vinculada_turma(Turma* lista_turmas, Disciplina* disciplina_alvo)
{
	Turma* aux;
	for (aux = lista_turmas; aux != NULL; aux = aux->prox)
		if (disciplina_alvo->codigo == aux->disciplina->codigo)
			return true;
	return false;
}