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
		delete lista; // Liberar la lista anterior
		lista = nuevaLista; // Asignar la nueva lista
	}
}

Lista<Producto>* Carrito::getLista()
{
	return lista;
}

int Carrito::cantidadProductos()
{
	if (!lista) { // Si la lista es nula, no hay productos
		return 0;
	}

	int contador = 0;
	Nodo<Producto>* actual = lista->getPrimero(); // Obtener el primer nodo

	while (actual) { // Mientras haya nodos
		contador++; // Incrementar el contador por cada producto
		actual = actual->getSiguiente(); // Avanzar al siguiente nodo
	}

	return contador; // Devolver el número total de productos
}

void Carrito::agregarProducto(Producto* producto)
{
	if (lista) {
		lista->insertarFinal(producto);
	}
}

double Carrito::sumaPrecios()
{
	if (!lista) { // Si la lista es nula, el total es 0
		return 0.0;
	}

	double total = 0.0; // Variable para la suma total de precios
	Nodo<Producto>* actual = lista->getPrimero(); // Obtener el primer nodo

	// Recorre la lista para sumar los precios
	while (actual != nullptr) { // Mientras haya nodos
		Producto* producto = actual->getInfo(); // Obtener el producto
		if (producto != nullptr) { // Verificar que el puntero es válido
			double precio = producto->getPrecioCosto();  // Obtener el precio costo
			total += precio; // Sumar el precio al total
		}
		actual = actual->getSiguiente();
	}

	return total;
}

double Carrito::IVA()
{
	double subtotal = sumaPrecios(); // Calcular el subtotal
	double iva = subtotal * 0.13;  // Calcular el IVA (13% del subtotal)
	double total = subtotal + iva;  // Calcular el total con el IVA

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
	s << "     &============ = &Productos& = ============& " << endl;
	if (lista && !lista->listaVacia()) {
		int contador = 0; // Contador para contar los productos

		Nodo<Producto>* actual = lista->getPrimero(); // Obtener el primer nodo
		while (actual != nullptr) { // Recorre la lista de productos
			Producto* producto = actual->getInfo();
			s << producto->toString() << endl; // Agrega la información del producto
			contador++; // Incrementa el contador
			actual = actual->getSiguiente(); // Pasa al siguiente nodo
		}

		s << "Total de productos en el carrito: " << contador << endl;
		s << "Sub total: $" << sumaPrecios() << endl;
		s << "IVA: 13% " << " Total a pagar: " << IVA() << endl;
	}
	else {
		s << "El carrito está vacío." << endl;
	}

	s << "========================================================" << endl;
	return s.str();
}

//bool Carrito::agregarProductoPorCodigo(Almacen* almacen, string* codigo, int* cantidad) {
//	// Buscar el producto en el almacén por código
//	Producto* producto = dynamic_cast<Producto*>(almacen->buscarProductoCodigo(codigo));
//
//	if (!producto) {  // Producto no encontrado
//		std::cout << "Producto con código " << codigo << " no encontrado en el almacén." << std::endl;
//		return false;
//	}
//
//	// Verificar si hay suficiente existencia para la cantidad solicitada
//	int existencia = *(producto->getExistencia());
//	if (*cantidad > existencia) {
//		std::cout << "Cantidad solicitada excede la existencia disponible." << std::endl;
//		return false;  // No hay suficiente existencia
//	}
//
//	// Crear una copia del producto para el carrito
//	Producto* productoCarrito = new ConcreteProducto(producto);  // Usar constructor copia
//	productoCarrito->setExistencia(new int(*cantidad));  // Establece la cantidad deseada para el carrito
//
//	// Agregar al carrito
//	agregarProducto(productoCarrito);
//
//	// Actualizar la existencia en el almacén
//	producto->setExistencia(new int(existencia - *cantidad));  // Reducir la existencia en el almacén
//
//	std::cout << "Producto agregado al carrito." << std::endl;
//	return true;
//}






