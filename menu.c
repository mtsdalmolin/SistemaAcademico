#include <stdio.h>
#include <stdbool.h>
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "turma.h"
#include "aula.h"
#include "avaliacao.h"
#include "rgeral.h"
#include "verifica.h"

void imprime_menu_principal()
{
	printf("----------MENU PRINCIPAL----------\n[1]ALUNO\n[2]PROFESSOR\n[3]DISCIPLINA\n[4]TURMA\n[5]AULA\n[6]AVALIACAO\n[7]RELATORIO GERAL\n[8]SAIR\n");
}

void imprime_menu_secundario()
{
	printf("[1]INSERIR\n[2]BUSCAR\n[3]EXCLUIR\n[4]VOLTAR\n");
}

Aluno* menu_aluno(Aluno* lista_alunos, Turma* lista_turmas)
{
	int seleciona_menu;
	int matricula_aluno;
	bool sair_menu = false;
	Aluno* aluno_alvo;
	do
	{
		printf("----------ALUNO----------\n");
		imprime_menu_secundario();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				printf("----------INSERIR----------\n");
				lista_alunos = cadastro_aluno(lista_alunos);
				break;
			case 2:
				printf("----------BUSCAR----------\n");
				if (lista_alunos == NULL)
					printf("\nSISTEMA SEM ALUNOS CADASTRADOS!!!\n\n");
				else
				{
					printf("Matricula do aluno:\n");
					scanf("%d", &matricula_aluno);
					aluno_alvo = busca_aluno(lista_alunos, matricula_aluno);
					if (aluno_alvo == NULL)
						printf("\nALUNO NAO CADASTRADO NO SISTEMA!!!\n\n");
					else
						imprime_dados_aluno(aluno_alvo);
				}
				break;
			case 3:
				printf("----------EXCLUIR----------\n");
				if (lista_alunos == NULL)
					printf("\nSISTEMA SEM ALUNOS CADASTRADOS!!!\n\n");
				else
				{
					printf("Matricula do aluno:\n");
					scanf("%d", &matricula_aluno);
					aluno_alvo = busca_aluno(lista_alunos, matricula_aluno);
					if (aluno_alvo == NULL)
						printf("\nALUNO NAO CADASTRADO NO SISTEMA!!!\n\n");
					else
					{
						if (!aluno_matriculado_turma(lista_turmas, aluno_alvo))
							lista_alunos = exclui_aluno(lista_alunos, matricula_aluno);
						else
							printf("\nNAO EH POSSIVEL EXCLUIR UM ALUNO CADASTRADO EM UMA TURMA!!!\n\n");
					}
				}
				break;
			case 4:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}
	} while (!sair_menu);
	return lista_alunos;
}

Professor* menu_professor(Professor* lista_professores, Turma* lista_turmas)
{
	int seleciona_menu;
	int siape_professor;
	bool sair_menu = false;
	Professor* professor_alvo;
	do
	{
		printf("----------PROFESSOR----------\n");
		imprime_menu_secundario();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				printf("----------INSERIR----------\n");
				lista_professores = cadastro_professor(lista_professores);
				break;
			case 2:
				printf("----------BUSCAR----------\n");
				if (lista_professores == NULL)
					printf("\nSISTEMA SEM PROFESSORES CADASTRADOS!!!\n\n");
				else
				{
					printf("Siape do professor:\n");
					scanf("%d", &siape_professor);
					professor_alvo = busca_professor(lista_professores, siape_professor);
					if (professor_alvo == NULL)
						printf("\nPROFESSOR NAO CADASTRADO NO SISTEMA!!!\n\n");
					else
						imprime_dados_professor(professor_alvo);
				}
				break;
			case 3:
				printf("----------EXCLUIR----------\n");
				if (lista_professores == NULL)
					printf("\nSISTEMA SEM PROFESSORES CADASTRADOS!!!\n\n");
				else
				{
					printf("Siape do professor:\n");
					scanf("%d", &siape_professor);
					professor_alvo = busca_professor(lista_professores, siape_professor);
					if (professor_alvo == NULL)
						printf("\nPROFESSOR NAO CADASTRADO NO SISTEMA!!!\n\n");
					else
					{
						if (!professor_matriculado_turma(lista_turmas, professor_alvo))
							lista_professores = exclui_professor(lista_professores, siape_professor);
						else
							printf("\nNAO EH POSSIVEL EXCLUIR UM PROFESSOR CADASTRADO EM UMA TURMA!!!\n\n");
					}
				}
				break;
			case 4:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}
	} while (!sair_menu);
	return lista_professores;
}

