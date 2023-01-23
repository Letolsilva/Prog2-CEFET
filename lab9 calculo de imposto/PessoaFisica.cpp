#include "PessoaFisica.hpp"

PF::PF():Pessoa()
{
    this->prox = NULL;
    this-> cpf = cpf;
}

PF::PF(string nome,string cpf,float renda):Pessoa(nome,renda){
    this->prox = NULL;
    this-> cpf = cpf;
}
void PF::setCpf(string cpf)
{
    this-> cpf=cpf;
}

string PF::getCpf()
{
    return this->cpf;
}
void PF::setProx(PF* prox){
    this->prox=prox;
}
PF* PF::getProx()
{
    return this->prox;
}

