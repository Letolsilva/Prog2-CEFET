#ifndef ListaJuridica_HPP
#define ListaJuridica_HPP
#include <string>
#include <iostream>
#include "PessoaJuridica.hpp"
using namespace std;
class Lista_juri
{
    private:
        PJ *inicio;
        PJ *fim;

    public:
    Lista_juri();
    Lista_juri(string nome,string cnpj, float renda);
    bool vazia();
    virtual ~Lista_juri();
    void inserir(string nome, string cnpj, float renda);
    void removerjuri(string cnpj);
    void imprimir();
    void Calcularimposto(int renda, string cnpj);
    
    PJ* getInicio();
    void setInicio(PJ* inicio);
    PJ* getFinal();
    void setFinal(PJ* final);
};
#endif