#ifndef ALMACEN_H
#define ALMACEN_H
#include "Producto.h"
#include "Lista.h"
#include "ConcreteProducto.h"
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
	
	Lista<Producto>* seleccionarProductosPorCodigo(string codigo, int cantidad);
	
	string toString();
};

#endif ALMACEN_H