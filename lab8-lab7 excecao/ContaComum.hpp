#ifndef __CONTACOMUM_HPP
#define __CONTACOMUM_HPP
#include<iostream> 
#include <string>
#include "ExcessaoLimite.hpp"
using namespace std;
class ContaComum{
protected:
    string nome;
    int Num_conta;
    float Saldo;
    string Transacao;
    ContaComum* prox;

public:
    ContaComum();
    ContaComum(string nome,int Num_conta);
    

    void setNome(string nome);
    string getNome();

    void setNum_Conta(int Num_conta);
    int getNum_Conta();

    void setSaldo(float Saldo);
    float getSaldo();
    
    ContaComum* getProx();
    void setProx(ContaComum* prox);

   void Deposito(double valor, string data,string descricao);
   void Saque(double valor, string data, string descricao);
   void extrato();
};
#endif