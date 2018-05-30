void imprime_menu_secundario();

Aluno* menu_aluno(Aluno* lista_alunos, Turma* lista_turmas);

Professor* menu_professor(Professor* lista_professores, Turma* lista_turmas);

Disciplina* menu_disciplina(Disciplina* lista_disciplinas, Turma* lista_turmas);

Turma* menu_turma(Turma* lista_turmas, Aluno* lista_alunos, Professor* lista_professores, Disciplina* lista_disciplinas);

Aula* menu_aula(Turma* lista_turmas);

Avaliacao* menu_avaliacao(Turma* lista_turmas);

void imprime_menu_avaliacao();

void imprime_menu_relatorio_geral();

void menu_relatorio_geral(Aluno* lista_alunos, Professor* lista_professores, Disciplina* lista_disciplinas, Turma* lista_turmas);

void imprime_menu_principal();

void menu_principal(Aluno** lista_alunos, Professor** lista_professores, Disciplina** lista_disciplinas, Turma** lista_turmas, bool* sair_menu);