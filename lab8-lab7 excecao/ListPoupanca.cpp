#include<iostream> 
#include "ListPoupanca.hpp"
using namespace std;
ListPoupanca::ListPoupanca(){
    inicio=NULL;
    final=NULL;
}

ListPoupanca::ListPoupanca(string nome,int Num_conta,string Niver){
    inicio = new ContaPoupanca(nome, Num_conta, Niver);
	final = inicio;
}
bool ListPoupanca::vazia() 
{
	return (inicio == NULL);
}
ListPoupanca::~ListPoupanca(){
    delete inicio;
}
ContaPoupanca* ListPoupanca::getInicio(){
    return this->inicio;
}
void ListPoupanca::setInicio(ContaPoupanca* inicio){
    this->inicio=inicio;
}
ContaPoupanca* ListPoupanca::getFinal(){
    return this->final;
}
void ListPoupanca::setFinal(ContaPoupanca* final){
    this->final=final;
}

void ListPoupanca:: inserir_usuarioPoup(string nome,int Num_conta,string Niver){
   ContaPoupanca* poup=new ContaPoupanca(nome, Num_conta, Niver);
   if(vazia())
   {
       inicio=poup;
       final=poup;
   }
   else{
       final->setProx(poup);
       final=poup;
   }

}
void ListPoupanca::DepositoPoup(int Num_conta){
    double valor;
    string data, descricao;
    int error;
    ContaPoupanca* usu=inicio;
    int controle=0;
    
    while(usu){
        if((usu->getNum_Conta()==Num_conta)){
            controle=1;
            break;
        }
         usu=usu->getProx();
    }
    if(controle==1){
    do{
        error=0;
        cout<< "Valor que deseja depositar: ";
        cin >> valor;
    if(cin.fail()){
        cout<<"Digite um inteiro valido"<<endl;
        error=1;
        cin.clear();
        cin.ignore(80,'\n');
    }
    }while (error==1);
        cout<<"Digite a data de hoje: ";
        cin>>data;
        cout<<"Digite a descriçao: ";
        cin>>descricao;
        usu->Deposito(valor, data, descricao);
    }
    else if(controle!=1){
        cout<<"\nUsuario não cadastrado\n";
    }
}

void ListPoupanca:: SaquePoup(int Num_conta){
    double valor;
    string data, descricao;
    int error;
    ContaPoupanca* usu=inicio;
    int controle=0;    
    while(usu){
        if((usu->getNum_Conta()==Num_conta)){
            controle=1;
            break;
        }
         usu=usu->getProx();
    }
     do{
        error=0;
        cout<< "Valor que deseja sacar: ";
        cin >> valor;
        if(cin.fail()){
        cout<<"Digite um inteiro valido"<<endl;
        error=1;
        cin.clear();
        cin.ignore(80,'\n');
        }
    }while (error==1);
    if(controle==1){
        try{
        cout<<"Digite a data de hoje: ";
        cin>>data;
        cout<<"Digite a descriçao: ";
        cin>>descricao;
        usu->Saque(valor, data, descricao);
        }
        catch(ExcessaoLimite &ex){
        cout<<ex.what()<<endl;
      }
    }
    else if(controle!=1){
        cout<<"\nUsuario não cadastrado\n";
        return;
    }
    if (usu->getSaldo()<valor){
        cout<<"\nVocê não possui este valor, escolha uma quantidade menor!\n";
    }
}


void ListPoupanca:: imprimir_usuarioPoup(){
    ContaPoupanca* poup=inicio;
    if(vazia()){
        inicio=poup;
        final=poup;
        cout<<"\n lista se encontra vazia \n";
    }
    else{
        while(poup){
    cout<<"O nome do correntista é: "<<poup->getNome()<<endl;
    cout<<"O numero da conta é: "<<poup->getNum_Conta()<<endl;
    cout<<"O saldo é: "<<poup->getSaldo()<<endl;
    cout<<"O aniversario da conta é: "<<poup->getNiver()<<endl;
    cout<<"\n\tImprimindo extrato...\n";
    poup->extrato();
    cout<<"\n=====================================================\n";
    poup=poup->getProx();
        }
    }
}

