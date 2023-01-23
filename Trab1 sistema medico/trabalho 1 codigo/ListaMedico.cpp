#include<iostream> 
#include "Lista_Medico.hpp"
int ListaMedico:: contMed=1;
using namespace std;

ListaMedico::ListaMedico(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, int crm, string especialidade){
    inicio = new Medico( nome,sexo,endereco, cpf,telefone,identidade,crm,especialidade); //perguntar
	fim = inicio;  
}
ListaMedico::ListaMedico(){
    inicio = NULL;
	fim = NULL;
}

bool ListaMedico::vazia() 
{
    return (inicio==NULL);
}
ListaMedico::~ListaMedico(){
    delete inicio;
}

Medico* ListaMedico::getInicio(){
    return this->inicio;
}
void ListaMedico::setInicio(Medico* inicio){
    this->inicio=inicio;
}
Medico* ListaMedico::getFim(){
    return this->fim;
}
void ListaMedico::setFim(Medico* fim){
    this->fim=fim;
}
void ListaMedico:: InserirMedico(string nome,string sexo, string endereco, string cpf, string telefone, string identidade, int crm, string especialidade){
   Medico* med=new Medico(nome,sexo,endereco,cpf,telefone,identidade,crm, especialidade); 
   if(vazia())
   {
       inicio=med;
       fim=med;
   }
   else{
       fim->setProx(med);
       fim=med;
   }
   
}
void ListaMedico::RemoverMedico(int crm){

    if(vazia())
	cout << "Não há nenhum medico\n";
	else if(inicio->getProx()==NULL && inicio->getCrm()==crm)
		inicio=NULL;
	else if(inicio->getProx()->getProx()==NULL && inicio->getCrm()==crm){
		inicio=inicio->getProx();
	}
	else if(inicio->getProx()->getProx()==NULL && inicio->getProx()->getCrm()==crm){
		inicio->setProx(NULL);
        fim=inicio;
	}
	else{
		Medico* iant=inicio;
		Medico* i=inicio->getProx();
		Medico* iprox=inicio->getProx()->getProx();
		while(iprox){
			if(inicio->getCrm()==crm){
				inicio=inicio->getProx();
			}
			else if(i->getCrm()==crm){
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->getProx();
		}
		if(i->getCrm()==crm)
        {
			iant->setProx(NULL);			
			fim=iant;
            free(i);
	    }
    }
}

void ListaMedico:: ImprimirMedico(){
    Medico* med=inicio;
    int aux=0;
    aux=contMed;
     if(vazia())
   {
       inicio=med;
       fim=med;
       cout<<"\n Não há medicos cadastrados!! \n";
   }
   else{
        while(med){
        cout<<"-----------------medicos: "<<aux++<<"-------------------";
        cout<<endl;
        cout << "O nome é: " << med->getNome() << endl;
        cout << "O sexo é: " << med->getSexo() << endl;
        cout << "O endereço é: "<< med->getEndereco() << endl;
        cout << "O cpf é: " << med->getCpf() << endl;
        cout << "O telefone é: " << med->getTelefone() << endl;
        cout << "A identidade é: "<< med->getIdentidade() << endl;
        cout << "O CRM é: " << med->getCrm() << endl;
        cout << "A especialidade é: " << med->getEspecialidade() << endl;
        cout<<endl;
        cout<<"--------------------------------------------------------------\n";
        med=med->getProx();
        }
   }
}