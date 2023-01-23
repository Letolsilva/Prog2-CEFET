#include<iostream> 
#include "Poupanca.hpp"
using namespace std;

ContaPoupanca::ContaPoupanca(string nome,int Num_conta,string Niver):ContaComum(nome, Num_conta){
    setNiver(Niver);
    this->prox=NULL;
}
ContaPoupanca::ContaPoupanca(){
     this->prox=NULL;
}

void ContaPoupanca::setNiver(string Niver){
    this->Niver=Niver;
}
string ContaPoupanca::getNiver(){
    return Niver;
}

void ContaPoupanca:: setProx(ContaPoupanca* prox){
    this->prox=prox;
}
ContaPoupanca* ContaPoupanca::getProx(){
    return this->prox;
}

void ContaPoupanca::extrato(){
    cout<<this->Transacao;
}
