#include<iostream> 
#include "Consulta.hpp"
using namespace std;

Consulta::Consulta(Data* data, string hora, string cpfPaciente, int crmMedico){
    this->data=data;
    this->hora=hora;
    this->cpfPaciente=cpfPaciente;
    this->crmMedico=crmMedico;
    this -> prox = NULL;
}
Consulta::Consulta(){
    this -> prox = NULL;
}

void Consulta::setData(Data* data){
    this->data=data;
}
Data* Consulta::getData(){
    return this->data;
}

void Consulta::setHora(string hora){
    this->hora=hora;
}
string Consulta::getHora(){
    return this->hora;
}

void Consulta::setCpfPaciente(string cpfPaciente){
    this->cpfPaciente=cpfPaciente;
}
string Consulta::getCpfPaciente(){
    return this->cpfPaciente;
}
void Consulta::setCrmMedico(int crmMedico){
    this->crmMedico=crmMedico;
}
int Consulta::getCrmMedico(){
    return this->crmMedico;
}
void Consulta::setProx(Consulta* prox){
    this->prox=prox;
}
Consulta* Consulta::getProx(){
    return this->prox;
}
