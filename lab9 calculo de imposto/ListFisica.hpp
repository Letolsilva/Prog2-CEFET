#ifndef ListFisica_HPP
#define ListFisica_HPP
#include <string>
#include <iostream>
#include "PessoaFisica.hpp"
using namespace std;
class Lista_fis
{
    private:
        PF *inicio;
        PF *fim;

    public:
    Lista_fis();
    Lista_fis(string nome,string cpf, float renda);
    virtual ~Lista_fis();
    bool vazia();
    void inserir(string nome, string cpf, float renda);
    void removerfisica(string cpf);
    void imprimir();
    void Calcularimposto(int renda, string cpf);
    
    PF* getInicio();
    void setInicio(PF* inicio);
    PF* getFinal();
    void setFinal(PF* final);
};
#endif