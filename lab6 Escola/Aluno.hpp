#ifndef __ALUNO_HPP
#define __ALUNO_HPP
#include<iostream> 
#include "Pessoa.hpp"
#include <string>
using namespace std;
class Aluno:public Pessoa{
private:
    string matricula;
    Aluno* prox;

public:
    Aluno(string matricula,string nome,string endereco);
    Aluno();

    void setMatricula(string matricula);
    string getMatricula();
    
    Aluno* getProx();
    void setProx(Aluno* prox);

};
#endif