Disciplina* menu_disciplina(Disciplina* lista_disciplinas, Turma* lista_turmas)
{
	int seleciona_menu;
	int codigo_disciplina;
	bool sair_menu = false;
	Disciplina* disciplina_alvo;
	do
	{
		printf("----------DISCIPLINA----------\n");
		imprime_menu_secundario();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				printf("----------INSERIR----------\n");
				lista_disciplinas = cadastro_disciplina(lista_disciplinas);
				break;
			case 2:
				printf("----------BUSCAR----------\n");
				if (lista_disciplinas == NULL)
					printf("\nSISTEMA SEM DISCIPLINAS CADASTRADAS!!!\n\n");
				else
				{
					printf("Codigo da disciplina:\n");
					scanf("%d", &codigo_disciplina);
					disciplina_alvo = busca_disciplina(lista_disciplinas, codigo_disciplina);
					if (disciplina_alvo == NULL)
						printf("\nDISCIPLINA NAO CADASTRADA NO SISTEMA!!!\n\n");
					else
						imprime_dados_disciplina(disciplina_alvo);
				}
				break;
			case 3:
				printf("----------EXCLUIR----------\n");
				if (lista_disciplinas == NULL)
					printf("\nSISTEMA SEM DISCIPLINAS CADASTRADAS!!!\n\n");
				else
				{
					printf("Codigo da disciplina:\n");
					scanf("%d", &codigo_disciplina);
					disciplina_alvo = busca_disciplina(lista_disciplinas, codigo_disciplina);
					if (disciplina_alvo == NULL)
						printf("\nDISCIPLINA NAO CADASTRADA NO SISTEMA!!!\n\n");
					else
					{
						if (!disciplina_vinculada_turma(lista_turmas, disciplina_alvo))
							lista_disciplinas = exclui_disciplina(lista_disciplinas, codigo_disciplina);
						else
							printf("\nNAO EH POSSIVEL EXCLUIR UMA DISCIPLINA VINCULADA A UMA TURMA!!!\n\n");
					}
				}
				break;
			case 4:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}
	} while (!sair_menu);
	return lista_disciplinas;
}

Turma* menu_turma(Turma* lista_turmas, Aluno* lista_alunos, Professor* lista_professores, Disciplina* lista_disciplinas)
{
	int seleciona_menu;
	int numero_turma;
	bool sair_menu = false;
	Turma* turma_alvo;
	do
	{
		printf("----------TURMA----------\n");
		imprime_menu_secundario();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				printf("----------INSERIR----------\n");
				if (lista_alunos == NULL && lista_professores == NULL && lista_disciplinas == NULL)
					printf("\nEH PRECISO TER ALUNOS, PROFESSORES E DISCIPLINAS PARA CADASTRAR UMA TURMA!!\n\n");
				else
				{
					lista_turmas = cadastro_turma(lista_turmas, lista_disciplinas, lista_professores, lista_alunos);
				}
				break;
			case 2:
				printf("----------BUSCAR----------\n");
				if (lista_turmas == NULL)
					printf("\nSISTEMA SEM TURMAS CADASTRADAS!!!\n\n");
				else
				{
					printf("Numero da turma:\n");
					scanf("%d", &numero_turma);
					turma_alvo = busca_turma(lista_turmas, numero_turma);
					if (turma_alvo == NULL)
						printf("\nTURMA NAO CADASTRADA NO SISTEMA!!!\n\n");
					else
						imprime_dados_turma(turma_alvo);
				}
				break;
			case 3:
				printf("----------EXCLUIR----------\n");
				if (lista_turmas == NULL)
					printf("\nSISTEMA SEM TURMAS CADASTRADAS!!!\n\n");
				else
				{
					printf("Numero da turma:\n");
					scanf("%d", &numero_turma);
					lista_turmas = exclui_turma(lista_turmas, numero_turma);
				}
				break;
			case 4:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}	
	} while (!sair_menu);
	return lista_turmas;
}

