#ifndef NO_HPP
#define NO_HPP
#include <iostream>
#include <string>

using namespace std;

class No
{
private:
	int id;
    int v;
    int qtd;
    string nome;
    No* prox;

public:
	No(int v, int id, int qtd, string nome);

	No();
    void setV(int v);
    int getV();
    void setId(int id);
    int getId();
    void setQtd(int qtd);
    int getQtd();
    void setNome(string nome);
    string getNome();
	No* obterProx();
    void imprimir();
	void setProx(No* p);
    
};

#endif

