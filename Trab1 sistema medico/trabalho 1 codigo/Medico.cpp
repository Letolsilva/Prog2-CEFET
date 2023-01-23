#include<iostream> 
#include "Medico.hpp"

using namespace std;

Medico::Medico(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, int crm, string especialidade):Pessoa(nome,sexo,endereco, cpf, telefone, identidade){
    this->crm=crm;
    this->especialidade=especialidade;
    this->prox=NULL;
}
Medico::Medico(){
    
}

void Medico::setCrm(int crm){
    this->crm=crm;
}
int Medico::getCrm(){
    return this->crm;
}

void Medico::setEspecialidade(string especialidade){
    this->especialidade=especialidade;
}
string Medico::getEspecialidade(){
    return this->especialidade;
}

void Medico::setProx(Medico* prox){
    this->prox=prox;
}
Medico* Medico::getProx(){
    return this->prox;
}

