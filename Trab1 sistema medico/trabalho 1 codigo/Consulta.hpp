#ifndef __CONSULTA_HPP
#define __CONSULTA_HPP
#include <string>
#include "Data.hpp"
using namespace std;
class Consulta{
private:
    Data* data;
    string hora;
    string cpfPaciente;
    int crmMedico;
    Consulta* prox;

public:
    Consulta(Data* data, string hora, string cpfPaciente, int crmMedico);
    Consulta();
    void setHora(string hora);
    string getHora();

    void setCpfPaciente(string cpfPaciente);
    string getCpfPaciente();

    void setCrmMedico(int crmMedico);
    int getCrmMedico();

    void setProx(Consulta* prox);
    Consulta* getProx();

    void setData(Data* data);
    Data* getData();

};
#endif
