#include<iostream> 
#include "List_prof.hpp"
using namespace std;
List_Prof::List_Prof(){
    inicio=NULL;
    final=NULL;
}

List_Prof::List_Prof(string nome, string endereco,string titulacao, string curso){
    inicio = new Professor(nome, endereco, titulacao, curso);
	final = inicio;
}
bool List_Prof::vazia() 
{
	return (inicio == NULL);
}
List_Prof::~List_Prof(){
    delete inicio;
}
Professor* List_Prof::getInicio(){
    return this->inicio;
}
void List_Prof::setInicio(Professor* inicio){
    this->inicio=inicio;
}
Professor* List_Prof::getFinal(){
    return this->final;
}
void List_Prof::setFinal(Professor* final){
    this->final=final;
}

void List_Prof:: inserir_professor(string nome, string endereco,string titulacao, string curso){
   Professor* prof=new Professor(titulacao, curso, nome, endereco);
   if(vazia())
   {
       inicio=prof;
       final=prof;
   }
   else{
       final->setProx(prof);
       final=prof;
   }

}

void List_Prof:: imprimir_professor(){
    Professor* prof=inicio;
    if(vazia()){
        inicio=prof;
        final=prof;
    }
    else{
        while(prof){
        cout<<"A Titulaçao é: "<<prof->getTitulacao()<<endl;
        cout<<"O curso é: "<<prof->getCurso()<<endl;
        cout<<"O nome é: "<<prof->getNome()<<endl;
        cout<<"O endeço é: "<<prof->getEndereco()<<endl;
        prof=prof->getProx();
        }
    }
}

