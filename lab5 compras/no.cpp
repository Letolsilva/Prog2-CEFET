
#include "no.hpp"

No::No(int v, int id, int qtd, string nome) 
{
        this->v = v;
        this->id=id;
        this->qtd=qtd;
        this->nome=nome;
	this->prox = NULL;

}
No::No()
{
}
void No::setV(int v){
        this->v=v;
}
int No::getV(){ 
        return this-> v; 
} 
void No::setId(int id){
        this->id=id;
}
int No::getId(){ 
        return this -> id; 
} 

void No:: setQtd(int qtd){
        this->qtd=qtd;
}
int No::getQtd(){ 
        return this -> qtd; 
} 
void No:: setNome(string nome){
        this->nome=nome;
}
string No::getNome(){ 
        return this -> nome; 
} 

void No:: imprimir(){

        cout<<endl;
        cout << "O nome é: " << this->nome << endl;
        cout << "O ID é: " << this->id << endl;
        cout << "O valor é: "<< this->v << endl;
        cout << "A quantidade deste produto foi: " << this->qtd << endl;
        cout<<endl;
}

No* No::obterProx() 
{
	return this->prox;
}

void No::setProx(No* p) 
{
	this->prox = p;
}