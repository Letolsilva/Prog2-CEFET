#include<iostream> 
#include "Consultorio.hpp"
using namespace std;
Consultorio::Consultorio(ListaMedico* medicos, ListaPaciente* pacientes, ListaConsulta* consultas, string nomeConsultorio, string enderecoConsultorio, int telefoneConsultorio){
    this-> medicos=medicos;
    this->pacientes=pacientes;
    this->consultas=consultas;
    setNomeConsultorio("ProSaude");
    setEnderecoConsultorio("Rua jardim das orquideas 292");
    setTelefoneConsultorio(33214576);
}
Consultorio::Consultorio(){
    this->medicos=new ListaMedico();
    this->pacientes= new ListaPaciente();
    this->consultas= new ListaConsulta();
}

void Consultorio::setNomeConsultorio(string nomeConsultorio){
    this->nomeConsultorio="ProSaude";
}
string Consultorio::getNomeConsultorio(){
    return "ProSaude";
}

void Consultorio::setEnderecoConsultorio(string enderecoConsultorio){
    this->enderecoConsultorio="Rua jardim das orquideas 292";
}
string Consultorio::getEnderecoConsultorio(){
    return "Rua jardim das orquideas 292";
}
void Consultorio::setTelefoneConsultorio(int telefoneConsultorio){
    this->telefoneConsultorio=33214576;
}
int Consultorio::getTelefoneConsultorio(){
    return 33214576;
}
void Consultorio::CadastrarPaciente(){
    string SexoPaci;
    string NomePaci, EnderecoPaci, cpfPaci, FonePaci, IdPaci, Relato, UltimaConsu, Medicacao, CPFverifica;
    Paciente* paciente=NULL;
    Paciente* paci=pacientes->getInicio();
    cout<<"\t* Vamos verificar se este paciente ja esta cadastrado *\t";
    cout<<"\nDigite o cpf da pessoa: ";
    getline(cin, CPFverifica);
    while(paci)
    {
        if(paci->getCpf()==CPFverifica){
            paciente=paci;
            cout<<"\n Paciente ja esta cadastrado\n";
            return;
        }
        paci=paci->getProx();
    }
    if(paciente==NULL)
    {
        cout<<"\n\n";
        cout<<"\tSEJA BEM VINDO AO CADASTRO AO PACIENTE!\t";
        cout<<"\n\n";
        cout<<"\tIrei precisar de algumas informaçoes do paciente\t";
        cout<<"\n-> Informe o nome completo: ";
        getline(cin, NomePaci);
        cout<<"-> O sexo: ";
        getline(cin,SexoPaci);
        cout<<"-> O endereco: ";
        getline(cin,EnderecoPaci);
        cout<<"-> O CPF: ";
        getline(cin,cpfPaci);
        cout<<"-> O telefone: ";
        getline(cin,FonePaci);
        cout<<"-> O numero de identidade: ";
        getline(cin,IdPaci);
        cout<<"-> Informe os sintomas: ";
        getline(cin,Relato);
        cout<<"-> A data de hoje: ";
        getline(cin,UltimaConsu);
        cout<<"-> A medicação: ";
        getline(cin,Medicacao);
    
        pacientes->InserirPaciente(NomePaci,SexoPaci,EnderecoPaci, cpfPaci, FonePaci, IdPaci, Relato, UltimaConsu, Medicacao);
        cout<<"\nPaciente cadastrado com sucesso!\n3";

    }
}
void Consultorio::RemoverPaciente(string cpf){

    pacientes->RemoverPaciente(cpf);
    cout<<"\nPaciente e suas consultas foram removidos\n";

}
void Consultorio:: CadastrarMedico(){
    string SexoMed;
    string NomeMed, EnderecoMed, cpfMed, FoneMed, IdMed, especialidade;
    int CRM, CRMverifica;
    Medico* medico=NULL;
    Medico* med=medicos->getInicio();
    cout<<" \t* Vamos verificar se o doutor(a) ja esta cadastrado *\t";
    cout<<"\nDigite o CRM: ";
    cin>> CRMverifica;
    while(med)
    {
        if(med->getCrm()==CRMverifica){
            medico=med;
            cout<<"\nMedico ja cadastrado\n";
            return;
        }
        med=med->getProx();
    }
    if(medico==NULL)
    {
        cout<<"\n";
        cout<<"\tSEJA BEM VINDO AO CADASTRO DO MEDICO!\t";
        cout<<"\n";
        cout<<"\t\nIrei precisar de algumas informaçoes do medico\t";
        cout<<"\n-> Informe o nome completo: ";
        cin.ignore();
        getline(cin, NomeMed);
        cout<<"-> O sexo: ";
        getline(cin,SexoMed);
        cout<<"-> O endereco: ";
        getline(cin,EnderecoMed);
        cout<<"-> O CPF: ";
        getline(cin,cpfMed);
        cout<<"-> O telefone: ";
        getline(cin,FoneMed);
        cout<<"-> O numero de identidade: ";
        getline(cin,IdMed);
        cout<<"-> O CRM: ";
        cin>>CRM;
        cout<<"-> A especialidade: ";
        cin.ignore();
        getline(cin,especialidade);
        medicos->InserirMedico( NomeMed, SexoMed, EnderecoMed, cpfMed, FoneMed, IdMed, CRM, especialidade);
        cout<<"\nMedico cadastrado com sucesso!\n";
    }
}
void Consultorio::RemoverMedico(int crm){
    
    medicos->RemoverMedico(crm);
    cout<<"\nMedico e suas consultas foram removidos\n";

}
void Consultorio::ImprimirPacientes(){
    cout << "\tImprimindo paciente...\t\n";
	pacientes->ImprimirPaciente();
}
void Consultorio::ImprimirMedicos(){
    cout << "\tImprimindo medicos...\t\n";
			medicos->ImprimirMedico();

}

