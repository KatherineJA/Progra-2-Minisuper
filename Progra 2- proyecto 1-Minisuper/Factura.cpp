#include "Factura.h"
#include "Factura.h"


Factura::Factura()
{
	ventas = nullptr;
   
}



Factura::Factura(Lista<Venta>* ventas)
{
	this->ventas = ventas;

}

Factura::~Factura()
{
	/*delete ventas;*/ //Es necesario eliminar ventas si nunca se uso el new?
}
//Logica para crear una factura nueva
void Factura::agregarVenta(Venta* venta)
{
	ventas->insertarFinal(venta);
}

const Lista<Venta>* Factura::getVentas()
{
	return ventas;
}




void Factura::NumeroFactura()
{
    if (ventas == nullptr) { 
        cout << "No hay ventas registradas.\n"; 
        return; 
    }

    Nodo<Venta>* actual = ventas->getPrimero(); 
    int contador = 1; // Contador para el número de factura 

    // Iterar sobre la lista para mostrar el número de factura de cada venta
    while (actual != nullptr) { 
        cout << "Número de factura: " << contador << endl ; // Muestra el número según la posición
        actual = actual->getSiguiente(); // Avanza al siguiente nodo 
        contador++; // Incrementar el contador 
    }  
}

void Factura::MostrarVentaClienteCedula(string cedula)
{
    // Recorre la lista de ventas buscando la venta con la cédula especificada
    Nodo<Venta>* actual = ventas->getPrimero();
    while (actual != nullptr) {
        Venta* venta = actual->getInfo();
        if (venta->getCarrito()->getCliente()->getId() == cedula) {
            std::cout << venta->toString() << std::endl;
            return; // Muestra la venta y termina
        }
        actual = actual->getSiguiente(); // Avanza al siguiente nodo
    }
    std::cout << "No se encontró ninguna venta para el cliente con cédula: " << cedula << std::endl;
}

string Factura::toString()
{
    std::stringstream ss;
    ss << "        ========== RESUMEN FACTURA ==========\n";

    if (ventas != nullptr) { 
        Nodo<Venta>* actual = ventas->getPrimero();  // Declaración inicial
        int contador = 1; //  Para mostrar el número de factura por cada venta

        // Mientras recorres la lista, muestra el número de factura y detalles de la venta
        while (actual != nullptr) {
            ss << "Número de factura: " << contador << "\n";  // Muestra el número de factura
            Venta* venta = actual->getInfo();
            ss << venta->toString() << std::endl;  // Usa el método toString() para mostrar detalles de la venta
            actual = actual->getSiguiente();  // Avanza al siguiente nodo
            contador++; //  Incrementar el contador
        }
    }

    return ss.str();  // Devuelve el resumen de la factura
}
