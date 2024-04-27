#ifndef CLIENTE_H 
#define CLIENTE_H
#include <iostream>
#include <sstream>
using namespace std;

class Cliente
{
private:
	string id;
	string nombre;
public:
	Cliente();
	Cliente(string nombre, string id);

	void setId(string);
	string getId();

	void setNombre(string);
	string getNombre();
	string toString();
};

#endif CLIENTE_H