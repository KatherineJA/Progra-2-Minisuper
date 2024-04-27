#ifndef PERECEDERO_H
#define PERECEDERO_H
#include "Fecha.h"

class Perecedero
{
private: 
	Fecha* fechaCaducidad ; 
public: 
	Perecedero(Fecha* );
	Perecedero(); 
	~Perecedero(); 
	string toStringFechaCaducidad(); 

};

#endif PERECEDERO_H