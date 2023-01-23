#include <locale>
#include <iostream>
#include "contribuintes.hpp"
int main()
{
    int resp;
    string cpf, cnpj;
	Contribuintes* contribu=new Contribuintes();
    do{
        cout<<"\t********************** SEJA BEM VINDO ****************************\t";
        cout<<"\nDigite o numero do item que deseja realizar";
        cout<<"\t\n 1- Inserir pessoa fisica"<<endl;
        cout<<"\t\n 2- Imprimir pessoa fisica"<<endl;
        cout<<"\t\n 3- Calcular imposto da pessoa fisica"<<endl;
        cout<<"\t\n 4- Inserir pessoa juridica"<<endl;
        cout<<"\t\n 5- Imprimir pessoa juridica"<<endl;
        cout<<"\t\n 6- Calcular imposto da pessoa juridica"<<endl;
        cout<<"\t\n 7- Remover pessoa fisica"<<endl;
        cout<<"\t\n 8- Remover pessoa juridica"<<endl;
        cout<<"\t\n 0-Sair"<<endl;
    
        cout<<"******************************************************************\n";
        cin>>resp;

        switch(resp){
            case 1:
                cin.ignore();
				contribu->inserirFisico();        
				break;
            case 2:
                contribu->imprimirFisico();
                break;
            case 3:
                contribu->calcularimpostoFisico();
    			break;
            case 4:
                cin.ignore();
                contribu->inserirJuridico();
                break;
            case 5:
                contribu->imprimirJuridico();
                break;
            case 6:
                contribu->calcularimpostoJuridico();
                break;
            case 7:
                cout<<"Digite o cpf da pessoa fisica que deseja remover: "<<endl;
                cin.ignore();
                getline(cin, cpf);
                contribu->RemoverFisico(cpf);
                break;
            case 8:
                cout<<"Digite o cnpj da pessoa juridica que deseja remover: "<<endl;
                cin.ignore();
                getline(cin, cnpj);
                contribu->RemoverJuri(cnpj);
                break;
            case 0:
                cout<<"Obrigada por utilizar este programa \n saindo...";
                break;
        }
    }while(resp!=0);
	
	return 0;
}