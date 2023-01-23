#ifndef __DISCIPLINA_HPP
#define __DISCIPLINA_HPP
#include <string>
#include "Professor.hpp"
using namespace std;
class Disciplina {
private:
    string nome;
    int CH;
    string nomeprof;

public:
    Disciplina(string nome, int CH, string nomeprof);
    Disciplina();

    void setNome(string nome);
    string getNome();

    void setCh(int CH);
    int getCh();

    void setNomeprof(string nomeprof);
    string getNomeprof();

};
#endif