#include<iostream> 
#include "Paciente.hpp"
using namespace std;

Paciente::Paciente(string nome,string sexo, string endereco, string cpf, string telefone, string identidade,string relato, string ultimaConsulta, string medicacao):Pessoa(nome,sexo,endereco,cpf, telefone, identidade){
    this->relato=relato;
    this->ultimaConsulta=ultimaConsulta;
    this->medicacao=medicacao;
    this->prox=NULL;
}  
Paciente::Paciente(){
   
}

void Paciente::setRelato(string relato){
    this->relato=relato;
}
string Paciente::getRelato(){
    return this->relato;
}
void Paciente::setUltimaConsulta(string ultimaConsulta){
    this->ultimaConsulta=ultimaConsulta;
}
string Paciente::getUltimaConsulta(){
    return this->ultimaConsulta;
}
void Paciente::setMedicacao(string medicacao){
    this->medicacao=medicacao;
}
string Paciente::getMedicacao(){
    return this->medicacao;
}
void Paciente::setProx(Paciente* prox){
    this->prox=prox;
}
Paciente* Paciente::getProx(){
    return this->prox;
}