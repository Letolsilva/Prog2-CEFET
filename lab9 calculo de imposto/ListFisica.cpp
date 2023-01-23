#include "ListFisica.hpp"
Lista_fis::Lista_fis()
{
    inicio=NULL;
    fim=NULL;
}

Lista_fis::Lista_fis(string nome,string cpf,float renda)
{
    inicio = new PF(nome, cpf,renda);
	fim = inicio;
}
bool Lista_fis::vazia()
{
	return (inicio == NULL);
}

Lista_fis::~Lista_fis(){
    delete inicio;
}

PF* Lista_fis::getInicio(){
    return this->inicio;
}
void Lista_fis::setInicio(PF* inicio){
    this->inicio=inicio;
}
PF* Lista_fis::getFinal(){
    return this->fim;
}
void Lista_fis::setFinal(PF* final){
    this->fim=fim;
}

void Lista_fis:: inserir(string nome, string cpf, float renda){
   PF* fisica=new PF(nome, cpf, renda);
   if(vazia())
   {
       inicio=fisica;
       fim=fisica;
   }
   else{
       fim->setProx(fisica);
       fim=fisica;
   }

}

void Lista_fis:: imprimir(){
    PF* fisica=inicio;
    if(vazia()){
        inicio=fisica;
        fim=fisica;
        cout<<"Lista vazia";
    }
    else{
        while(fisica){
        cout<<"O nome é: "<<fisica->getNome()<<endl;
        cout<<"O CPF é: "<<fisica->getCpf()<<endl;
        cout<<"A renda o é: "<<fisica->getRenda()<<endl;
        cout<<"Imposto:  "<<fisica->getValorpago()<<endl;
        cout<<"\n\n";
        fisica=fisica->getProx();
        }
    }
}
void Lista_fis::Calcularimposto(int renda, string cpf){
    PF* fisica=inicio;
    float total, valor_a_pagar;
    while(fisica){
        if(fisica->getCpf()==cpf){
            if(fisica->getRenda()<=1903.98){
                cout<<"\nA Renda não sera modificada\nRenda atual: \n"<<renda;
                fisica->setValorpago("Não paga imposto""\n");
            }
            else if(renda>1903.98 && renda<=2826.65){
                total=0;
                valor_a_pagar=0;
                cout<<"\nAliquo de 7,50% o valor reduzido é de 142,80\n";
                total=(renda*0.925)-142.80;
                valor_a_pagar=((renda*0,075)-142,80);
                cout<<"\nRenda apos os descontos: "<<total<<endl;
                cout<<"\nValor a pagar: "<<valor_a_pagar<<endl;
                fisica->setValorpago("renda com os descontos "+to_string(total)+" valor a pagar "+to_string(valor_a_pagar)+"\n");
                //fisica->setRenda(total);
                
            }
            
            else if(renda>2826.65 && renda<= 3751.06){
                total=0;
                valor_a_pagar=0;
                cout<<"\nAliquo de 15% o valor reduzido é de 354.80\n";
                total=((renda*0.85)-354.80);
                valor_a_pagar=((renda*0.15)-354.80);
                cout<<"\nRenda apos os descontos: "<<total<<endl;
                cout<<"\nValor a pagar: "<<valor_a_pagar<<endl;
                fisica->setValorpago("renda com os descontos "+to_string(total)+" valor a pagar "+to_string(valor_a_pagar)+"\n");
            // fisica->setRenda(total);
              
            }
            else if(renda>3751.06 && renda<=4664.68){
                total=0;
                valor_a_pagar=0;
                cout<<"\nAliquo de 22,5% o valor reduzido é de 636,13\n";
                total=((renda*0.775)-636.13);
                valor_a_pagar=((renda*0.225)-636.13);
                cout<<"\nRenda apos os descontos: "<<total<<endl;
                cout<<"\nValor a pagar: "<<valor_a_pagar<<endl;
                fisica->setValorpago("renda com os descontos "+to_string(total)+" valor a pagar "+to_string(valor_a_pagar)+"\n");
                //fisica->setRenda(total);
                
            }
            else if(renda>4664.68){
                total=0;
                valor_a_pagar=0;
                cout<<"\nAliquo de 27,5% o valor reduzido é de 869,36\n";
                total=((renda*0.725)-869.36);
                valor_a_pagar=((renda*0.275)-869.36);
                cout<<"\nRenda apos os descontos: "<<total<<endl;
                cout<<"\nValor a pagar: "<<valor_a_pagar<<endl;
                fisica->setValorpago("renda com os descontos "+to_string(total)+" valor a pagar "+to_string(valor_a_pagar)+"\n");
                //fisica->setRenda(total);
                
            }
            else{
                "Renda nao encontrada!";
            }
        }
        fisica=fisica->getProx();
    }
}

void Lista_fis::removerfisica(string cpf){

    if(vazia())
	cout << "Não há nenhuma pessoa fisica\n";
	else if(inicio->getProx()==NULL && inicio->getCpf()==cpf)
		inicio=NULL;
	else if(inicio->getProx()->getProx()==NULL && inicio->getCpf()==cpf){
		inicio=inicio->getProx();
	}
	else if(inicio->getProx()->getProx()==NULL && inicio->getProx()->getCpf()==cpf){
		inicio->setProx(NULL);
        fim=inicio;
	}
	else{
		PF* iant=inicio;
		PF* i=inicio->getProx();
		PF* iprox=inicio->getProx()->getProx();
		while(iprox){
			if(inicio->getCpf()==cpf){
				inicio=inicio->getProx();
			}
			else if(i->getCpf()==cpf){
				iant->setProx(iprox);
				free(i);
			}
			iant=i;
			i=iprox;
			iprox=iprox->getProx();
		}
		if(i->getCpf()==cpf)
        {
			iant->setProx(NULL);
			free(i);
			fim=iant;
	    }
    }
}