Aula* menu_aula(Turma* lista_turmas)
{
	int seleciona_menu;
	int numero_turma;
	bool sair_menu = false;
	Data data_aula;
	Aula* aula_alvo;
	Aula* aux;
	Turma* turma_alvo;
	do
	{
		printf("----------AULA----------\n");
		imprime_menu_secundario();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				if (lista_turmas == NULL)
					printf("\nNAO EH POSSIVEL INSERIR UMA AULA SEM TURMAS CADASTRADAS!\n\n");
				else
				{
					printf("----------INSERIR----------\n");
					printf("LISTA DE TURMAS CADASTRADAS NO SISTEMA\n");
					imprime_lista_turmas(lista_turmas);
					printf("Informe o numero da turma que deseja inserir a aula:\n");
					scanf("%d", &numero_turma);
					turma_alvo = busca_turma(lista_turmas, numero_turma);
					if (turma_alvo == NULL)
						printf("\nTURMA NAO CADASTRADA NO SISTEMA!!!\nNAO EH POSSIVEL CADASTRAR UMA AULA!!!\n\n");
					else if (turma_alvo->numero_aulas >= turma_alvo->disciplina->carga_horaria)
						printf("\nTOTAL DE AULAS JA CADASTRADO\n\n");
					else
					{
						turma_alvo->aulas = cadastro_aula(turma_alvo);
						turma_alvo->numero_aulas++;
					}
				}
				break;
			case 2:
				if (lista_turmas->aulas == NULL)
					printf("\nTURMA SEM AULAS CADASTRADAS!\n\n");
				else
				{
					printf("----------BUSCAR----------\n");
					printf("Informe o numero da turma que deseja buscar a aula:\n");
					scanf("%d", &numero_turma);
					turma_alvo = busca_turma(lista_turmas, numero_turma);
					if (turma_alvo == NULL)
						printf("\nTURMA NAO CADASTRADA NO SISTEMA!!!\nNAO EH POSSIVEL BUSCAR UMA AULA!!!\n\n");
					else
					{
						printf("Informe a data da aula:\nDia: ");
						scanf("%d", &data_aula.dia);
						printf("Mes: ");
						scanf("%d", &data_aula.mes);
						printf("Ano: ");
						scanf("%d", &data_aula.ano);
						aula_alvo = busca_aula(turma_alvo->aulas, &data_aula);
						if (aula_alvo == NULL)
							printf("\nAULA NAO CADASTRADA NO SISTEMA!!!\n\n");
						else
							for (aux = aula_alvo; aux != NULL; aux = aux->prox)
								if (aux->data_aula.dia == data_aula.dia && aux->data_aula.mes == data_aula.mes && aux->data_aula.ano == data_aula.ano)
									imprime_dados_aula(aux);
					}
				}
				break;
			case 3:
				if (lista_turmas->aulas == NULL)
					printf("\nTURMA SEM AULAS CADASTRADAS!\n\n");
				else
				{
					printf("----------EXCLUIR----------\n");
					printf("Informe o numero da turma que deseja buscar a aula:\n");
					scanf("%d", &numero_turma);
					turma_alvo = busca_turma(lista_turmas, numero_turma);
					if (turma_alvo == NULL)
						printf("\nTURMA NAO CADASTRADA NO SISTEMA!!!\nNAO EH POSSIVEL EXCLUIR UMA AULA!!!\n\n");
					else
					{
						printf("Informe a data da aula:\nDia: ");
						scanf("%d", &data_aula.dia);
						printf("Mes: ");
						scanf("%d", &data_aula.mes);
						printf("Ano: ");
						scanf("%d", &data_aula.ano);
						aula_alvo = busca_aula(turma_alvo->aulas, &data_aula);
						if (aula_alvo == NULL)
							printf("\nAULA NAO CADASTRADA NO SISTEMA!!!\n\n");
						else
						{
							turma_alvo->aulas = exclui_aula(turma_alvo->aulas, &data_aula);
							turma_alvo->numero_aulas--;
							tira_presenca(turma_alvo);
						}
					}
					
				}
				break;
			case 4:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}
	} while (!sair_menu);
	return lista_turmas->aulas;
}

void imprime_menu_avaliacao()
{
	printf("[1]INSERIR\n[2]VOLTAR\n");
}

Avaliacao* menu_avaliacao(Turma* lista_turmas)
{
	int seleciona_menu;
	int numero_turma;
	bool sair_menu = false;
	Turma* turma_alvo;
	do
	{
		printf("----------AVALIACAO----------\n");
		imprime_menu_avaliacao();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				if (lista_turmas == NULL)
					printf("\nNAO EH POSSIVEL INSERIR UMA AVALIACAO SEM TURMAS CADASTRADAS!\n\n");
				else
				{
					if (lista_turmas->alunos == NULL)
						printf("\nNAO EH POSSIVEL INSERIR UMA AVALIACAO EM UMA TURMA SEM ALUNOS\n\n");
					else
					{
						printf("----------INSERIR----------\n");
						printf("Informe o numero da turma que voce deseja inserir uma avaliacao.\n");
						scanf("%d", &numero_turma);
						turma_alvo = busca_turma(lista_turmas, numero_turma);
						if (turma_alvo == NULL)
							printf("\nTURMA NAO CADASTRADA NO SISTEMA!!!\n\n");
						else
						{
							if (turma_alvo->alunos->avaliacao != NULL)
								printf("\nNOTAS JA LANCADAS PARA ESSA TURMA!!!\n\n");
							else
								turma_alvo = cadastro_avaliacao(turma_alvo);
						}
					}
				}
				break;
			case 2:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}
	} while (!sair_menu);
	return lista_turmas->alunos->avaliacao;
}

