#include<iostream> 
#include "ListComum.hpp"
int ListContaComum:: deposito=0;
using namespace std;

ListContaComum::ListContaComum(){
    inicio = NULL;
	final = NULL;
}
ListContaComum::ListContaComum(string nome,int Num_conta){
    inicio = new ContaComum(nome, Num_conta);
	final = inicio;
}

bool ListContaComum::vazia() 
{
    return (inicio==NULL);
}
ListContaComum::~ListContaComum(){
    delete inicio;
}
ContaComum* ListContaComum::getInicio(){
    return this->inicio;
}
void ListContaComum::setInicio(ContaComum* inicio){
    this->inicio=inicio;
}
ContaComum* ListContaComum::getFinal(){
    return this->final;
}
void ListContaComum::setFinal(ContaComum* final){
    this->final=final;
}
void ListContaComum:: inserir_usuario(string nome,int Num_conta){
   ContaComum* usu=new ContaComum(nome, Num_conta);
   if(vazia())
   {
       inicio=usu;
       final=usu;
   }
   else{
       final->setProx(usu);
       final=usu;
   }
   
}

void ListContaComum::DepositoComum(int Num_conta){
    double valor;
    string data, descricao;
    int error=0;
    ContaComum* usu=inicio;
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

void ListContaComum:: imprimir_usuario(){
    ContaComum* usu=inicio;
     if(vazia())
   {
       inicio=usu;
       final=usu;
       cout<<"\n lista se encontra vazia \n";
   }
   else{
        while(usu){
            cout<<"O nome do correntista é: "<<usu->getNome()<<endl;
            cout<<"O numero da conta é: "<<usu->getNum_Conta()<<endl;
            cout<<"O saldo é: "<<usu->getSaldo()<<endl;
            cout<<"\n\tImprimindo o extrato...\n";
            usu->extrato();
            cout<<"\n================================================\n";
            usu=usu->getProx();
        }
   }
}

void ListContaComum:: SaqueComum(int Num_conta){
    double valor;
    string data, descricao;
    int error;
    ContaComum* usu=inicio;
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

