#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <string>
#include <iostream>
using namespace std;
class Pessoa
{
    private:
        string nome;
        string valorpago;
        float renda;
    public:
        Pessoa();
        Pessoa(string nome, float renda);

        void setNome(string nome);
        string getNome();

        void setRenda(float renda);
        float getRenda();

        void setValorpago(string valorpago);
        string getValorpago();
};
#endif 