#ifndef PESSOAJURIDICA_HPP
#define PESSOAJURIDICA_HPP
#include "Pessoa.hpp"

class PJ : public Pessoa
{
    private:
    string cnpj;
    PJ* prox;
    public:
    PJ(string nome,string cnpj,float renda);
    PJ();
    void setCnpj(string cnpj);
    string getCnpj();
    void setProx(PJ* prox);
    PJ* getProx();
    
};

#endif 