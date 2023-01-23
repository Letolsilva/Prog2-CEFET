#ifndef __LISTCOMUM_HPP
#define __LISTCOMUM_HPP
#include "ContaComum.hpp"

using namespace std;
class ListContaComum{
protected:
    ContaComum* inicio;
    ContaComum* final;
    static int deposito;
public:
    ListContaComum(string nome,int Num_conta);
    ListContaComum();

    void inserir_usuario(string nome,int Num_conta);
    void imprimir_usuario();
    void DepositoComum(int Num_conta);
    void SaqueComum(int Num_conta);
    bool vazia();
    virtual ~ListContaComum();
    
    ContaComum* getInicio();
    void setInicio(ContaComum* inicio);
    ContaComum* getFinal();
    void setFinal(ContaComum* final);
};
#endif