#include <locale>
#include <iostream>
#include "ContaComum.hpp"
#include "ListComum.hpp"
#include "ListLimite.hpp"
#include "ListPoupanca.hpp"
int main()
{
    int resp,valor, Num_conta, limite;
    string nome, niver;
    float saldin;
	ListContaComum* cons=new ListContaComum();
    ListLimite* cc=new ListLimite();
    ListPoupanca* cp=new ListPoupanca();

    do{
        cout<<"\t====================AREA DE OPÇOES============================\t";
        cout<<"\nDigite o numero do item que deseja realizar";
        cout<<"\t\n 1- Inserir Usuario na conta Comum"<<endl;
        cout<<"\t\n 2- Realizar um deposito na conta comum"<<endl;
        cout<<"\t\n 3- Realizar um Saque na conta comum"<<endl;
        cout<<"\t\n 4- Imprimir extrato da conta comum"<<endl;
        cout<<"\t\n 5- Inserir Usuario na conta corrente"<<endl;
        cout<<"\t\n 6- Realizar um deposito na conta corrente"<<endl;
        cout<<"\t\n 7- Realizar um saque na conta corrente"<<endl;
        cout<<"\t\n 8- Imprimir extrato da conta corrente"<<endl;
        cout<<"\t\n 9- Inserir Usuario na conta poupança"<<endl;
        cout<<"\t\n 10- Realizar um deposito na conta poupança"<<endl;
        cout<<"\t\n 11- Realizar um saque na conta poupança"<<endl;
        cout<<"\t\n 12- Imprimir extrato da conta poupança"<<endl;
        cout<<"\t\n 0-  Sair"<<endl;
        cout<<"\n";
        cin>>resp;

        switch(resp){
            case 1:
                cout<<"Digite o nome : ";
                cin>>nome;
                cout<<"Digite o numero da conta: ";
                cin>>Num_conta;
                cons->inserir_usuario(nome, Num_conta);
            break;
            case 2:
                cout<<"\t* Vamos verificar se este usuario ja esta cadastrado *\t";
                cout<<"\nDigite o codigo da pessoa: ";
                cin>>Num_conta;
                cons->DepositoComum(Num_conta);         
				break;
            case 3:
                cout<<"\t* Vamos verificar se este usuario ja esta cadastrado *\t";
                cout<<"\nDigite o codigo da pessoa: \n";
                cin>>Num_conta;
                cons->SaqueComum(Num_conta);
                break;
            case 4:
                cons->imprimir_usuario();
                break;
            case 5:
                cout<<"Digite o nome : ";
                cin>>nome;
                cout<<"Digite o numero da conta: ";
                cin>>Num_conta;
                cout<<"Digite o limite de credito: ";
                cin>>limite;
                cc->inserir_usuario(nome, Num_conta, limite);
                break;
            case 6:
                cout<<"\t* Vamos verificar se este usuario ja esta cadastrado *\t";
                cout<<"\nDigite o codigo da pessoa: \n";
                cin>>Num_conta;
                cc->DepositoCorrente(Num_conta);
                break;
            case 7:
                cout<<"\t* Vamos verificar se este usuario ja esta cadastrado *\t";
                cout<<"\nDigite o codigo da pessoa: \n";
                cin>>Num_conta;
                cc->SaqueCorrente(Num_conta);
                break;
            case 8:
                cc->imprimir_usuariocorrente();
                break;
            case 9:
                cout<<"Digite o nome : ";
                cin>>nome;
                cout<<"Digite o numero da conta: ";
                cin>>Num_conta;
                cout<<"Digite o aniversario da conta: ";
                cin>>niver;
                cp->inserir_usuarioPoup(nome, Num_conta, niver);
                break;
            case 10:
                cout<<"\t* Vamos verificar se este usuario ja esta cadastrado *\t";
                cout<<"\nDigite o codigo da pessoa: \n";
                cin>>Num_conta;
                cp->DepositoPoup(Num_conta);
                break;
            case 11:
                cout<<"\t* Vamos verificar se este usuario ja esta cadastrado *\t";
                cout<<"\nDigite o codigo da pessoa: \n";
                cin>>Num_conta;
                cp->SaquePoup(Num_conta);
                break;
            case 12:
                cp->imprimir_usuarioPoup();
                break;
			case 0:
				cout<<"\nSaindo...\n";
				break;
        }
    }while(resp!=0);
	
	return 0;
}