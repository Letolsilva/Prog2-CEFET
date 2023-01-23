#ifndef LISTA_HPP
#define LISTA_HPP
#include "no.hpp"

class Lista
{
private:
	No* inicio;
	No* final;
	static int cont;
	static float total;
	static int qtd_total;

public:
	Lista();
	Lista(int v, int id, int qtd, string nome);

    void inserir(int id, int v, int qtd, string nome);
    void mostrar();
    void retirar();
    void modificar();
	bool vazia();
	void consultar(int id);


	
};
#endif