#ifndef __POUPANCA_HPP
#define __POUPANCA_HPP
#include<iostream> 
#include <string>
#include "ContaComum.hpp"
using namespace std;
class ContaPoupanca:public ContaComum {
private:
    string Niver;
    ContaPoupanca* prox;

public:
ContaPoupanca(string nome,int Num_conta,string Niver);
ContaPoupanca();

void setNiver(string Niver);
string getNiver();

ContaPoupanca* getProx();
void setProx(ContaPoupanca* prox);
 void extrato();
};
#endif