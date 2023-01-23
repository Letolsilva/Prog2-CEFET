#ifndef __LIST_DISCIPLINA_HPP
#define __LIST_DISCIPLINA_HPP
#include "Disciplina.hpp"
using namespace std;
class List_Disciplina {
private:
 
    Disciplina* inicio;
    Disciplina* final;
    

 public:
    List_Disciplina(string nome, int CH, Professor* prof);
    List_Disciplina();
    void inserir_disciplina(string nome, int CH, Professor* prof);
    void imprimir_disciplina();
    bool vazia();
    virtual ~List_Disciplina();

    Disciplina* getInicio();
    void setInicio(Disciplina* inicio);
    Disciplina* getFinal();
    void setFinal(Disciplina* final);
};
#endif