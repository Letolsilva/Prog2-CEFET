#ifndef PESSOAFISICA_HPP
#define PESSOAFISICA_HPP
#include "Pessoa.hpp"

class PF : public Pessoa
{
    private:
    string cpf;
    PF* prox;

    public:
    
    PF(string nome, string cpf, float renda);
    PF();
    void setCpf(string cpf);
    string getCpf();
    void setProx(PF* prox);
    PF* getProx();
       
};

#endif 