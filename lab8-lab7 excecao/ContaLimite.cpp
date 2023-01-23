#include<iostream> 
#include "ContaLimite.hpp"
#include "ExcessaoLimite.hpp"
using namespace std;

ContaLimite::ContaLimite(string nome,int Num_conta,double Valor_lim):ContaComum(nome, Num_conta){
    setValor_Lim(Valor_lim);
    setValorFix(Valor_lim);
    this->prox=NULL;
}
ContaLimite::ContaLimite(){
     this->prox=NULL;
}

void ContaLimite::setValor_Lim(double Valor_lim){
    this->Valor_lim=Valor_lim;
}
double ContaLimite::getValor_Lim(){
    return Valor_lim;
}
void ContaLimite::setValorFix(double Valor_lim){
    this->ValorFixo=Valor_lim;
}
double ContaLimite::getValorFix(){
    return ValorFixo;
}
void ContaLimite:: setProx(ContaLimite* prox){
    this->prox=prox;
}
ContaLimite* ContaLimite::getProx(){
    return this->prox;
}
void ContaLimite::Deposito(double valor, string data, string descricao){
    
    if(this->Valor_lim<this->ValorFixo){
        if(valor>0){
            this->Valor_lim+=valor;
            cout<<"deposito realizado no limite\n";
        }
        cout<<"Valor negativo!!";
    }
    else{
        if(valor>0){
            this->Saldo+=valor;
        }
         else{
             cout<<"Valor inválido! Tente novamente"<<endl; 
        }
    }
        this->Transacao+=data+" - Adicionou: "+to_string(valor)+" - "+descricao+"\n";
        cout<<this->Transacao;
      

}

void ContaLimite::Saque(double valor, string data, string descricao)
{
    int cont=0;
            if(this->Saldo==0)
            {
                if(this->Valor_lim>=valor){
                    this->Valor_lim-=valor;
                    cout<<"\nSaque realizado no limite\n";
                    this->Transacao+=data+" - Retirou: "+to_string(valor)+" - "+descricao+"\n";
                    cout<<this->Transacao;
                    return;
                }
                throw ExcessaoLimite();
            }
        
            if(this->Saldo>0){
                    if(this->Saldo+this->Valor_lim>valor){
                        this->Saldo-=valor;
                        
                        if(this->Saldo<0){
                        cout<<"Saldo ultrapassado, vamos retirar do limite\n";
                             while(getSaldo()<0){
                                setSaldo(getSaldo()+1);
                                cont++;
                            }
                        this->Valor_lim-=cont;
                        this->Transacao+=data+" - Retirou: "+to_string(valor)+" - "+descricao+"\n";
                        cout<<this->Transacao;
                        return;
                        }
                    else{
                        cout<<"\nSaque realizado com sucesso!\n";
                        this->Transacao+=data+" - Retirou: "+to_string(valor)+" - "+descricao+"\n";
                        cout<<this->Transacao;
                        return;
                    }
                }

            }
            if(this->Valor_lim==0 && this->Saldo==0){
            cout<<"\nnão tem valor na conta\n";
        }
       
  
}
void ContaLimite::extrato(){
    cout<<this->Transacao;
}