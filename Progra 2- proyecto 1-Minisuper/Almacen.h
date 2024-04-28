#ifndef ALMACEN_H
#define ALMACEN_H
#include "Includes.h"
//Reportes aqui
class Almacen
{
private:
	Lista<Producto>* listaProductos;
public:
	Almacen();
	Almacen(Lista<Producto>*);
	~Almacen();

	void setListaProductos(Lista<Producto>*);
	Lista<Producto>* getListaProductos();

	void agregarProductoAlmacen(Producto* );
	void actualizarProductoPorCodigo(string codigo, double nuevoPrecioCosto, int nuevaExistencia);
	void actualizarProductoPorNombre(string nombre, double nuevoPrecioCosto, int nuevaExistencia);
	bool ListaProductoVacia();

	void eliminarPorCodigo(string codigo);
	void eliminarPorNombreCM(string nombreCM);

	Producto* buscarProductoCodigo(string codigo);
	Producto* buscarProductoCategoria(int categoria);

	Lista<Producto>* seleccionarProductosPorCodigo(string codigo, int cantidad);
	 //Reportes
	string toString();
	
	Lista<Producto>* reporteCategorias(int categoria);
	Lista<Producto>* reporteProductosPorDebajoDelMinimo(); 
	
};

#endif ALMACEN_H