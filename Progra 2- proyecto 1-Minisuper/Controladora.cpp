#include "Controladora.h"


void Controladora::ejecutar() {
    bool salir = false;
    while (!salir) {
        int opcion = vista->menuPrincipal();
        switch (opcion) {
        case 1: {
            menuMantenimiento();
            break;
        }
        case 2: {
            menuVentas();
            break;
        }
        case 3: {
            menuReporte();
            break;
        }
        case 4: {
            salir = true;
            break;
        }

        }
    }
}



void Controladora::menuVentas() {
    bool salir = false;
    while (!salir) {
        int opcion = vista->menuVentas();
        switch (opcion) {
        case 1: {
            crearFacturaCompra(); 
            break;
        }
        case 2: {
            salir = true; // Salir del men� de ventas y retornar al men� principal
            break;
        }

        }
    }
}






void Controladora::ingresarProducto() {
    int opcionTipoProducto = vista->menuIngresoProducto();
    switch (opcionTipoProducto) {
    case 1: {
        agregarConserva(); 
        break;
    }
    case 2: {
        agregarAbarrote();
        break;
    }
    case 3: {
        agregarEmbutido(); 
        break;
    }
    case 4: {
        // Retornar al menu de mantenimiento
        break;
    }
    }
}

void Controladora::eliminarProducto() {
    int opcionEliminacion = vista->menuNombreCodigo();
    switch (opcionEliminacion) {
    case 1: {
    /*    eliminarPorCodigo(); */
        break;
    }
    case 2: {
    /*    eliminarPorNombre();*/
        break;
    }
    case 3: {
        // Retornar al men� de mantenimiento
        break;
    }
    }
}

void Controladora::actualizarProducto() {
    int opcionActualizacion = vista->menuNombreCodigo();
    switch (opcionActualizacion) {
    case 1: {
      /*  actualizarPorCodigo(); */
        break;
    }
    case 2: {
       /* actualizarPorNombre();*/ 
    }
    case 3: {
        // Retornar al menu de mantenimiento
        break;
    }
    }
}

void Controladora::menuMantenimiento() {
    int opcion = vista->menuMantenimiento();
    switch (opcion) {
    case 1: {
        ingresarProducto();
        break;
    }
    case 2: {
        eliminarProducto();
        break;
    }
    case 3: {
        actualizarProducto();
        break;
    }
    case 4: {
        // Retornar al men� principal
        break;
    }
    }
}

void Controladora::menuReporte() {
    int opcion = vista->menuReporte();
    switch (opcion) {
    case 1: {
        // L�gica para reportar todos los productos
        cout << modelo->toString();
        break;
    }
    case 2: {
        // L�gica para reportar productos por categor�a
        break;
    }
    case 3: {
        // L�gica para reportar productos por debajo del m�nimo de existencia
        break;
    }
    case 4: {
        // L�gica para reportar facturas por c�dula de cliente
        break;
    }
    case 5: {
        // L�gica para reportar las c�dulas de los 5 mejores clientes
        break;
    }
    case 6: {
        // Salir del programa (retornar al men� principal)

        break;
    }
    }
}

Controladora::~Controladora()
{
}

void Controladora::agregarAbarrote()
{
    modelo->agregarProductoAlmacen(vista->capturarAbarrote());
  
}

void Controladora::agregarConserva()
{
    modelo->agregarProductoAlmacen(vista->capturarConserva());

}

void Controladora::agregarEmbutido()
{
    modelo->agregarProductoAlmacen(vista->capturarEmbutido());
}

void Controladora::crearFacturaCompra()
{
    string nombre  ;
    string cedula  ;

    cout << "Nombre del cliente: ";
    cin >> nombre;
    cout << "Cedula del cliente: ";
    cin >> cedula;
    Cliente* cliente = new Cliente(nombre, cedula);
    string codigoProdu ;
    int cantiadproducts ;
    cout << "Codigo del producto: ";
    cin >>codigoProdu;
    cout << "Cantidad del producto a llevar: ";
    cin >> cantiadproducts;

    Carrito* carrito = new Carrito(cliente, modelo->seleccionarProductosPorCodigo(codigoProdu, cantiadproducts));
    Fecha* f2 = new Fecha(6, 8, 2024);
    Venta* venta = new Venta(carrito, f2);
    Factura* factura = new Factura(new Lista<Venta>());
    factura->agregarVenta(venta);
    cout << factura->toString() << endl;
}



