#ifndef VENTA_H
#define VENTA_H

#include "Cliente.h"
#include "Producto.h"
#include "Fecha.h"
#include "Carrito.h"
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