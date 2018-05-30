#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"
#include "aula.h"
#include "avaliacao.h"

Avaliacao* insere_avaliacao(Avaliacao* lista_avaliacoes, float nota1, float nota2)
{
	Avaliacao* nova_avaliacao = (Avaliacao*) malloc(sizeof(Avaliacao));
	nova_avaliacao->nota1 = nota1;
	nova_avaliacao->nota2 = nota2;
	return nova_avaliacao;
}

Turma* cadastro_avaliacao(Turma* turma_alvo)
{
	float nota1;
	float nota2;
	AlunoTurma* aux;
	for (aux = turma_alvo->alunos; aux != NULL; aux = aux->prox)
	{
		printf("Aluno %s.\nNota da primeira avaliacao: ", aux->aluno->nome);
		scanf("%f", &nota1);
		printf("Nota da segunda avaliacao: ");
		scanf("%f", &nota2);
		aux->avaliacao = insere_avaliacao(aux->avaliacao, nota1, nota2);
	}
	return turma_alvo;
}