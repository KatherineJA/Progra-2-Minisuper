#ifndef CONTROLADORA_H
#define CONTROLADORA_H
#include "InterfazUsuario.h"
#include "Almacen.h"
#include "Factura.h"

class Controladora {
private:
	InterfazUsuario* vista;
	Almacen* modelo= new Almacen();
	Factura* factura = new Factura(new Lista<Venta>());
	//Faltan cosas
public:
	void ejecutar();
	void ingresarProducto();
	void eliminarProducto();
	void actualizarProducto();
	void menuMantenimiento();
	void menuVentas();
	void menuReporte();
	~Controladora();

	void agregarAbarrote();
	void agregarConserva();
	void agregarEmbutido(); 

	

	 

	void crearFacturaCompra(); 
	/*Cliente* crearCliente();*/

    


};

#endif CONTROLADORA_H

