#include "ListaJuridica.hpp"

Lista_juri::Lista_juri()
{
    inicio=NULL;
    fim=NULL;
}

Lista_juri::Lista_juri(string nome,string cnpj,float renda)
{
    inicio = new PJ(nome,cnpj,renda);
	fim = inicio;
}
bool Lista_juri::vazia()
{
	return (inicio == NULL);
}

Lista_juri::~Lista_juri(){
    delete inicio;
}

PJ* Lista_juri::getInicio(){
    return this->inicio;
}
void Lista_juri::setInicio(PJ* inicio){
    this->inicio=inicio;
}
PJ* Lista_juri::getFinal(){
    return this->fim;
}
void Lista_juri::setFinal(PJ* final){
    this->fim=fim;
}

void Lista_juri:: inserir(string nome, string cnpj, float renda){
   PJ* juridica=new PJ(nome, cnpj, renda);
   if(vazia())
   {
       inicio=juridica;
       fim=juridica;
   }
   else{
       fim->setProx(juridica);
       fim=juridica;
   }

}

void Lista_juri:: imprimir(){
    PJ* juridica=inicio;
    if(vazia()){
        inicio=juridica;
        fim=juridica;
        cout<<"Lista vazia";
    }
    else{
        while(juridica){
        cout<<"O nome é: "<<juridica->getNome()<<endl;
        cout<<"O CNPJ é: "<<juridica->getCnpj()<<endl;
        cout<<"A renda o é: "<<juridica->getRenda()<<endl;
        cout<<"Imposto: "<<juridica->getValorpago()<<endl;
        juridica=juridica->getProx();
        }
    }
}
void Lista_juri::Calcularimposto(int renda, string cnpj){
    PJ* juridica=inicio;
    float total, valor_a_pagar;
    while(juridica){
        if(juridica->getCnpj()==cnpj){
        if(renda>0){
            total=0;
            cout<<"\nSera descontado 10% da renda bruta da empresa\n";
            total=renda*0.90;
            valor_a_pagar=renda*0.1;
            cout<<"\nRenda liquida apos os descontos: "<<total<<endl;
            cout<<"\nValor a ser pago: "<<valor_a_pagar<<endl;
            juridica->setValorpago("renda com os descontos "+to_string(total)+" valor a pagar "+to_string(valor_a_pagar)+"\n");
            //juridica->setRenda(total);
        }
        else{
            "Renda nao encontrada!";
        }
        
    }
    juridica=juridica->getProx();

}
}


void Lista_juri::removerjuri(string cnpj){
    if(vazia())
	cout << "Não há nenhuma pessoa \n";
	else if(inicio->getProx()==NULL && inicio->getCnpj()==cnpj)
		inicio=NULL;
	else if(inicio->getProx()->getProx()==NULL && inicio->getCnpj()==cnpj){
		inicio=inicio->getProx();
	}
	else if(inicio->getProx()->getProx()==NULL && inicio->getProx()->getCnpj()==cnpj){
		inicio->setProx(NULL);
        fim=inicio;
	}
	else{
		PJ* iant=inicio;
		PJ* i=inicio->getProx();
		PJ* iprox=inicio->getProx()->getProx();
		while(iprox){
			if(inicio->getCnpj()==cnpj){
				inicio=inicio->getProx();
			}
			else if(i->getCnpj()==cnpj){
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->getProx();
		}
		if(i->getCnpj()==cnpj)
        {
			iant->setProx(NULL);
			free(i);
			fim=iant;
	    }
    }
}

