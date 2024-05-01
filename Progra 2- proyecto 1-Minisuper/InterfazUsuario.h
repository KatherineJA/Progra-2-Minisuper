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
	static void cabeza(); 
	static int opcion(); //	acepta opciones/entradas,excepcion 
	static void pause();

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
	string capturarCodigo(); 
	string capturarNombre(); 
	string capturarCedula(); 
	string capturarDescripcion(); 
	string capturarEmpresa(); 
	string capturarMarca();
	string capturarAnimal(); 
	string capturarParteAnimal(); 
	double capturarPrecio(); 
	double capturarPeso();
	int captuarCategoria(); 
	int capturarLimite(); 
	int capturarCantidad();
	int capturarExistencia();
	int capturarDia(); 
	int capturarAnnio(); 
	int capturarMes(); 
	bool capturarEnvasado(); 
	bool capturarNacionalidad(); 
	bool capturarTripa(); 
	//Nueva Version 
	Producto* capturarAbarrote(); 
	Producto* capturarConserva(); 
	Producto* capturarEmbutido(); 
	





	
};

#endif INTERFAZUSUARIO_H

