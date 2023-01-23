#include<iostream> 
#include "Lista_Paciente.hpp"
int ListaPaciente:: contPaci=1;
using namespace std;

ListaPaciente::ListaPaciente(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, string relato, string ultimaConsulta, string medicacao){
    inicio = new Paciente(nome, sexo, endereco, cpf, telefone, identidade, relato, ultimaConsulta, medicacao); 
	fim = inicio;  
}
ListaPaciente::ListaPaciente(){
    inicio = NULL;
	fim = NULL;
}

bool ListaPaciente::vazia() 
{
    return (inicio==NULL);
}
ListaPaciente::~ListaPaciente(){
    delete inicio;
}

Paciente* ListaPaciente::getInicio(){
    return this->inicio;
}
void ListaPaciente::setInicio(Paciente* inicio){
    this->inicio=inicio;
}
Paciente* ListaPaciente::getFim(){
    return this->fim;
}
void ListaPaciente::setFim(Paciente* fim){
    this->fim=fim;
}
void ListaPaciente:: InserirPaciente(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, string relato, string ultimaConsulta, string medicacao){
   Paciente* paci=new Paciente(nome,sexo,endereco,cpf,telefone,identidade,relato, ultimaConsulta, medicacao); 
   if(vazia())
   {
       inicio=paci;
       fim=paci;
   }
   else{
       fim->setProx(paci);
       fim=paci;
   }
   
}
void ListaPaciente::RemoverPaciente(string cpf){

    if(vazia())
	cout << "Não há nenhum paciente agendado\n";
	else if(inicio->getProx()==NULL && inicio->getCpf()==cpf)
		inicio=NULL;
	else if(inicio->getProx()->getProx()==NULL && inicio->getCpf()==cpf){
		inicio=inicio->getProx();
	}
	else if(inicio->getProx()->getProx()==NULL && inicio->getProx()->getCpf()==cpf){
		inicio->setProx(NULL);
        fim=inicio;
	}
	else{
		Paciente* iant=inicio;
		Paciente* i=inicio->getProx();
		Paciente* iprox=inicio->getProx()->getProx();
		while(iprox){
			if(inicio->getCpf()==cpf){
				inicio=inicio->getProx();
			}
			else if(i->getCpf()==cpf){
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->getProx();
		}
		if(i->getCpf()==cpf)
        {
			iant->setProx(NULL);
			free(i);
			fim=iant;
	    }
    }
}

void ListaPaciente:: ImprimirPaciente(){
    int aux=0;
    aux=contPaci;
    Paciente* paci=inicio;
     if(vazia())
   {
       inicio=paci;
       fim=paci;
       cout<<"\n Não tem pacientes cadastrados!! \n";
   }
   else{
        while(paci){
        cout<<"----------------Paciente "<<aux++<<"----------------";
        cout<<endl;
        cout << "O nome é: " << paci->getNome() << endl;
        cout << "O sexo é: " << paci->getSexo() << endl;
        cout << "O endereço é: "<< paci->getEndereco() << endl;
        cout << "O cpf é: " << paci->getCpf() << endl;
        cout << "O telefone é: " << paci->getTelefone() << endl;
        cout << "A identidade é: "<< paci->getIdentidade() << endl;
        cout << "O relato é: " << paci->getRelato() << endl;
        cout << "A Ultima consulta foi: " << paci->getUltimaConsulta() << endl;
        cout << "A medicaçao é: " << paci->getMedicacao() << endl;
        cout<<endl;
        cout<<"---------------------------------------------------\n";
        paci=paci->getProx();
        }
   }
}