#include<iostream> 
#include "Curso.hpp"
#include <vector>
using namespace std;
Curso::Curso(string nome_curso){

}
Curso::Curso(){
 
}

void Curso::setNome_curso(string nome_curso){
    this->nome_curso=nome_curso;
}
string Curso::getNome_curso(){
    return this->nome_curso;
}
void Curso:: cadastrar_professor(){

    string nome_prof, titulacao, endereco_prof, curso;
    int con=0;

    cout<<"Digite a titulaçao: ";
    getline(cin,titulacao);
    
    cout<<"Digite o nome: ";
    getline(cin,nome_prof);
    
    cout<<"Digite o endereço: ";
    getline(cin,endereco_prof);
    
    cout<<"Digite o curso: ";
    getline(cin,nome_curso);
   

    for(int i=0; i<prof.size(); i++){
            if(prof[i].getTitulacao()==titulacao && prof[i].getNome()==nome_prof && prof[i].getEndereco()==endereco_prof && prof[i].getCurso()==nome_curso){
                cout<<"Professor ja esta cadastrado!"<<endl;
                con=1;          
            }
        }
        if(con!=1){
            Professor* aux=new Professor(titulacao,nome_curso,nome_prof, endereco_prof);
            prof.push_back(*aux);
            cout<<"Professor cadastrado com sucesso!"<<endl;
        }

    
}
void Curso::cadastrar_aluno(){
    string nome_aluno, matricula, endereco;
    int con=0;
        cout<<"Digite o numero da matricula: ";
        getline(cin, matricula);

        for(int i=0; i<alunos.size(); i++){
            if(alunos[i].getMatricula()==matricula){
                cout<<"Aluno ja cadastrado!"<<endl;
                con=1;
                return;
            
            }
        }
        if(con!=1){
             cout<<"Numero de matricula verificado, continue cadastrando..."<<endl;
        }
       
        cout<<"Digite o nome: ";
        getline(cin,nome_aluno);
       
        cout<<"Digite o endereço: ";
        getline(cin,endereco);

        if(con!=1){
        Aluno* aux=new Aluno(matricula,nome_aluno,endereco);
        alunos.push_back(*aux);
        cout<<"Aluno cadastrado com sucesso!";
        }
}
void Curso::cadastrar_disciplina(){
    bool con=0;
    string nome_disci, nome_prof;
    int ch;
    cout<<"Digite o nome: ";
    cin>> nome_disci;
    cout<<"Digite a carga horaria: ";
    cin>>ch;
    cout<<"Digite o professor: ";
    cin>>nome_prof;

    for(int i=0; i<disci.size(); i++){
        if(disci[i].getNome()==nome_disci){
            cout<<"Disiciplina ja cadastrada!"<<endl;
            con=1;
        
        }
    }
    if(con!=1){
        for(int i=0; i<prof.size(); i++){
            if(prof[i].getNome()==nome_prof){
                Disciplina* aux=new Disciplina(nome_disci,ch, nome_prof);
                disci.push_back(*aux);
                con=1;
                cout<<"Disciplina cadastrada com sucesso!"<<endl;
            }  
        }
        if(con==0){
            cout<<"professor nao cadastrado"<<endl;
        }
   
}
}
void Curso::imprimir_prof(){
    if(prof.empty()){
        cout<<"Lista vazia!";
    }
    else{
        cout << "\nImprimindo...\n"<<endl;
        for(int i=0; i<prof.size(); i++){
        cout<<"O nome do professor é: "<<prof[i].getNome()<<endl;
        cout<<"A Titulaçao é: "<<prof[i].getTitulacao()<<endl;
        cout<<"O curso é: "<<prof[i].getCurso()<<endl;
        cout<<"O nome é: "<<prof[i].getNome()<<endl;
        cout<<"O endeço é: "<<prof[i].getEndereco()<<endl;
    }  
    }
  
}
void Curso::imprimir_aluno(){
     if(alunos.empty()){
        cout<<"Lista vazia!";
    }
    else{
        cout << "\nImprimindo...\n"<<endl;
        for(int i=0;i<alunos.size();i++){
        cout<<"A matricula é: "<<alunos[i].getMatricula()<<endl;
        cout<<"O nome é: "<<alunos[i].getNome()<<endl;
        cout<<"O endeço é: "<<alunos[i].getEndereco()<<endl;
    }		
	
    }

}
void Curso::imprimir_disciplina(){
        if(disci.empty()){
        cout<<"Lista vazia!"<<endl;
    }
    else{
        for(int i=0; i<disci.size();i++)
        {
        cout<<"O nome é: "<<disci[i].getNome()<<endl;
        cout<<"O CH é: "<<disci[i].getCh()<<endl;
        cout<<"O professor: "<<disci[i].getNomeprof()<<endl;
        }
    }
   
}
