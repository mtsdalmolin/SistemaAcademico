typedef struct disciplina
{
	int codigo;
	int carga_horaria;
	struct prerrequisito* prerrequisitos;
	char curso[50];
	char nome[50];
	struct disciplina* prox;
} Disciplina;

typedef struct prerrequisito
{
	struct disciplina* disc;
	struct prerrequisito* prox;
} Prerrequisito;

typedef struct lista_prerrequisitos
{
	int codigo;
	struct lista_prerrequisitos* prox;
} Lista_Prerrequisitos;

bool codigo_igual(Disciplina* lista_disciplinas, int codigo);

Disciplina* cria_lista_disciplinas();

Disciplina* insere_disciplina(Disciplina* lista_disciplinas, int codigo, int carga_horaria, char* curso, char* nome, Lista_Prerrequisitos* lista_prerrequisitos);

Disciplina* exclui_disciplina(Disciplina* lista_disciplinas, int codigo);

Disciplina* busca_disciplina(Disciplina* lista_disciplinas, int codigo);

void imprime_lista_disciplinas(Disciplina* lista_disciplinas);

Disciplina* cadastro_disciplina(Disciplina* lista_disciplinas);

Prerrequisito* inserir_prerrequisito(Disciplina* nova_disciplina, Disciplina* lista_disciplinas, int codigo_prerrequisito);

Lista_Prerrequisitos* adicionar_prerrequisito_lista(Lista_Prerrequisitos* lista, int codigo);

void libera_lista_prerrequisitos(Lista_Prerrequisitos* lista_prerrequisitos);

void imprime_disciplinas_sem_prerrequisitos(Disciplina* lista_disciplinas);

void imprime_dados_disciplina(Disciplina* disciplina_alvo);