#include "Aluno.hpp"
using namespace std;

Aluno::Aluno(string matricula,string nome,string endereco):Pessoa(nome,endereco){
    setMatricula(matricula);
    
} 
Aluno::Aluno(){  

} 

void Aluno::setMatricula(string matricula){
    this->matricula=matricula;
}
string Aluno::getMatricula(){
    return this-> matricula;
}
