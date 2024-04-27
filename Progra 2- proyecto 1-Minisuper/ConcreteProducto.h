#ifndef CONCRETEPRODUCTO_H
#define CONCRETEPRODUCTO_H
#include "Producto.h"
#include "Categoria.h"
//ConcreteComponent
class ConcreteProducto : public Producto
{
public:
	ConcreteProducto();
	ConcreteProducto(ConcreteProducto* otro);
	ConcreteProducto(string, string, string, int, double, int, int);
	string getCodigo() override;
	string getNombreComercial() override;
	string getDescripcion() override;
	int getCategoria() override;
	double getPrecioCosto() override;
	int getExistencia() override;
	int getLimite() override;

	void setCodigo(string) override;
	void setNombreComercial(string) override;
	void setDescripcion(string) override;
	void setCategoria(int) override;
	void setPrecio(double) override;
	void setExistencia(int) override;
	void setLimite(int) override;

	double calculaPorcGanancia() override;

	

	string toString() override;
};
#endif CONCRETEPRODUCTO_H