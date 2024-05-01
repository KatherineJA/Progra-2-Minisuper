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
	
public:
	void ejecutar();
	void ingresarProducto();
	void eliminarProducto();
	void actualizarProductoPrecio();
	void actualizarProductoExistencia();
	void menuMantenimiento();
	void menuVentas();
	void menuReporte();
	void menuActualizar(); 
	~Controladora();

	void agregarAbarrote();
	void agregarConserva();
	void agregarEmbutido(); 

	

	 

	void crearFacturaCompra(); 


    


};

#endif CONTROLADORA_H

