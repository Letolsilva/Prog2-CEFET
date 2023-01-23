#include<iostream> 
#include "List_Disciplina.hpp"
using namespace std;
List_Disciplina::List_Disciplina(){
    inicio=NULL;
    final=NULL;
}

List_Disciplina::List_Disciplina(string nome, int CH, Professor* prof){
    inicio = new Disciplina(nome,CH,prof);
	final = inicio;
}
bool List_Disciplina::vazia() 
{
	return (inicio == NULL);
}
List_Disciplina::~List_Disciplina(){
    delete inicio;
}
Disciplina* List_Disciplina::getInicio(){
    return this->inicio;
}
void List_Disciplina::setInicio(Disciplina* inicio){
    this->inicio=inicio;
}
Disciplina* List_Disciplina::getFinal(){
    return this->final;
}
void List_Disciplina::setFinal(Disciplina* final){
    this->final=final;
}

void List_Disciplina:: inserir_disciplina(string nome, int CH, Professor* prof){
   Disciplina* disc=new Disciplina(nome, CH, prof);
   if(vazia())
   {
       inicio=disc;
       final=disc;
   }
   else{
       final->setProx(disc);
       final=disc;
   }

}

void List_Disciplina:: imprimir_disciplina(){
    Disciplina* disc=inicio;
    if(vazia()){
        inicio=disc;
        final=disc;
    }
    else{
        while(disc){
        cout<<"O nome é: "<<disc->getNome()<<endl;
        cout<<"O CH é: "<<disc->getCh()<<endl;
        cout<<"O professor: "<<disc->getProf()->getNome()<<endl;

        disc=disc->getProx();
        }
    }
}

