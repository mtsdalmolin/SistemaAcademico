typedef struct avaliacao
{
	float nota1;
	float nota2;
} Avaliacao;

Avaliacao* insere_avaliacao(Avaliacao* lista_avaliacoes, float nota1, float nota2);

Turma* cadastro_avaliacao(Turma* turma_alvo);