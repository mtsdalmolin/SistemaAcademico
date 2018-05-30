typedef struct aluno
{
	int matricula;
	char curso[50];
	char nome[50];
	struct aluno* prox;
} Aluno;

Aluno* cria_lista_alunos();

Aluno* insere_aluno(Aluno* lista_alunos, int matricula, char curso[], char nome[]);

void imprime_lista_alunos(Aluno* lista_alunos);

bool matricula_igual(Aluno* lista_alunos, int matricula);

Aluno* exclui_aluno(Aluno* lista_alunos, int matricula);

Aluno* busca_aluno(Aluno* lista_alunos, int matricula);

Aluno* cadastro_aluno(Aluno* lista_alunos);

void imprime_dados_aluno(Aluno* aluno_alvo);