#ifndef ALMACEN_H
#define ALMACEN_H
#include "Lista.h"
#include "Producto.h"
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
	void actualizarProductoPrecioPorCodigo(string codigo, double nuevoPrecioCosto);
	void actualizarProductoPrecioPorNombre(string nombre, double nuevoPrecioCosto);
	bool ListaProductoVacia();
	void actualizarExistenciaPorCodigo(string codigo, int cantidad);
	void actulizarExistenciaPorNombre(string codigo, int existencia);
	void eliminarPorCodigo(string codigo);
	void eliminarPorNombreCM(string nombreCM);
	bool verificarCod(string cod);
	Producto* buscarProductoCodigo(string codigo);
	Producto* buscarProductoCategoria(int categoria);

	Lista<Producto>* seleccionarProductosPorCodigo(string codigo, int cantidad);
	 //Reportes
	string toString();
	
	Lista<Producto>* reporteCategorias(int categoria);
	Lista<Producto>* reporteProductosPorDebajoDelMinimo(); 
	
	
};

#endif ALMACEN_H