#include <locale>
#include "Curso.hpp"
int main()
{
    int ch, resp;

	Curso* curso=new Curso();
    do{
        cout<<"Digite:\n (1) inserir aluno \n (2) inserir prof \n (3) inserir disciplina \n (4) imprimir professor \n (5) imprimir aluno \n (6) imprimir disciplina \n (0) sair \n";
        cin>>resp;

        switch(resp){
            case 1:
            cin.ignore();
				curso->cadastrar_aluno();    

				break;
			case 2:
            cin.ignore();
				curso->cadastrar_professor();             
				break;
            case 3:
            cin.ignore();
                curso->cadastrar_disciplina();
                break;
            case 4:
                curso->imprimir_prof();
                break;
            case 5:
                curso->imprimir_aluno();
                break;
            case 6:
                curso->imprimir_disciplina();
                break;
			case 0:
				cout<<"saindo...\n";
				break;
        }
    }while(resp!=0);
	
	return 0;
}