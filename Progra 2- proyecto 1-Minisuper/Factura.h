#ifndef FACTURA_H
#define FACTURA_H
#include "Lista.h"
#include "Venta.h"
class Factura
{
private:
	Lista<Venta>* ventas;

public:
	Factura();

	Factura(Lista<Venta>*);

	~Factura();

	void agregarVenta(Venta* venta);

	const Lista<Venta>* getVentas();


	void NumeroFactura();

	void MostrarVentaClienteCedula(string cedula);
	void reporteMejoresClientes(); 
	string toString();
	
};

#endif FACTURA_H