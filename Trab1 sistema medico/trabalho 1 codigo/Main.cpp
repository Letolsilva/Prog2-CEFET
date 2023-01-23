#include <locale>
#include <iostream>
#include "Consultorio.hpp"
int main()
{
    int ch, resp,CrmRemove;
    string CpfRemove, ConsuRemove;
	Consultorio* cons=new Consultorio();
    do{
        cout<<"\t********************** SEJA BEM VINDO ****************************\t";
        cout<<"\nDigite o numero do item que deseja realizar";
        cout<<"\t\n 1- Inserir paciente"<<endl;
        cout<<"\t\n 2- Imprimir paciente"<<endl;
        cout<<"\t\n 3- Remover paciente"<<endl;
        cout<<"\t\n 4- Cadastrar medico"<<endl;
        cout<<"\t\n 5- Imprimir medico"<<endl;
        cout<<"\t\n 6- Remover medico"<<endl;
        cout<<"\t\n 7- Cadastrar consulta"<<endl;
        cout<<"\t\n 8- Imprimir consulta"<<endl;
        cout<<"\t\n 9- Remover Consulta"<<endl;
        cout<<"\t\n 10-Imprimir consulta medico"<<endl;
        cout<<"\t\n 11-Imprimir dados do consultorio"<<endl;
        cout<<"\t\n 0-Sair"<<endl;
    
        cout<<"******************************************************************\n";
        cin>>resp;

        switch(resp){
            case 1:
                cin.ignore();
				cons->CadastrarPaciente();         
				break;
            case 2:
                cons->ImprimirPacientes();
                break;
            case 3:
                cout<<"Digite o cpf do paciente que deseja remover: "<<endl;
                cin.ignore();
                getline(cin, CpfRemove);
                cons->RemoverPaciente(CpfRemove);
                cons->RemoverConsulta(CpfRemove);
                break;
            case 4:
                cin.ignore();
                cons->CadastrarMedico();
                break;
            case 5:
                cons->ImprimirMedicos();
                break;
            case 6:
                cout<<"Digite o CRM do medico que deseja remover: "<<endl;
                cin>> CrmRemove;
                cons->RemoverMedico(CrmRemove);
                cons->RemoverConsultaMedica(CrmRemove);
                break;
            case 7:
                cons->CadastrarConsulta();
                break;
            case 8: 
                cons->ImprimirConsultas();
                break;
            case 9:
                cout<<"Digite o cpf do paciente que deseja remover a consulta: "<<endl;
                cin.ignore();
                getline(cin, ConsuRemove);
                cons->RemoverConsulta(ConsuRemove);
                break;
            case 10:
                cons->ImprimirConsultaMedicos();
                break;
            case 11:
                cons->Imprimirdadosconsultorio();
                break;
			case 0:
				cout<<"\nsaindo...\n";
				break;
        }
    }while(resp!=0);
	
	return 0;
}