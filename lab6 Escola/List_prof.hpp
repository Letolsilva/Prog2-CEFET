#ifndef __LIST_PROF_HPP
#define __LIST_PROF_HPP
#include "Professor.hpp"
using namespace std;
class List_Prof {
private:
    static int tam2;
    Professor* inicio;
    Professor* final;

public:
    List_Prof(string nome, string endereco,string titulacao, string curso);
    List_Prof();
    void inserir_professor(string nome, string endereco,string titulacao, string curso);
    void imprimir_professor();
    bool vazia();
    virtual ~List_Prof();

    Professor* getInicio();
    void setInicio(Professor* inicio);
    Professor* getFinal();
    void setFinal(Professor* final);
};
#endif
