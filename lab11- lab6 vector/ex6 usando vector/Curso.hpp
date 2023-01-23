#ifndef __CURSO_HPP
#define __CURSO_HPP
#include <string>
#include <vector>
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Disciplina.hpp"

using namespace std;
class Curso {
private:
    vector <Professor>prof;
    vector <Aluno> alunos;
    vector <Disciplina>disci;
    string nome_curso;


public:
    Curso (string nome_curso);
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