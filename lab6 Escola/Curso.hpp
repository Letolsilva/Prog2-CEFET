#ifndef __CURSO_HPP
#define __CURSO_HPP
#include <string>
#include "List_Aluno.hpp"
#include "List_prof.hpp"
#include "List_Disciplina.hpp"
using namespace std;
class Curso {
private:
   ListAluno* alunos;
   List_Prof* professores;
   List_Disciplina* disciplinas;
   string nome_curso;


public:
    Curso (string nome_curso, List_Prof* professores, ListAluno* alunos, List_Disciplina* disciplinas);
    Curso();
    void setNome_curso(string nome_curso);
    string getNome_curso();
    
    void cadastrar_professor();
    void cadastrar_aluno();
    void cadastrar_disciplina();
    void imprimir_prof();
    void imprimir_aluno();
    void imprimir_disciplina();
};
#endif