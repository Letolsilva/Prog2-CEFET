#ifndef __LISTA_PACIENTE_HPP
#define __LISTA_PACIENTE_HPP
#include "Paciente.hpp"
using namespace std;
class ListaPaciente{
private:
    Paciente* inicio;
    Paciente* fim;
    static int contPaci;
public:
    ListaPaciente(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, string relato, string ultimaConsulta, string medicacao);
    ListaPaciente();

    void InserirPaciente(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, string relato, string ultimaConsulta, string medicacao);
    void ImprimirPaciente();
    void RemoverPaciente(string cpf);
    virtual ~ListaPaciente();
    bool vazia();
    
    Paciente* getInicio();
    void setInicio(Paciente* inicio);
    Paciente* getFim();
    void setFim(Paciente* fim);
};
#endif