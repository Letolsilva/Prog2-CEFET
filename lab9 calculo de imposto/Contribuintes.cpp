#include<iostream> 
#include "contribuintes.hpp"
using namespace std;
Contribuintes::Contribuintes(Lista_fis* fisicos, Lista_juri* juridicos)
{
    this->fisicos=fisicos;
    this->juridicos=juridicos;
}
Contribuintes::Contribuintes(){
    this->fisicos=new Lista_fis();
    this->juridicos= new Lista_juri();
}
void Contribuintes::inserirFisico(){
    string nome, cpf;
    int renda;
    PF* fisico=NULL;
    PF* fisio=fisicos->getInicio();
    cout<<"\t* Vamos verificar se ja esta cadastrado *\t";
    cout<<"\nDigite o cpf da pessoa: ";
    getline(cin, cpf);
    
    while(fisio)
    {
        if(fisio->getCpf()==cpf){
            fisico=fisio;
            cout<<"\n Pessoa fisica ja cadastrada \n";
            return;
        }
        fisio=fisio->getProx();
    }
    
      if(fisico==NULL)
    {
        cout<<"\n\n";
        cout<<"\tSEJA BEM VINDO AO CADASTRO PESSOA FISICA!\t";
        cout<<"\n\n";
        cout<<"\tIrei precisar de algumas informaçoes\t";
        cout<<"\n-> Informe o nome completo: ";
        getline(cin, nome);
        cout<<"Informe o cpf: ";
        getline(cin, cpf);
        cout<<"Informe sua renda: ";
        cin>>renda;
        fisicos->inserir(nome, cpf, renda);
        fisicos->Calcularimposto(renda, cpf);

    }
}
void Contribuintes::imprimirFisico(){
    cout << "\tImprimindo ...\t\n";
	fisicos->imprimir();
}
void Contribuintes::calcularimpostoFisico(){
    string cpf;
    PF* fisico=fisicos->getInicio();
    cout<<" \t* CALCULANDO O IMPOSTO *\t";
    cout<<"\nDigite o cpf: ";
    cin>> cpf;
    while (fisico)
    {
        if(fisico->getCpf()==cpf){
        fisicos->Calcularimposto(fisico->getRenda(), fisico->getCpf());

        }
        fisico=fisico->getProx();
    }
}
void Contribuintes::inserirJuridico(){
    string nome, cnpj;
    int renda;
    PJ* juridico=NULL;
    PJ* juri=juridicos->getInicio();
    cout<<"\t* Vamos verificar se ja esta cadastrado *\t";
    cout<<"\nDigite o cnpj da pessoa: ";
    getline(cin, cnpj);
    
    while(juri)
    {
        if(juri->getCnpj()==cnpj){
            juridico=juri;
            cout<<"\n Pessoa juridica ja cadastrada \n";
            return;
        }
        juri=juri->getProx();
    }
    
      if(juridico==NULL)
    {
        cout<<"\n\n";
        cout<<"\tSEJA BEM VINDO AO CADASTRO PESSOA JURIDICA!\t";
        cout<<"\n\n";
        cout<<"\tIrei precisar de algumas informaçoes\t";
        cout<<"\n-> Informe o nome completo: ";
        getline(cin, nome);
        cout<<"Informe o CNPJ: ";
        getline(cin, cnpj);
        cout<<"Informe a renda da empresa: ";
        cin>>renda;
        juridicos->inserir(nome,cnpj,renda);
        juridicos->Calcularimposto(renda, cnpj);
    }
}
void Contribuintes::imprimirJuridico(){
    cout << "\tImprimindo ...\t\n";
	juridicos->imprimir();
}
void Contribuintes::calcularimpostoJuridico(){
    string cnpj;
    PJ* juridico=juridicos->getInicio();
    cout<<" \t* CALCULANDO O IMPOSTO *\t";
    cout<<"\nDigite o CNPJ: ";
    cin>> cnpj;
    
    while (juridico)
    {
        if(juridico->getCnpj()==cnpj){
        juridicos->Calcularimposto(juridico->getRenda(), juridico->getCnpj());
        
        }
        juridico=juridico->getProx();
        
    }
    
}

void Contribuintes::RemoverFisico(string cpf){
    fisicos->removerfisica(cpf);
    cout<<"\nPessoa fisica removida\n";
}
void Contribuintes::RemoverJuri(string cnpj){
    juridicos->removerjuri(cnpj);
    cout<<"\nPessoa juridica removida\n";
}