#include "Pessoa.hpp"
Pessoa::Pessoa()
{
}
Pessoa::Pessoa(string nome, float renda)
{
    this -> nome = nome;
    this -> renda = renda;
    this -> valorpago=valorpago;
}

void Pessoa::setNome(string nome)
{
    this-> nome=nome;
}

string Pessoa::getNome()
{
    return this->nome;
}

void Pessoa::setRenda(float renda)
{
    this-> renda=renda;
}

float Pessoa::getRenda()
{
    return this->renda;
}

void Pessoa::setValorpago(string valorpago){
    this-> valorpago=valorpago;
}
string Pessoa:: getValorpago(){
    return  this->valorpago;
}