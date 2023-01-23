#include<iostream> 
#include "Pessoa.hpp"
using namespace std;

Pessoa::Pessoa(string nome, string sexo, string endereco, string cpf, string telefone, string identidade){
    this->nome=nome;
    this->sexo=sexo;
    this->endereco=endereco;
    this->cpf=cpf;
    this->telefone=telefone;
    this->identidade=identidade;
}
Pessoa::Pessoa(){
    
}

void Pessoa::setNome(string nome){
    this->nome=nome;
}

string Pessoa::getNome(){
    return this->nome;
}

void Pessoa:: setSexo(string sexo){
    this->sexo=sexo;
}
string Pessoa::getSexo(){
    return this->sexo;
}

void Pessoa::setEndereco(string endereco){
this->endereco=endereco;
}
string Pessoa::getEndereco(){
return this->endereco;
}

void Pessoa::setCpf(string cpf){
    this->cpf=cpf;
}
string Pessoa::getCpf(){
return this->cpf;
}

void Pessoa::setTelefone(string telefone){
    this->telefone=telefone;
}
string Pessoa::getTelefone(){
    return this->telefone;
}

void Pessoa::setIdentidade(string identidade){
    this->identidade=identidade;
}
string Pessoa::getIdentidade(){
    return this->identidade;
}

