#ifndef __PESSOA_HPP
#define __PESSOA_HPP
#include <string>
using namespace std;
class Pessoa {
private:
    string nome;
    string sexo;
    string endereco;
    string cpf;
    string telefone;
    string identidade;

public:
    Pessoa(string nome,string sexo, string endereco, string cpf, string telefone, string identidade);
    Pessoa();
    void setNome(string nome);
    string getNome();

    void setSexo(string sexo);
    string getSexo();


    void setEndereco(string endereco);
    string getEndereco();

    void setCpf(string cpf);
    string getCpf();

    void setTelefone(string telefone);
    string getTelefone();

    void setIdentidade(string identidade);
    string getIdentidade();

    //void imprimirPessoa();
};
#endif