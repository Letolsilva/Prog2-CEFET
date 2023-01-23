#include<iostream> 
#include "Curso.hpp"
using namespace std;
Curso::Curso(string nome_curso, List_Prof* professores, ListAluno* alunos, List_Disciplina* disciplinas){
    this-> nome_curso=nome_curso;
    this->professores=professores;
    this->alunos=alunos;
    this->disciplinas=disciplinas;
}
Curso::Curso(){
    this->professores=new List_Prof();
    this->alunos= new ListAluno();
    this-> disciplinas= new List_Disciplina();
}

void Curso::setNome_curso(string nome_curso){
    this->nome_curso=nome_curso;
}
string Curso::getNome_curso(){
    return this->nome_curso;
}
void Curso:: cadastrar_professor(){
    Professor* prof=professores->getInicio();
    string nome_prof, titulacao, endereco_prof, curso;
    cout<<"Digite a titulaçao: ";
    getline(cin,titulacao);
    
    cout<<"Digite o nome: ";
    getline(cin,nome_prof);
    
    cout<<"Digite o endereço: ";
    getline(cin,endereco_prof);
    
    cout<<"Digite o curso: ";
    getline(cin,nome_curso);
    
    professores->inserir_professor(nome_prof, endereco_prof, titulacao, nome_curso);
    professores->imprimir_professor();
}
void Curso::cadastrar_aluno(){
    string nome_aluno, matricula, endereco;
    
        cout<<"Digite o numero da matricula: ";
        getline(cin, matricula);
        
        cout<<"Digite o nome: ";
        getline(cin,nome_aluno);
       
        cout<<"Digite o endereço: ";
        getline(cin,endereco);
        
    alunos->inserir_aluno(matricula,nome_aluno, endereco);
}
void Curso::cadastrar_disciplina(){
    Professor* prof = NULL;
    Professor* profer=professores->getInicio();
    string nome_disci, nome_prof;
    int ch;
    cout<<"Digite o nome: ";
    cin>> nome_disci;
    cout<<"Digite a carga horaria: ";
    cin>>ch;
    cout<<"Digite o professor: ";
    cin>>nome_prof;
    while(profer){
        if(profer->getNome()==nome_prof){
            prof=profer;
        }
        profer=profer->getProx();
    }


    if(prof!=NULL){
     disciplinas->inserir_disciplina(nome_disci,ch,prof);
    }
    else{
        cout<<"Professor não cadastrado \n";
    }
   
}
void Curso::imprimir_prof(){
    cout << "\nImprimindo...\n";
	professores->imprimir_professor();
   

}
void Curso::imprimir_aluno(){
    cout << "\nImprimindo...\n";		
		alunos->imprimir_aluno();
		
	
}
void Curso::imprimir_disciplina(){
    cout << "\nImprimindo...\n";
    disciplinas->imprimir_disciplina();
}