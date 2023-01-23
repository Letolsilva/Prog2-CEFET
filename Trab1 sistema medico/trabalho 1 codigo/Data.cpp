#include<iostream> 
#include "Data.hpp"
using namespace std;

Data::Data(int dia, int mes, int ano){
    this->dia=dia;
    this->mes=mes;
    this->ano=ano;
    
}
Data::Data(){
    
}

void Data::setDia(int dia){
    this->dia=dia;
}
int Data::getDia(){
    return this->dia;
}

void Data::setMes(int mes){
    this->mes=mes;
}
int Data::getMes(){
    return this->mes;
}
void Data::setAno(int ano){
    this->ano=ano;
}
int Data::getAno(){
    return this->ano;
}