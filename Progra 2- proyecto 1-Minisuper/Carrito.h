#ifndef CARRITO_H
#define CARRITO_H
#include "Lista.h"
#include "Producto.h"
#include "ConcreteProducto.h"
#include "Cliente.h"
#include "Almacen.h"

class Carrito: public Cliente
{
private:
	Lista<Producto>* lista;
	Cliente* cliente;
public:
	Carrito();
	Carrito(Cliente* cliente,Lista<Producto>* lista);

	~Carrito();

	void setCliente(Cliente*);
	Cliente* getCliente();

	void setLista(Lista<Producto>*);
	Lista<Producto>* getLista();
	
	int cantidadProductos();
	//
	void agregarProducto(Producto*);

	double sumaPrecios();
	double IVA();
	bool estaVacio() const;

	string toStringCarrito();

	/*bool agregarProductoPorCodigo(Almacen*, string* ,int* );*/


	
};

#endif CARRITO_H