#ifndef __PROFESSOR_HPP
#define __PROFESSOR_HPP
#include<iostream> 
#include <string>
#include "Pessoa.hpp"
using namespace std;
class Professor:public Pessoa {
private:
    string titulacao;
    string curso;

public:
Professor(string titulacao, string curso, string nome,string endereco);
Professor();

void setTitulacao(string titulacao);
string getTitulacao();

void setCurso(string curso);
string getCurso();

 
};
#endif