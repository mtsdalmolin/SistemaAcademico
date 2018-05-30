typedef struct professor
{
	int siape;
	char titulacao[50];
	char nome[50];
	char area_atuacao[50];
	struct professor* prox;
} Professor;

bool siape_igual(Professor* lista_professores, int siape);

Professor* cria_lista_professores();

Professor* insere_professor(Professor* lista_professores, int siape, char* titulacao, char* nome, char* area_atuacao);

Professor* exclui_professor(Professor* lista_professores, int siape);

Professor* busca_professor(Professor* lista_professores, int siape);

void imprime_lista_professores(Professor* lista_professores);

Professor* cadastro_professor(Professor* lista_professores);

void imprime_dados_professor(Professor* professor_alvo);