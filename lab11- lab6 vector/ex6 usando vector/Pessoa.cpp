#include<iostream> 
#include "Pessoa.hpp"
using namespace std;

Pessoa::Pessoa(string nome, string endereco){
    setNome(nome);
    setEndereco(endereco);
}
Pessoa::Pessoa(){
    
}

void Pessoa::setNome(string nome){
this->nome=nome;
}

string Pessoa::getNome(){
return this->nome;
}
void Pessoa::setEndereco(string endereco){
this->endereco=endereco;
}
string Pessoa::getEndereco(){
return this->endereco;
}
