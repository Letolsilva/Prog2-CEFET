#ifndef __PACIENTE_HPP
#define __PACIENTE_HPP
#include <string>
#include "Pessoa.hpp"
using namespace std;
class Paciente:public Pessoa {
private:
    string relato;
    string ultimaConsulta;
    string medicacao;
    Paciente* prox;

public:
    Paciente(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, string relato, string ultimaConsulta, string medicacao);
    Paciente();

    void setRelato(string relato);
    string getRelato();

    void setUltimaConsulta(string ultimaConsulta);
    string getUltimaConsulta();

    void setMedicacao(string medicacao);
    string getMedicacao();

    void setProx(Paciente* prox);
    Paciente* getProx();

};
#endif