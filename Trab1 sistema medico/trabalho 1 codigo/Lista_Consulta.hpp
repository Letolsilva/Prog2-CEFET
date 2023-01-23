#ifndef __LISTA_CONSULTA_HPP
#define __LISTA_CONSULTA_HPP
#include "Consulta.hpp"

using namespace std;
class ListaConsulta{
private:
    Consulta* inicio;
    Consulta* fim;
public:
    ListaConsulta(Data* data, string hora, string cpfPaciente, int crmMedico);
    ListaConsulta();

    void InserirConsulta(Data* data, string hora, string cpfPaciente, int crmMedico);
    void ImprimirConsulta();
    void RemoverConsulta(string cpfPaciente);
    void RemoverConsultaMED(int crmMedico);
    virtual ~ListaConsulta();
    bool vazia();
    

bool existe(int dia,int mes,int ano,string hora,int crm, string cpfPaciente);
    Consulta* getInicio();
    void setInicio(Consulta* inicio);
    Consulta* getFim();
    void setFim(Consulta* fim);
};
#endif