#ifndef CONTROLADORA_H
#define CONTROLADORA_H
#include "InterfazUsuario.h"
#include "Carrito.h"
#include "Factura.h"
#include "Venta.h"
#include "Cliente.h"
#include "Producto.h"
#include "ConcreteProducto.h"
#include "Abarrote.h"
#include "Carne.h"
#include "Conserva.h"
#include "Embutido.h"
#include "Almacen.h"
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

	//void actualizarPorNombre(); 
	//void actualizarPorCodigo();

	//void eliminarPorNombre(); 
	//void eliminarPorCodigo(); 

	void crearFacturaCompra(); 
	/*Cliente* crearCliente();*/

    


};

#endif CONTROLADORA_H

