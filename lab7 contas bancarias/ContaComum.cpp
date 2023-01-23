#include "ContaComum.hpp"

using namespace std;

ContaComum::ContaComum(string nome,int Num_conta){
    this->nome=nome;
    this->Num_conta=Num_conta;
    this->Saldo=0;
    this->Transacao="";
    this->prox=NULL;
} 
ContaComum::ContaComum(){  
    this->prox=NULL;
} 
void ContaComum::setNome(string nome){
    this->nome=nome;
}
string ContaComum::getNome(){
    return this-> nome;
}
void ContaComum::setNum_Conta(int Num_conta){
    this->Num_conta=Num_conta;
}
int ContaComum::getNum_Conta(){
    return this->Num_conta;
}
void ContaComum::setSaldo(float Saldo){
    this->Saldo=Saldo;
}
float ContaComum::getSaldo(){
    return this->Saldo;
}
void ContaComum:: setProx(ContaComum* prox){
    this->prox=prox;
}
ContaComum* ContaComum::getProx(){
    return this->prox;
}

void ContaComum::Deposito(double valor, string data, string descricao){

    if(valor>0){
        this->Saldo+=valor;
        this->Transacao+=data+" - Adicionou: "+to_string(valor)+" - "+descricao+"\n";
        cout<<this->Transacao;
    }
    else{
       cout<<"Valor inválido! Tente novamente"<<endl; 
    }

}

void ContaComum::Saque(double valor, string data, string descricao)
{
    
        this->Saldo-=valor;
        this->Transacao+=data+" - Retirou: "+to_string(valor)+" - "+descricao+"\n";
        cout<<this->Transacao;
  
}
void ContaComum::extrato(){
     cout<<this->Transacao;
 }