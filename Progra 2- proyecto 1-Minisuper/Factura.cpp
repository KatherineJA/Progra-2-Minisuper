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

  
    while (actual != nullptr) { 
        cout << "Numero de factura: " << contador << endl ; 
        actual = actual->getSiguiente(); 
        contador++; 
    }  
}

void Factura::MostrarVentaClienteCedula(string cedula)
{
   
    Nodo<Venta>* actual = ventas->getPrimero();
    while (actual != nullptr) {
        Venta* venta = actual->getInfo();
        if (venta->getCarrito()->getCliente()->getId() == cedula) {
            cout << venta->toString() <<endl;
            
            return; 
        }
        else {
           cout << "No se encontro ninguna venta para el cliente con cedula:  " << cedula << endl;
        }
        actual = actual->getSiguiente(); 
    }
}

void Factura::reporteMejoresClientes()
{
    if (!ventas) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

  
    struct ClienteMonto {
        string cedula;
        double montoTotal;
    };

  
    ClienteMonto mejoresClientes[5];

   
    for (int i = 0; i < 5; i++) {
        mejoresClientes[i].cedula = "";
        mejoresClientes[i].montoTotal = 0.0;
    }

    
    Nodo<Venta>* actualVenta = ventas->getPrimero();
    while (actualVenta != nullptr) {
        Venta* venta = actualVenta->getInfo();
        string cedulaCliente = venta->getCarrito()->getCliente()->getId();
        double montoTotal = venta->getCarrito()->sumaPrecios();

       
        for (int i = 0; i < 5; i++) {
            if (mejoresClientes[i].cedula == "" ||
                montoTotal > mejoresClientes[i].montoTotal) {
                
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
        Nodo<Venta>* actual = ventas->getPrimero();  
        int contador = 1; 

        
        while (actual != nullptr) {
            ss << "Numero de factura: " << contador << "\n"; 
            Venta* venta = actual->getInfo();
            ss << venta->toString() << std::endl; 
            actual = actual->getSiguiente();
            contador++; 
        }
    }

    return ss.str(); 
}

string Factura::toStringUltimo()
{
    std::stringstream ss;
    ss << "        ========== RESUMEN FACTURA ==========\n";

    if (ventas != nullptr) {
        Nodo<Venta>* actual = ventas->getPrimero();

        
        while (actual != nullptr && actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();  
        }

      
        if (actual != nullptr) {
            Venta* venta = actual->getInfo();
            ss << venta->toString() << std::endl;  
        }
    }

    return ss.str();
}


