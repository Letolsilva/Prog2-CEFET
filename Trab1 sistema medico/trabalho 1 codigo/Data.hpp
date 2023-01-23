#ifndef __DATA_HPP
#define __DAtA_HPP
#include <string>
using namespace std;
class Data {
private:
    int dia;
    int mes; 
    int ano;

public:
    Data(int dia, int mes, int ano);
    Data();
    void setDia(int dia);
    int getDia();

    void setMes(int mes);
    int getMes();

    void setAno(int ano);
    int getAno();
};
#endif



