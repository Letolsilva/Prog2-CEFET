#ifndef __EXCESSAOLIMITE_HPP
#define __EXCESSAOLIMITE_HPP
#include <stdexcept>
using namespace std;
class ExcessaoLimite: public runtime_error
{
public:
  ExcessaoLimite();
};
#endif