void imprime_menu_relatorio_geral()
{
	printf("[1]IMPRIMIR RELATORIO GERAL\n[2]IMPRIMIR LISTA DE ALUNOS\n[3]IMPRIMIR LISTA DE PROFESSORES\n[4]IMPRIMIR LISTA DE DISCIPLINAS\n[5]IMPRIMIR LISTA DE TURMAS\n[6]VOLTAR\n");
}

void menu_relatorio_geral(Aluno* lista_alunos, Professor* lista_professores, Disciplina* lista_disciplinas, Turma* lista_turmas)
{
	int seleciona_menu;
	int numero_turma;
	bool sair_menu = false;
	Turma* turma_alvo;
	do
	{
		printf("----------RELATORIO GERAL----------\n");
		imprime_menu_relatorio_geral();
		scanf("%d", &seleciona_menu);
		switch (seleciona_menu)
		{
			case 1:
				if (lista_turmas == NULL)
					printf("\nSISTEMA SEM TURMAS CADASTRADAS!!!\n\n");
				else
				{
					printf("Informe o codigo da turma que voce quer o relatorio geral.\n");
					scanf("%d", &numero_turma);

					turma_alvo = busca_turma(lista_turmas, numero_turma);
					if (turma_alvo == NULL)
						printf("\nTURMA NAO CADASTRADA NO SISTEMA!!!\n\n");
					else
					{
						if (turma_alvo->alunos == NULL)
							printf("\nNAO EH POSSIVEL GERAR RELATORIO GERAL DE UMA TURMA SEM ALUNOS\n\n");
						else
						{
							if (turma_alvo->alunos->avaliacao == NULL)
								printf("\nNAO EH POSSIVEL GERAR RELATORIO GERAL DE UMA TURMA SEM AVALIACAO\n\n");
							else
								gerar_relatorio_geral(turma_alvo);
						}
					}
				}
				break;
			case 2:
				if (lista_alunos == NULL)
					printf("\nSISTEMA SEM ALUNOS CADASTRADOS!!!\n\n");
				else
					imprime_lista_alunos(lista_alunos);
				break;
			case 3:
				if (lista_professores == NULL)
					printf("\nSISTEMA SEM PROFESSORES CADASTRADOS!!!\n\n");
				else
					imprime_lista_professores(lista_professores);
				break;
			case 4:
				if (lista_disciplinas == NULL)
					printf("\nSISTEMA SEM DISCIPLINAS CADASTRADAS!!!\n\n");
				else
					imprime_lista_disciplinas(lista_disciplinas);
				break;
			case 5:
				if (lista_turmas == NULL)
					printf("\nSISTEMA SEM TURMAS CADASTRADAS!!!\n\n");
				else
					imprime_lista_turmas(lista_turmas);
				break;
			case 6:
				sair_menu = true;
				break;
			default: printf("Entrada invalida!\n");
		}
	} while (!sair_menu);
}

void menu_principal(Aluno** lista_alunos, Professor** lista_professores, Disciplina** lista_disciplinas, Turma** lista_turmas, bool* sair_menu)
{
	int seleciona_menu;
	imprime_menu_principal();
	scanf("%d", &seleciona_menu);
	switch (seleciona_menu)
	{
		case 1:
			*lista_alunos = menu_aluno(*lista_alunos, *lista_turmas);
			break;
		case 2:
			*lista_professores = menu_professor(*lista_professores, *lista_turmas);
			break;
		case 3:
			*lista_disciplinas = menu_disciplina(*lista_disciplinas, *lista_turmas);
			break;
		case 4:
			*lista_turmas = menu_turma(*lista_turmas, *lista_alunos, *lista_professores, *lista_disciplinas);
			break;
		case 5:
			if (*lista_turmas == NULL)
				printf("\nEH PRECISO TER TURMAS CADASTRADAS NO SISTEMA PARA ACESSAR O MENU AULA!\n\n");
			else
				(*lista_turmas)->aulas = menu_aula(*lista_turmas);
			break;
		case 6:
			if (*lista_turmas == NULL)
				printf("\nEH PRECISO TER TURMAS CADASTRADAS NO SISTEMA PARA ACESSAR O MENU AVALIACAO!\n\n");
			else
				(*lista_turmas)->alunos->avaliacao = menu_avaliacao(*lista_turmas);
			break;
		case 7:
			menu_relatorio_geral(*lista_alunos, *lista_professores, *lista_disciplinas, *lista_turmas);
			break;
		case 8:
			*sair_menu = true;
			break;
		default: printf("Entrada invalida!\n");
	}
}