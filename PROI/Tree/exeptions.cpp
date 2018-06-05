#include "exeptions.h"
#include <string>
using namespace std;

Exept::Exept(std::string xx): x(xx) {}

string Exept::what()
{
    return x;
}
