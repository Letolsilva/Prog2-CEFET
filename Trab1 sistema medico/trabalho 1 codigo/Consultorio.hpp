#ifndef __CONSULTORIO_HPP
#define __CONSULTORIO_HPP
#include <string>
#include "Lista_Medico.hpp"
#include "Lista_Paciente.hpp"
#include "Lista_Consulta.hpp"
using namespace std;
class Consultorio {
private:
   ListaMedico* medicos;
   ListaPaciente* pacientes;
   ListaConsulta* consultas;
   string nomeConsultorio;
   string enderecoConsultorio;
   int telefoneConsultorio;
   static int contPaciente;
public:
    Consultorio(ListaMedico* medicos, ListaPaciente* pacientes, ListaConsulta* consultas, string nomeConsultorio, string enderecoConsultorio, int telefoneConsultorio);
    Consultorio();
    void setNomeConsultorio(string nomeConsultorio);
    string getNomeConsultorio();
    void setEnderecoConsultorio(string enderecoConsultorio);
    string getEnderecoConsultorio();
    void setTelefoneConsultorio(int telefoneConsultorio);
    int getTelefoneConsultorio();

    void CadastrarPaciente();
    void RemoverPaciente(string cpf);
    void CadastrarMedico();
    void RemoverMedico(int crm);
    void CadastrarConsulta();
    void RemoverConsulta(string cpfPaciente);
    void RemoverConsultaMedica(int crmMedicos);
    void ImprimirPacientes();
    void ImprimirConsultas();
    void ImprimirConsultaMedicos();
    void ImprimirMedicos();
    void Imprimirdadosconsultorio();
    
};
#endif