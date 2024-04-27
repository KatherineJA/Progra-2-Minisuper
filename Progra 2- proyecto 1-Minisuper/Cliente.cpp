#include "Cliente.h"

Cliente::Cliente()
{
	nombre = "";
	id = " ";

}

Cliente::Cliente(string nombre, string id)
{
	this->id = id;
	this->nombre = nombre;
}

void Cliente::setId(string id)
{
	this->id = id;
}

string Cliente::getId()
{
	return id;
}

void Cliente::setNombre(string id)
{
	this->id = id;
}

string Cliente::getNombre()
{
	return nombre;
}

string Cliente::toString()
{
	stringstream s;
	s << "ID cliente: " << getId() << endl;
	s << "Nombre: " << getNombre() << endl;
	return s.str();
}