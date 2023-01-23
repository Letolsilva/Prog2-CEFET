#ifndef __PESSOA_HPP
#define __PESSOA_HPP
#include <string>
using namespace std;
class Pessoa {
private:
    string nome;
    string endereco;

public:
    Pessoa(string nome, string endereco);
    Pessoa();
    void setNome(string nome);
    string getNome();

    void setEndereco(string endereco);
    string getEndereco();

};
#endif