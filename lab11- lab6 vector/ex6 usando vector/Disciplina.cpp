#include<iostream> 
#include "Disciplina.hpp"
using namespace std;

Disciplina::Disciplina(string nome, int CH, string nomeprof){ 
    setNome(nome);
    setCh(CH);
    setNomeprof(nomeprof);
}
Disciplina::Disciplina(){

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
void Disciplina::setNomeprof(string nomeprof){
    this->nomeprof=nomeprof;
}
string Disciplina::getNomeprof(){
    return this-> nomeprof;
}
