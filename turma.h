typedef struct turma
{
	int numero;
	int numero_aulas;
	struct disciplina* disciplina;
	struct prof_turma* professores;
	struct aluno_turma* alunos;
	struct aula* aulas;
	struct turma* prox;
} Turma;

typedef struct lista_prof_turma
{
	int siape;
	struct lista_prof_turma* prox;
} ListaProfTurma;

typedef struct lista_aluno_turma
{
	int matricula;
	struct lista_aluno_turma* prox;
} ListaAlunoTurma;

typedef struct prof_turma
{
	struct professor* professor;
	struct prof_turma* prox;
} ProfTurma;

typedef struct aluno_turma
{
	int num_presencas;
	struct avaliacao* avaliacao;
	struct aluno* aluno;
	struct aluno_turma* prox;
} AlunoTurma;

Turma* cria_lista_turmas();

bool numero_turma_igual(Turma* lista_turmas, int numero_turma);

ProfTurma* insere_professor_turma(Turma* nova_turma, Professor* lista_professores, int siape);

AlunoTurma* insere_aluno_turma(Turma* nova_turma, Aluno* lista_alunos, int matricula);

Turma* insere_turma(Turma* lista_turmas, int numero_turma, Disciplina* disciplina, ListaProfTurma* professoresT, ListaAlunoTurma* alunosT, Professor* lista_professores, Aluno* lista_alunos);

Turma* exclui_turma(Turma* lista_turmas, int numero_turma);

Turma* busca_turma(Turma* lista_turmas, int numero_turma);

ListaProfTurma* insere_professor_lista_turma(ListaProfTurma* professoresT, int siape);

ListaAlunoTurma* insere_aluno_lista_turma(ListaAlunoTurma* alunosT, int matricula);

Turma* cadastro_turma(Turma* lista_turmas, Disciplina* lista_disciplinas, Professor* lista_professores, Aluno* lista_alunos);

void imprime_lista_turmas(Turma* lista_turmas);

bool aluno_ja_matriculado(ListaAlunoTurma* alunosT, int matricula_aluno);

bool professor_ja_matriculado(ListaProfTurma* professoresT, int siape_professor);

void imprime_dados_turma(Turma* turma_alvo);