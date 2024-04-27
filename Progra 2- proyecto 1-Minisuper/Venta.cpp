#include "Venta.h"



Venta::Venta()
{
	carrito = nullptr;
	fechaCompra = nullptr;
}

Venta::Venta(Carrito* carritoCliente, Fecha* fechaComprado)
{
	this->carrito = carritoCliente;
	this->fechaCompra = fechaComprado;
}

void Venta::setFechaCompra(Fecha* fecha)
{
	this->fechaCompra = fecha;
}

Fecha* Venta::getFechaCompra()
{
	return fechaCompra;
}

void Venta::setCarrito(Carrito* carritoNuevo)
{
	this->carrito = carritoNuevo;
}

Carrito* Venta::getCarrito()
{
	return carrito;
}





string Venta::toString() const
{
	stringstream s;
	s << "\033[1;36m========== FACTURA MINISUPER [TWINS A COLOR] ==========\033[0m" << endl;
	s << "Fecha de Compra: " << this->fechaCompra->toStringFecha()  << endl;
	s << this->carrito->toStringCarrito();
	s << "========================================================" << endl;

	return s.str();
}
