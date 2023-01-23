#ifndef __LISTA_ALUNO_HPP
#define __LIST_ALUNO_HPP

#include "Aluno.hpp"
using namespace std;
class ListAluno{
private:
    Aluno* inicio;
    Aluno* finala;
   

public:
    
    
    ListAluno(string matricula,string nome,string endereco);
    ListAluno();

    void inserir_aluno(string matricula,string nome,string endereco);
    void imprimir_aluno();

    bool vazia();

    virtual ~ListAluno();
    
    Aluno* getInicio();
    void setInicio(Aluno* inicio);
    Aluno* getFinala();
    void setFinala(Aluno* final);
};
#endif