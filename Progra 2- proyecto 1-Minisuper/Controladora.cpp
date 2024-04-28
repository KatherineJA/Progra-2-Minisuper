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
            salir = true; 
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
        string codigo;
        cout << "Ingrese el codigo del producto a eliminar:";
        cin >> codigo;
        modelo->eliminarPorCodigo(codigo);
        break;
    }
    case 2: {
        string nombrePC;
        cout << "Ingrese el nombre del producto a eliminar:";
        getline(cin, nombrePC);
        modelo->eliminarPorNombreCM(nombrePC);
        break;
    }
    case 3: {
        // Retornar al menu de mantenimiento
        break;
    }
    }
}

void Controladora::actualizarProducto() {
    int opcionActualizacion = vista->menuNombreCodigo();
    switch (opcionActualizacion) {
    case 1: {
        string codigo; 
        double nuevoPrecio; 
        double nuevaExistencia; 
        cout << "Ingrese el codigo del producto a actualizar "; 
        cin >> codigo; 
        cout << "Ingrese el nuevo Precio del producto a actualizar ";
        cin >> nuevoPrecio;
        cout << "Ingrese la nueva Existencia del producto a actualizar ";
        cin >> nuevaExistencia;
        modelo->actualizarProductoPorCodigo(codigo,nuevoPrecio,nuevaExistencia);
        break;
    }
    case 2: {
        string nombreCM;
        double nuevoPrecio;
        double nuevaExistencia;
        cout << "Ingrese el nombre Comercial del producto a actualizar ";
        cin >> nombreCM;
        cout << "Ingrese el nuevo Precio del producto a actualizar ";
        cin >> nuevoPrecio;
        cout << "Ingrese la nueva Existencia del producto a actualizar ";
        cin >> nuevaExistencia;
        modelo->actualizarProductoPorNombre(nombreCM, nuevoPrecio, nuevaExistencia);
        break;
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
        // Retornar al menu principal
        break;
    }
    }
}

void Controladora::menuReporte() {
    int opcion = vista->menuReporte();
    switch (opcion) {
    case 1: {
        // Logica para reportar todos los productos
       cout << modelo->toString();
       system("pause");
        break;
    }
    case 2: {
        int categoria;
        cout << "Ingrese la categoria que desea ver el reporte: " << endl; 
        cin >> categoria; 
        modelo->reporteCategorias(categoria); 
        system("pause"); 
        break;
    }
    case 3: {
        modelo->reporteProductosPorDebajoDelMinimo(); 
        system("pause");
        break;
    }
    case 4: {
        string id;
        cout << "Ingrese la cedula del cliente: ";
        cin >> id;
        factura->MostrarVentaClienteCedula(id);
        system("pause");
        break;
    }
    case 5: {
        factura->reporteMejoresClientes(); 
        system("pause"); 
        break;
    }
    case 6: {
        // Salir del programa (retornar al menu principal)

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
    factura->agregarVenta(venta);
    cout << factura->toString() << endl;
}



