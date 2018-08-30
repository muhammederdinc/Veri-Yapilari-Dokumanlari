
#include "Kart.hpp"
Kart::Kart(Sembol **sembol1)
{
     this->sembol=*sembol1;

}

Sembol* Kart::getSembol()
{
    return sembol;
}

