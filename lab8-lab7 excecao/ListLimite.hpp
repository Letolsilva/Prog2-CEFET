#ifndef __LISTLIMITE_HPP
#define __LISTLIMITE_HPP
#include "ContaLimite.hpp"
#include "ExcessaoLimite.hpp"
using namespace std;
class ListLimite{
protected:
    ContaLimite* inicio;
    ContaLimite* final;
   
public:
    ListLimite(string nome,int Num_conta,double Valor_lim);
    ListLimite();

    void inserir_usuario(string nome,int Num_conta, double Valor_lim);
    void imprimir_usuariocorrente();
    void DepositoCorrente(int Num_conta);
    void SaqueCorrente(int Num_conta);
    bool vazia();
    virtual ~ListLimite();
    
    ContaLimite* getInicio();
    void setInicio(ContaLimite* inicio);
    ContaLimite* getFinal();
    void setFinal(ContaLimite* final);
};
#endif