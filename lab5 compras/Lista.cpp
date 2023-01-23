
#include "Lista.hpp"
int Lista:: cont=0;
float Lista:: total=0;
int Lista:: qtd_total=0;

Lista::Lista()
{
	inicio = NULL;
	final = NULL;
}

Lista::Lista(int v, int id, int qtd, string nome)
{
	inicio = new No(v, id, qtd, nome);
	final = inicio;
}

bool Lista::vazia() 
{
	return (inicio == NULL);
}

void Lista::inserir(int v,int id, int qtd, string nome)
{
    No* no = new No(v, id, qtd, nome);

	total+=no->getV()*no->getQtd();
	qtd_total+=no->getQtd();
	cont++;

	if(vazia())
	{
		inicio = no;
		final=no;
	}
	else
	{
		no->setProx(inicio);
		inicio = no;
		
	}
}

void Lista::mostrar() 
{
	cout << "\nImprimindo...\n";

	No* i = inicio;
	
	if(vazia())
		cout << "\nA lista NÃO tem elementos!!\n";
	else
	{
		while(i) 
		{
			i->imprimir();
			i=i->obterProx();
		
		}
		cout << endl;
	}
	cout<<"O valor total é: " << total << endl;
	cout<<"A quantidade total de produtos foram: " << qtd_total << endl;
}

void Lista::consultar(int id)
{
	int comparar;
	if(vazia())
		cout << "A lista NÃO tem elementos!!\n";
	
	else
	{
		cout<<"Digite o ID do produto: ";
		cin>>comparar;
		No* i = inicio;
		while(i)
		{
			if(comparar== i->getId())
			{
				cout<<"\nElemento encontrado!!\n";
				i->imprimir();
				
			}	
			i = i->obterProx();
		}
		
	}
}

void Lista:: modificar()
{
	int comparar, v, qtd, Id;
	string nome;
	int controle=cont;

	if(vazia())
	{
		cout << "A lista NÃO tem elementos!!\n";
	}
	else
	{
		cout<<"Digite o ID do produto: ";
		cin>>comparar;
		No* i = inicio;

		while(i)
		{
			if(comparar== i->getId())
			{
				total-=i->getV()*i->getQtd();
				qtd_total-=i->getQtd();
				cout << "Digite o novo nome: " << endl;
				cin>>nome;
				cout << "Digite o novo ID: " << endl;
				cin>>Id;
				cout << "Digite o novo valor: " << endl;
				cin>>v;
				cout << "Digite a nova quantidade: "<< endl;
				cin>>qtd;
				
				i->setNome(nome);
				i->setId(Id);
				i->setV(v);
				i->setQtd(qtd);
				total+=i->getV()*i->getQtd();
				qtd_total+=i->getQtd();
				cout<<"Produto alterado com sucesso!!";
				i->imprimir();
				

			}
			i = i->obterProx();
			
		}
	}	
	
}

void Lista:: retirar(){
	int comparar, total, quantidade;
	float valor;

	cout<<"Digite o ID que deseja remover: ";
	cin>>comparar;
	if(vazia())
	cout << "A lista NÃO tem elementos!!\n";
	
	else if(inicio->obterProx()==NULL && inicio->getId()==comparar){
		qtd_total-=inicio->getQtd();
		total-=(inicio->getV())*(inicio->getQtd());
		inicio=NULL;
	}
		
	else if(inicio->obterProx()->obterProx()==NULL && inicio->getId()==comparar){
		qtd_total-=inicio->getQtd();
		total-=(inicio->getV())*(inicio->getQtd());
		inicio=inicio->obterProx();

	}
	else if(inicio->obterProx()->obterProx()==NULL && inicio->obterProx()->getId()==comparar){
		qtd_total-=inicio->obterProx()->getQtd();
		total-=inicio->obterProx()->getV()*inicio->obterProx()->getQtd();
		inicio->setProx(NULL);

	}
	else{
		No* iant=inicio;
		No* i=inicio->obterProx();
		No* iprox=inicio->obterProx()->obterProx();
		while(iprox){
			if(inicio->getId()==comparar){
				qtd_total-=inicio->getQtd();
				total-=inicio->getV()*inicio->getQtd();
				inicio=inicio->obterProx();
			}
			else if(i->getId()==comparar){
				qtd_total-=i->getQtd();
				total=i->getV()*i->getQtd();
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->obterProx();
		}
		if(i->getId()==comparar){
			qtd_total-=final->getQtd();
			total-=final->getV()*final->getQtd();
			iant->setProx(NULL);
			free(i);
			
		}
	}
	

}
