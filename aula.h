typedef struct data
{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct aula
{
	Data data_aula;
	char conteudo_ministrado[50];
	struct aula* prox;
} Aula;

Aula* cria_lista_aulas();

Aula* insere_aula(Aula* lista_aulas, Data* data_aula, char* conteudo_ministrado);

Aula* exclui_aula(Aula* lista_aulas, Data* data_aula);

void tira_presenca(Turma* turma_alvo);

void presenca_alunos(Aula* aula_alvo, Turma* lista_turmas);

void imprime_dados_aula(Aula* aula_alvo);

Aula* busca_aula(Aula* lista_aulas, Data* data_aula);

void imprime_lista_aulas(Aula* lista_aulas);

Aula* cadastro_aula(Turma* turma_alvo);