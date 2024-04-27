#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H
#include <iostream>
#include "Producto.h"
#include "ConcreteProducto.h"
#include "Abarrote.h"
#include "Conserva.h"
#include "Carne.h"
#include "Embutido.h"
using namespace std;
//vista 
class InterfazUsuario
{
public:
	static void cabeza(); //		limpia la pantalla
	static int opcion(); //	acepta opciones/entradas
	static void pause();//	pausa el metodo

	static int menuPrincipal();
	static int menuMantenimiento();
	static int menuVentas();
	static int menuReporte();
	static int menuIngresoProducto();

	static int menuNombreCodigo();
	static int menuFacturas();
	static int menuProductos();
	static int menuActualizacionProducto(); 
	
	//capturadores
	



	//Nueva Version 
	Producto* capturarAbarrote(); 
	Producto* capturarConserva(); 
	Producto* capturarEmbutido(); 
	





	
};

#endif INTERFAZUSUARIO_H

