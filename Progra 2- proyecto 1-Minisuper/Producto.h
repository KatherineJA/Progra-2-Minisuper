#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "Fecha.h"
#include "Categoria.h"
//Component
class Producto{
protected: 
	string codigo; 
	string nombreComercial;
	string descripcion;
	int categoria;
	double precioCosto;
	int existencia;
	int limite;

public: 
	virtual string getCodigo() = 0; 
	virtual string getNombreComercial() = 0;
	virtual string getDescripcion() = 0;
	virtual int getCategoria() = 0;
	virtual double getPrecioCosto() = 0;
	virtual int getExistencia() = 0;
	virtual int getLimite() = 0;

	virtual void setCodigo(string) = 0; 
	virtual void setNombreComercial(string) = 0; 
	virtual void setDescripcion(string) = 0; 
	virtual void setCategoria(int) = 0; 
	virtual void setPrecio(double) = 0; 
	virtual void setExistencia(int) = 0; 
	virtual void setLimite(int) = 0; 

	virtual double calculaPorcGanancia() = 0; 

	///////
	virtual string toString() = 0;

};

#endif PRODUCTO_H