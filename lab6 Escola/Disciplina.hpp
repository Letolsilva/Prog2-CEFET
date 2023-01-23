#ifndef __DISCIPLINA_HPP
#define __DISCIPLINA_HPP
#include <string>
#include "Professor.hpp"
using namespace std;
class Disciplina {
private:
    string nome;
    int CH;
    Professor* prof;
    Disciplina* prox;

public:
    Disciplina(string nome, int CH, Professor* prof);
    Disciplina();

    void setNome(string nome);
    string getNome();

    void setCh(int CH);
    int getCh();

    void setProf(Professor* prof);
    Professor* getProf();

    Disciplina* getProx();
    void setProx(Disciplina* prox);

};
#endif