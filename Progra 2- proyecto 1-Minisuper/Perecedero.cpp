#include "Perecedero.h"

Perecedero::Perecedero(Fecha* FC)
{
	fechaCaducidad = FC;

}

Perecedero::Perecedero()
{
	fechaCaducidad = new Fecha(); 
}

Perecedero::~Perecedero()
{
	
}

string Perecedero::toStringFechaCaducidad()
{
	return "Fecha de Caducidad:  " + fechaCaducidad->toStringFecha(); 
}
