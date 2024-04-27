#ifndef EMBUTIDO_H
#define EMBUTIDO_H
#include "Empaque.h"
#include "Carne.h"

class Embutido : public Carne
{
private:
	string marca;
	bool tripa;
	Empaque* empaque; 
public:
	Embutido();
	Embutido(Producto* producto, string marca, bool tripa);

	void setMarca(string marca);
	string getMarca();
	bool esDeTripa(); 
	string toStringEmbutido() ; 
};

#endif EMBUTIDO_H