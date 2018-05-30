#include <stdio.h>
#include <stdbool.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"
#include "aula.h"
#include "avaliacao.h"
#include "menu.h"
#include "rgeral.h"
#include "verifica.h"

int main()
{
	bool sair_menu = false;
	Aluno* lista_alunos;
	Professor* lista_professores;
	Disciplina* lista_disciplinas;
	Turma* lista_turmas;
	Aula* lista_aulas;

	lista_alunos = cria_lista_alunos();
	lista_professores = cria_lista_professores();
	lista_disciplinas = cria_lista_disciplinas();
	lista_turmas = cria_lista_turmas();
	lista_aulas = cria_lista_aulas();

	do
	{
		menu_principal(&lista_alunos, &lista_professores, &lista_disciplinas, &lista_turmas, &sair_menu);
	} while (!sair_menu);

	return 0;
}