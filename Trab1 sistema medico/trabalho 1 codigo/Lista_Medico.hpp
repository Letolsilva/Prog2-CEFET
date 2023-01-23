#ifndef __LISTA_MEDICO_HPP
#define __LISTA_MEDICO_HPP
#include "Medico.hpp"
using namespace std;
class ListaMedico{
private:
    Medico* inicio;
    Medico* fim;
    static int contMed;
public:
    ListaMedico(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, int crm, string especialidade);
    ListaMedico();

    void InserirMedico(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, int crm, string especialidade);
    void ImprimirMedico();
    void RemoverMedico(int crm);
    virtual ~ListaMedico();
    bool vazia();
    
    Medico* getInicio();
    void setInicio(Medico* inicio);
    Medico* getFim();
    void setFim(Medico* fim);
};
#endif