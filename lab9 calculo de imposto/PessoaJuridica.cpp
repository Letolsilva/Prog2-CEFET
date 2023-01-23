#include "PessoaJuridica.hpp"

PJ::PJ():Pessoa()
{
    this->prox = NULL;
}

PJ::PJ(string nome,string cnpj,float renda):Pessoa(nome,renda){
    this->prox = NULL;
    this-> cnpj = cnpj;
}


void PJ::setCnpj(string cnpj)
{
    this-> cnpj=cnpj;
}

string PJ::getCnpj()
{
    return this->cnpj;
}
 
void PJ::setProx(PJ* prox){
    this->prox=prox;
}
PJ* PJ::getProx()
{
    return this->prox;
}

