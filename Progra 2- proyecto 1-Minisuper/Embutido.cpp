#include "Embutido.h"

Embutido::Embutido()
{
	marca = "";
	tripa = false;
	empaque = new Empaque(); 
}

Embutido::Embutido(Producto* producto, string marca, bool tripa)
{
	this->marca = marca;
	this->tripa = tripa;
	this->ptrProducto = producto; 
	empaque = new Empaque(); 
}

void Embutido::setMarca(string marca)
{
	this->marca = marca;
}

string Embutido::getMarca()
{
	return marca;
}

bool Embutido::esDeTripa()
{
	return empaque->esDeTripa(tripa); 
}

string Embutido::toString()
{
	string result = Carne::toString(); 

	result += "Marca: " + (getMarca()) + "\n" + "Tripa: "; 

	if (esDeTripa()) { 
		result += "Si\n"; 
	}
	else { 
		result += "No\n"; 
	}
	stringstream ss;
	ss << fixed << setprecision(2) << calculaPorcGanancia();
	result += "Ganancia para la tienda: " + ss.str() + " Por cada producto vendido\n";
	return result; 
}

string Embutido::toStringFactu()
{
	string result = Carne::toStringFactu(); 

	result += "Marca: " + (getMarca()) + "\n" + "Tripa: ";

	if (esDeTripa()) {
		result += "Si\n";
	}
	else {
		result += "No\n";
	}
	return result;
}




