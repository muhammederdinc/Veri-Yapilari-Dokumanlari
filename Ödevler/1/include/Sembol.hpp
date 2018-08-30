#ifndef SEMBOL_HPP
#define SEMBOL_HPP
#include "iostream"

using  namespace std;
class Sembol{
     private:
        char *semb;
        int renk;
public:
     Sembol();
    Sembol(char *semb,int renk);

    char getkarakter();
    int getrenk();

};
#endif
