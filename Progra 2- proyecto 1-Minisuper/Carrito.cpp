#include "Carrito.h"

Carrito::Carrito()
{
	cliente = nullptr;
	lista = nullptr;
}

Carrito::Carrito(Cliente* cliente,Lista<Producto>* lista)
{ 
	this->cliente = cliente;
	this->lista = lista; 

}

Carrito::~Carrito()
{
	
}

void Carrito::setCliente(Cliente* nuevoCliente)
{
	this->cliente = nuevoCliente;
}

Cliente* Carrito::getCliente()
{
	return cliente;
}

void Carrito::setLista(Lista<Producto>* nuevaLista)
{
	if (lista != nuevaLista) {
		delete lista;
		lista = nuevaLista; // Asignar la nueva lista
	}
}

Lista<Producto>* Carrito::getLista()
{
	return lista;
}

int Carrito::cantidadProductos()
{
	if (!lista) {
		return 0;
	}

	int contador = 0;
	Nodo<Producto>* actual = lista->getPrimero();

	while (actual) {
		contador++;
		actual = actual->getSiguiente();
	}

	return contador;
}

void Carrito::agregarProducto(Producto* producto)
{
	if (lista) {
		lista->insertarFinal(producto);
	}
}

double Carrito::sumaPrecios()
{
	if (!lista) { 
		return 0.0;
	}

	double total = 0.0; 
	Nodo<Producto>* actual = lista->getPrimero(); 

	
	while (actual != nullptr) { 
		Producto* producto = actual->getInfo(); 
		if (producto != nullptr) { 
			double precio = producto->getPrecioCosto();  
			total += precio;
		}
		actual = actual->getSiguiente();
	}

	return total;
}

double Carrito::IVA()
{
	double subtotal = sumaPrecios(); 
	double iva = subtotal * 0.13; 
	double total = subtotal + iva;  

	return total; 
}



bool Carrito::estaVacio() const
{
	return lista ? lista->listaVacia() : true;
}

string Carrito::toStringCarrito()
{
	stringstream s;
	s << this->cliente->toString() << endl;
	s << "\033[1;32m     &============ =  Productos  = ============& \033[0m" << endl;
	if (lista && !lista->listaVacia()) {
		int contador = 0; 

		Nodo<Producto>* actual = lista->getPrimero();
		while (actual != nullptr) { 
			Producto* producto = actual->getInfo();
			s << producto->toStringFactu() << endl; 
			contador++;
			actual = actual->getSiguiente(); 
		}

		s << "Total de productos en el carrito: " << contador << endl;
		s << "Sub total: $" << sumaPrecios() << endl;
		s << "IVA: 13% " << " Total a pagar: " << IVA() << endl;
	}
	else {
		s << "El carrito esta vacio." << endl;
	}

	s << "========================================================" << endl;
	return s.str();
}





