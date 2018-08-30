
#include "Sembol.hpp"


    Sembol::Sembol(char *semb,int renk)
    {

           this->semb=semb;
           this->renk=renk;
    }
    char Sembol:: getkarakter()
    {

        return *semb;
    }
    int Sembol:: getrenk()
    {
       return renk;
    }