void Consultorio:: CadastrarConsulta(){
    string hora, cpfPaciente; 
    bool verificaMed=false, verificaPaci=false;
    int crmMedico;
    int dia=0, mes=0, ano=0;
    Data* aux=new Data(dia, mes, ano);
    Consulta* con=consultas->getInicio();
    Paciente* paci=pacientes->getInicio();
    Medico* med=medicos->getInicio();

    cout<<" \t* Vamos verificar se existe um doutor(a) atendendo no momento *\t";
    cout<<"\nDigite o CRM: ";
    cin>> crmMedico;
    cout<<"\t * Vamos verificar se você ja é um paciente cadastrado * \t";
    cout<<"\n Digite o CPF: ";
    cin>> cpfPaciente;
    while(med)
    {
        if(med->getCrm()==crmMedico){
            verificaMed=true;
            cout<<"\nMedico esta atendendo! proxima etapa...";
            break;
        }
        med=med->getProx();
    }
    while(paci){
        if(paci->getCpf()==cpfPaciente){
            verificaPaci=true;
            cout<<"\nPaciente esta cadastrado! Vamos para a proxima etapa...\n";
            break;
        }
        paci=paci->getProx();
    }
    if(!verificaMed){
        cout<<"\n Desculpe não temos este medico atendendo no momento\n";
    }
    if(!verificaPaci){
        cout<<"\n Vocẽ ainda não é um paciente cadastrado\n";
    }
    if(verificaMed && verificaPaci)
    {
        cout<<"\tSEJA BEM VINDO AO CADASTRO CONSULTA!\t";
        cout<<"\n";
        cout<<"\t\nIrei precisar de algumas informaçoes\t";
        cout<<"\n-> Informe o CPF do paciente: ";
        cin.ignore();
        getline(cin, cpfPaciente);
        cout<<"-> O CRM do medico: ";
        cin>>crmMedico;

        cout<<"-> O dia da consulta: ";
        cin>>dia;
        if(dia>31 || dia<1){
            cout<<"Dia invalido\n";
            return;
        }
        cout<<"-> O mes: ";
        cin>>mes;
        if(mes>12 || mes<1){
            cout<<("mes invalido!\n");
            return;
        }
        cout<<"-> O ano: ";
        cin>>ano;
        if(ano<2022){
             cout<<"Ano invalido!\n";
            return;
         }
        Data* aux=new Data(dia, mes, ano);
        cout<<"-> O horario: ";
        cin.ignore();
        getline(cin,hora);
        if(hora>"24" || hora<"0"){
            cout<<"Hora invalida!\n";
            return;
        }
        consultas->InserirConsulta(aux, hora,cpfPaciente,crmMedico);
        cout<<"\nConsulta cadastrada com sucesso!\n";
    }
}
void Consultorio::ImprimirConsultas(){
    cout << "\tImprimindo Consultas...\t\n";
			consultas->ImprimirConsulta();
}
void Consultorio::RemoverConsulta(string cpfPaciente){
    
    consultas->RemoverConsulta(cpfPaciente);
    cout<<"\nConsulta removida com sucesso!\n";

}
void Consultorio::RemoverConsultaMedica(int crmMedico){
    consultas->RemoverConsultaMED(crmMedico);
}

void Consultorio::ImprimirConsultaMedicos(){
    int CRM;
    Consulta* consu=consultas->getInicio();
    cout<<" \t* LISTA DE CONSULTAS DE UM DETERMINADO MEDICO *\t";
    cout<<"\nDigite o CRM: ";
    cin>> CRM;

    while(consu)
    {
        if(consu->getCrmMedico()==CRM){
        cout<<"=====================================================";
        cout<<endl;
        cout << "O dia é: " << consu->getData()->getDia() << endl;
        cout << "O mes é: " << consu->getData()->getMes() << endl;
        cout << "O ano é: "<< consu->getData()->getAno() << endl;
        cout << "O horario é: " << consu->getHora() << endl;
        cout << "O CPF do paciente é: " << consu->getCpfPaciente() << endl;
        cout << "O CRM do medico é: "<< consu->getCrmMedico() << endl;
        cout<<endl;
        cout<<"=====================================================\n";
        }
        consu=consu->getProx();
    }
}
void Consultorio::Imprimirdadosconsultorio(){

    cout << "O nome da clinica é: " <<this->getNomeConsultorio() << endl;
    cout << "O endereço: " << this->getEnderecoConsultorio() << endl;
    cout << "O telefone: "<< this->getTelefoneConsultorio() << endl;
}