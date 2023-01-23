#include "Aluno.hpp"
using namespace std;

Aluno::Aluno(string matricula,string nome,string endereco):Pessoa(nome,endereco){
    setMatricula(matricula);
    this->prox=NULL;
} 
Aluno::Aluno(){  
    this->prox=NULL;
} 

void Aluno::setMatricula(string matricula){
    this->matricula=matricula;
}
string Aluno::getMatricula(){
    return this-> matricula;
}
void Aluno:: setProx(Aluno* prox){
    this->prox=prox;
}
Aluno* Aluno::getProx(){
    return this->prox;
}