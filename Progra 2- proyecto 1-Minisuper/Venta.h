#ifndef VENTA_H
#define VENTA_H
#include "Carrito.h"
#include "Fecha.h"
class Venta
{
private:
	Carrito* carrito;
	Fecha* fechaCompra;
	
public:
	Venta();
	Venta(Carrito*,Fecha*);


	void setFechaCompra(Fecha*);
	Fecha* getFechaCompra();

	void setCarrito(Carrito*);
	Carrito* getCarrito();

	

	string toString() const;



};

#endif VENTA_H