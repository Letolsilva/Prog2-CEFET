#ifndef __MEDICO_HPP
#define __MEDICO_HPP
#include <string>
#include "Pessoa.hpp"
using namespace std;
class Medico:public Pessoa {
private:
    int crm;
    string especialidade;
    Medico* prox;

public:
    Medico(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, int crm, string especialidade);
    Medico();

    void setCrm(int crm);
    int getCrm();

    void setEspecialidade(string especialidade);
    string getEspecialidade();

    void setProx(Medico* prox);
    Medico* getProx();
};
#endif