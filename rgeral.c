#include <stdio.h>
#include <stdbool.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"
#include "aula.h"
#include "avaliacao.h"

void gerar_relatorio_geral(Turma* turma_alvo)
{
	int numero_turma;
	float media_notas;
	Aluno* alunoT;
	AlunoTurma* aluno_aux;

	for (aluno_aux = turma_alvo->alunos; aluno_aux != NULL; aluno_aux = aluno_aux->prox)
	{
		media_notas = (aluno_aux->avaliacao->nota1 + aluno_aux->avaliacao->nota2) / 2;
		if (aluno_aux->num_presencas >= 75*(turma_alvo->disciplina->carga_horaria)/100)
		{
			if (media_notas >= 7)
				printf("Nome: %s\tNota 1: %.2f\tNota 2: %.2f\tMedia: %.2f\tSituacao: Aprovado!\n", aluno_aux->aluno->nome, aluno_aux->avaliacao->nota1, aluno_aux->avaliacao->nota2, media_notas);
			else
				printf("Nome: %s\tNota 1: %.2f\tNota 2: %.2f\tMedia: %.2f\tSituacao: Reprovado por nota!\n", aluno_aux->aluno->nome, aluno_aux->avaliacao->nota1, aluno_aux->avaliacao->nota2, media_notas);
		}
		else
			printf("Nome: %s\tNota 1: %.2f\tNota 2: %.2f\tMedia: %.2f\tSituacao: Reprovado por frequencia!\n", aluno_aux->aluno->nome, aluno_aux->avaliacao->nota1, aluno_aux->avaliacao->nota2, media_notas);
	}
}