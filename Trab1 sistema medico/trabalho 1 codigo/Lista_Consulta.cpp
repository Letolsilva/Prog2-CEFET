#include<iostream> 
#include "Lista_Consulta.hpp"
using namespace std;

ListaConsulta::ListaConsulta(Data* data, string hora, string cpfPaciente, int crmMedico){
    inicio = new Consulta(data, hora, cpfPaciente, crmMedico); //perguntar
	fim = inicio;  
}
ListaConsulta::ListaConsulta(){
    inicio = NULL;
	fim = NULL;
}

bool ListaConsulta::vazia() 
{
    return (inicio==NULL);
}
ListaConsulta::~ListaConsulta(){
    delete inicio;
}

Consulta* ListaConsulta::getInicio(){
    return this->inicio;
}
void ListaConsulta::setInicio(Consulta* inicio){
    this->inicio=inicio;
}
Consulta* ListaConsulta::getFim(){
    return this->fim;
}
void ListaConsulta::setFim(Consulta* fim){
    this->fim=fim;
}
void ListaConsulta:: InserirConsulta(Data* data, string hora, string cpfPaciente, int crmMedico){
   Consulta* cons=new Consulta(data, hora, cpfPaciente, crmMedico);
   if(vazia())
   {
       inicio=cons;
       fim=cons;
   }
   else if(!existe(data->getDia(), data->getMes(), data->getAno(), hora,crmMedico, cpfPaciente)){
        fim->setProx(cons);
        fim=cons;
   }
    else{
        cout<<"Consulta ja existe neste dia e horario\n";
    }
   
}
void ListaConsulta::RemoverConsulta(string cpfPaciente){


    if(vazia())
	cout << "Não há nenhum paciente agendado para consulta\n";
	else if(inicio->getProx()==NULL && inicio->getCpfPaciente()==cpfPaciente)
		inicio=NULL;
	else if(inicio->getProx()->getProx()==NULL && inicio->getCpfPaciente()==cpfPaciente){
		inicio=inicio->getProx();
	}
	else if(inicio->getProx()->getProx()==NULL && inicio->getProx()->getCpfPaciente()==cpfPaciente){
		inicio->setProx(NULL);
		fim=inicio;
	}
	else{
		Consulta* iant=inicio;
		Consulta* i=inicio->getProx();
		Consulta* iprox=inicio->getProx()->getProx();
		while(iprox){
			if(inicio->getCpfPaciente()==cpfPaciente){
				inicio=inicio->getProx();
			}
			else if(i->getCpfPaciente()==cpfPaciente){
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->getProx();
		}
		if(i->getCpfPaciente()==cpfPaciente)
        {
			iant->setProx(NULL);
			free(i);
			fim=iant;
	    }
    }
}

void ListaConsulta::RemoverConsultaMED(int crmMedico){


    if(vazia())
	cout << "Não há nenhum paciente agendado para consulta\n";
	else if(inicio->getProx()==NULL && inicio->getCrmMedico()==crmMedico)
		inicio=NULL;
	else if(inicio->getProx()->getProx()==NULL && inicio->getCrmMedico()==crmMedico){
		inicio=inicio->getProx();
	}
	else if(inicio->getProx()->getProx()==NULL && inicio->getProx()->getCrmMedico()==crmMedico){
		inicio->setProx(NULL);
	}
	else{
		Consulta* iant=inicio;
		Consulta* i=inicio->getProx();
		Consulta* iprox=inicio->getProx()->getProx();
		while(iprox){
			if(inicio->getCrmMedico()==crmMedico){
				inicio=inicio->getProx();
			}
			else if(i->getCrmMedico()==crmMedico){
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->getProx();
		}
		if(i->getCrmMedico()==crmMedico)
        {
			iant->setProx(NULL);
			free(i);
			fim=iant;
	    }
    }
}

void ListaConsulta:: ImprimirConsulta(){
    Consulta* cons=inicio;
     if(vazia())
   {
       inicio=cons;
       fim=cons;
       cout<<"\n Não ha consultas!! \n";
   }
   else{
        while(cons){
        cout<<"=====================================================";
        cout<<endl;
        cout << "O dia é: " << cons->getData()->getDia() << endl;
        cout << "O mes é: " << cons->getData()->getMes() << endl;
        cout << "O ano é: "<< cons->getData()->getAno() << endl;
        cout << "O horario é: " << cons->getHora() << endl;
        cout << "O CPF do paciente é: " << cons->getCpfPaciente() << endl;
        cout << "O CRM do medico é: "<< cons->getCrmMedico() << endl;
        cout<<endl;
        cout<<"=====================================================";
        cons=cons->getProx();
        }
   }
}

bool ListaConsulta::existe(int dia,int mes,int ano,string hora,int crm, string cpfPaciente)
{
    if(vazia())
    return false;

    Consulta*aux= inicio;

    while(aux)
    {
        if(aux->getCrmMedico()==crm && aux->getData()->getDia()==dia && aux->getData()->getMes()==mes && aux->getData()->getAno()==ano && aux->getHora()==hora)
        {
            return true;
        }
        aux=aux->getProx();
    }
	aux=inicio;
	while(aux)
    {
        if(aux->getCpfPaciente()==cpfPaciente && aux->getData()->getDia()==dia && aux->getData()->getMes()==mes && aux->getData()->getAno()==ano && aux->getHora()==hora)
        {
            return true;
        }
        aux=aux->getProx();
    }
    return false;
}