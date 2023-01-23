#ifndef __LISTPOUPANCA_HPP
#define __LISTPOUPANCA_HPP
#include "Poupanca.hpp"

using namespace std;
class ListPoupanca{
protected:
    ContaPoupanca* inicio;
    ContaPoupanca* final;
   
public:
    ListPoupanca(string nome,int Num_conta, string Niver);
    ListPoupanca();

    void inserir_usuarioPoup(string nome,int Num_conta, string Niver);
    void imprimir_usuarioPoup();
    void DepositoPoup(int Num_conta);
    void SaquePoup(int Num_conta);
    bool vazia();
    virtual ~ListPoupanca();
    
    ContaPoupanca* getInicio();
    void setInicio(ContaPoupanca* inicio);
    ContaPoupanca* getFinal();
    void setFinal(ContaPoupanca* final);
};
#endif