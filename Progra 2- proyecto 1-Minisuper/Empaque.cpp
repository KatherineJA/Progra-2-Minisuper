#include "Empaque.h"

Empaque::Empaque(bool tripa )
{
    this->tripa = tripa; 
}

Empaque::Empaque()
{
    tripa = true; 
}

Empaque::~Empaque()
{
}

bool Empaque::esDeTripa(bool tripa)
{

    if (tripa == true) {
        return true;
    }
    else  {
        return false;
    }
}
