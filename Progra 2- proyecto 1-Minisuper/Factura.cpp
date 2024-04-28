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
    int contador = 1; 

    // Iterar sobre la lista para mostrar el número de factura de cada venta
    while (actual != nullptr) { 
        cout << "Numero de factura: " << contador << endl ; // Muestra el número según la posición
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
            cout << venta->toString() <<endl;
            
            return; // Muestra la venta y termina
        }
        else {
           cout << "No se encontro ninguna venta para el cliente con cedula:  " << cedula << endl;
        }
        actual = actual->getSiguiente(); // Avanza al siguiente nodo
    }
}

void Factura::reporteMejoresClientes()
{
    if (!ventas) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    // Estructura para almacenar cliente y monto total
    struct ClienteMonto {
        string cedula;
        double montoTotal;
    };

    // Arreglo para almacenar los 5 mejores clientes
    ClienteMonto mejoresClientes[5];

    // Inicializar con valores vacíos
    for (int i = 0; i < 5; i++) {
        mejoresClientes[i].cedula = "";
        mejoresClientes[i].montoTotal = 0.0;
    }

    // Recorrido de ventas
    Nodo<Venta>* actualVenta = ventas->getPrimero();
    while (actualVenta != nullptr) {
        Venta* venta = actualVenta->getInfo();
        string cedulaCliente = venta->getCarrito()->getCliente()->getId();
        double montoTotal = venta->getCarrito()->sumaPrecios();

        // Buscar en los 5 mejores
        for (int i = 0; i < 5; i++) {
            if (mejoresClientes[i].cedula == "" ||
                montoTotal > mejoresClientes[i].montoTotal) {
                // Desplazar elementos a la derecha para insertar
                for (int j = 4; j > i; j--) {
                    mejoresClientes[j] = mejoresClientes[j - 1];
                }
                mejoresClientes[i].cedula = cedulaCliente;
                mejoresClientes[i].montoTotal = montoTotal;
                break;
            }
        }

        actualVenta = actualVenta->getSiguiente();
    }

    // Imprimir los 5 mejores clientes
    cout << "========== 5 MEJORES CLIENTES ==========\n";
    for (int i = 0; i < 5; i++) {
        if (mejoresClientes[i].cedula != "") {
            cout << i + 1 << ". Cedula: " << mejoresClientes[i].cedula;
        }
    }
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
            ss << "Numero de factura: " << contador << "\n";  // Muestra el número de factura
            Venta* venta = actual->getInfo();
            ss << venta->toString() << std::endl;  // Usa el método toString() para mostrar detalles de la venta
            actual = actual->getSiguiente();  // Avanza al siguiente nodo
            contador++; //  Incrementar el contador
        }
    }

    return ss.str();  // Devuelve el resumen de la factura
}

string Factura::toStringUltimo()
{
    std::stringstream ss;
    ss << "        ========== RESUMEN FACTURA ==========\n";

    if (ventas != nullptr) {
        Nodo<Venta>* actual = ventas->getPrimero();

        // Recorre la lista para llegar al último nodo
        while (actual != nullptr && actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();  // Avanza hasta el último nodo
        }

        // En este punto, 'actual' es el último nodo de la lista
        if (actual != nullptr) {
            Venta* venta = actual->getInfo();
            ss << venta->toString() << std::endl;  // Usa el método toString() para mostrar detalles de la venta
        }
    }

    return ss.str();
}


