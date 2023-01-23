#include<iostream> 
#include "ListLimite.hpp"
using namespace std;
ListLimite::ListLimite(){
    inicio=NULL;
    final=NULL;
}

ListLimite::ListLimite(string nome,int Num_conta, double Valor_lim){
    inicio = new ContaLimite(nome, Num_conta, Valor_lim);
	final = inicio;
}
bool ListLimite::vazia() 
{
	return (inicio == NULL);
}
ListLimite::~ListLimite(){
    delete inicio;
}
ContaLimite* ListLimite::getInicio(){
    return this->inicio;
}
void ListLimite::setInicio(ContaLimite* inicio){
    this->inicio=inicio;
}
ContaLimite* ListLimite::getFinal(){
    return this->final;
}
void ListLimite::setFinal(ContaLimite* final){
    this->final=final;
}

void ListLimite:: inserir_usuario(string nome,int Num_conta,double Valor_lim){
   ContaLimite* lim=new ContaLimite(nome, Num_conta, Valor_lim);
   if(vazia())
   {
       inicio=lim;
       final=lim;
   }
   else{
       final->setProx(lim);
       final=lim;
   }

}

void ListLimite::DepositoCorrente(int Num_conta){
    double valor;
    string data, descricao;
    int error;
    ContaLimite* usu=inicio;
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
        cout<<"\nDeposito realizado com sucesso!\n";
    }
    else if(controle!=1){
        cout<<"\nUsuario não cadastrado\n";
        
    }
}
void ListLimite:: SaqueCorrente(int Num_conta){
    double valor;
    string data, descricao;
    ContaLimite* usu=inicio;
    int controle=0, error;    
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
            usu->Saque(valor, data,descricao);
        }
        catch(ExcessaoLimite &ex){
            cout<<ex.what()<<endl;
        }
        }
    
    else if(controle!=1){
        cout<<"\nUsuario não cadastrado\n";
        return;
    }
    

}

void ListLimite:: imprimir_usuariocorrente(){
    ContaLimite* lim=inicio;
    if(vazia()){
        inicio=lim;
        final=lim;
        cout<<"\n lista se encontra vazia \n";
    }
    else{
        while(lim){
    cout<<"O nome do correntista é: "<<lim->getNome()<<endl;
    cout<<"O numero da conta é: "<<lim->getNum_Conta()<<endl;
    cout<<"O saldo é: "<<lim->getSaldo()<<endl;
    cout<<"O limite restante é: "<<lim->getValor_Lim()<<endl;
    cout<<"O limite inicial é: "<<lim->getValorFix()<<endl;
    cout<<"\n\tImprimindo extrato...\n";
    lim->extrato();
    cout<<"\n===============================================\n";
    lim=lim->getProx();
        }
    }
}

