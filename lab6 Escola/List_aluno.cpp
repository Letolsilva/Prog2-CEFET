#include<iostream> 
#include "List_Aluno.hpp"
using namespace std;

ListAluno::ListAluno(){
    inicio = NULL;
	finala = NULL;
}
ListAluno::ListAluno(string matricula,string nome,string endereco){
    inicio = new Aluno(matricula, nome, endereco);
	finala = inicio;
    
}

bool ListAluno::vazia() 
{
    return (inicio==NULL);
}
ListAluno::~ListAluno(){
    delete inicio;
}
Aluno* ListAluno::getInicio(){
    return this->inicio;
}
void ListAluno::setInicio(Aluno* inicio){
    this->inicio=inicio;
}
Aluno* ListAluno::getFinala(){
    return this->finala;
}
void ListAluno::setFinala(Aluno* final){
    this->finala=finala;
}
void ListAluno:: inserir_aluno(string matricula,string nome,string endereco){
   Aluno* al=new Aluno(matricula, nome, endereco);
   if(vazia())
   {
       inicio=al;
       finala=al;
   }
   else{
       finala->setProx(al);
       finala=al;
   }
   
}

void ListAluno:: imprimir_aluno(){
    Aluno* aul=inicio;
     if(vazia())
   {
       inicio=aul;
       finala=aul;
       cout<<"lista vazia";
   }
   else{
        while(aul){
            cout<<"A matricula é: "<<aul->getMatricula()<<endl;
            cout<<"O nome é: "<<aul->getNome()<<endl;
            cout<<"O endeço é: "<<aul->getEndereco()<<endl;
            aul=aul->getProx();
        }
   }
}
