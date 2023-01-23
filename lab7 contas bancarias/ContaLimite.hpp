#ifndef __CONTALIMITE_HPP
#define __CONTALIMITE_HPP
#include<iostream> 
#include <string>
#include "ContaComum.hpp"
using namespace std;
class ContaLimite:public ContaComum {
private:
    double Valor_lim;
    double ValorFixo;
    ContaLimite* prox;

public:
ContaLimite(string nome,int Num_conta, double Valor_lim);
ContaLimite();

void setValor_Lim(double Valor_lim);
double getValor_Lim();

void setValorFix(double ValorFixo);
double getValorFix();

ContaLimite* getProx();
void setProx(ContaLimite* prox);

void Deposito(double valor, string data, string descricao);
void Saque(double valor, string data, string descricao);
void extrato();

};
#endif