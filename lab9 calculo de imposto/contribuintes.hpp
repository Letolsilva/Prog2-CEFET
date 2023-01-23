#ifndef _CONTRIBUINTES_HPP
#define _CONTRIBUINTES_HPP
#include <string>
#include "ListFisica.hpp"
#include "ListaJuridica.hpp"
class Contribuintes {
private:
    Lista_fis* fisicos;
    Lista_juri* juridicos;
   
public:
    Contribuintes(Lista_fis* fisicos, Lista_juri* juridicos);
    Contribuintes();

    void inserirFisico();
    void imprimirFisico();
    void calcularimpostoFisico();
    void RemoverFisico(string cpf);
    void RemoverJuri(string cnpj);
    void inserirJuridico();
    void imprimirJuridico();
    void calcularimpostoJuridico();

};
#endif