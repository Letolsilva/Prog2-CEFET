#include<iostream> 
#include "Disciplina.hpp"
using namespace std;

Disciplina::Disciplina(string nome, int CH, Professor* prof){
    setNome(nome);
    setCh(CH);
    setProf(prof);
    this -> prox = NULL;
}
Disciplina::Disciplina(){
    this -> prox = NULL;
}

void Disciplina::setNome(string nome){
    this->nome=nome;
}
string Disciplina::getNome(){
return nome;
}
void Disciplina::setCh(int CH){
    this->CH=CH;
}
int Disciplina::getCh(){
    return CH;
}
void Disciplina::setProf(Professor* prof){
    this->prof=prof;
}
Professor* Disciplina::getProf(){
    return this-> prof;
}
void Disciplina:: setProx(Disciplina* prox){
    this->prox=prox;
}
Disciplina* Disciplina::getProx(){
    return this->prox;
}