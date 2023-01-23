#include<iostream> 
#include "Professor.hpp"
using namespace std;

Professor::Professor(string titulacao, string curso, string nome, string endereco):Pessoa(nome,endereco){
    setTitulacao(titulacao);
    setCurso(curso);
    
}
Professor::Professor(){
    
}

void Professor::setTitulacao(string titulacao){
    this->titulacao=titulacao;
}
string Professor::getTitulacao(){
    return titulacao;
}
void Professor::setCurso(string curso){
    this->curso=curso;
}
string Professor::getCurso(){
    return curso;
}
