#include <locale>
#include "Lista.hpp"

int main(int argc, char *argv[])
{
    int resp, soma=0;
    int v, id,qtd;
	string nome;
	Lista l;
	
	if(l.vazia())
		cout << "A lista está vazia!!\n";
	else
		cout << "A lista NÃO está vazia!!\n";
	
	l.mostrar();
	
    do{
        cout<<"Digite: \n (1)-Inserir produto \n (2)-Consultar \n (3)-mostrar \n (4)-retirar \n (5)-modificar \n";
        cin>>resp;

        switch(resp){
            case 1:
				cout<<"Digite o nome do produto: ";
				cin>> nome;
				cout<<"Digite o ID: ";
				cin>>id;
				cout<<"Digite o valor: ";
				cin>>v;
				cout<<"Digite a quantidade: ";
				cin>>qtd;
				l.inserir(v, id,  qtd, nome);
				soma+=v;
				break;
			case 2:
				l.consultar(id);
				break;
			case 3:
				l.mostrar();
				
				break;
			case 4:
				l.retirar();
			break;
			case 5:
				l.modificar();
				break;
			case 0:
				cout<<"saindo...\n";
				break;
        }
    }while(resp!=0);
	
	return 0;
}