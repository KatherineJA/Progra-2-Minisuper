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
        modelo->eliminarPorCodigo(vista->capturarCodigo());
        break;
    }
    case 2: {
        modelo->eliminarPorNombreCM(vista->capturarNombre());
        break;
    }
    case 3: {
        // Retornar al menu de mantenimiento
        break;
    }
    }
}

void Controladora::actualizarProductoPrecio() {
    int opcionActualizacion = vista->menuNombreCodigo();
    switch (opcionActualizacion) {
    case 1: {
        modelo->actualizarProductoPrecioPorCodigo(vista->capturarCodigo(), vista->capturarPrecio());
        break;
    }
    case 2: {
        modelo->actualizarProductoPrecioPorNombre(vista->capturarNombre(),vista->capturarPrecio());
        break;
    }
    case 3: {
        // Retornar al menu de mantenimiento
        break;
    }
    }
}

void Controladora::actualizarProductoExistencia()
{
    int opcionActualizacion = vista->menuNombreCodigo();
    switch (opcionActualizacion) {
    case 1: {
        string codigo = vista->capturarCodigo(); 
        int existenciaNueva = vista->capturarExistencia(); 
        modelo->actualizarExistenciaPorCodigo(codigo,existenciaNueva);
        break;
    }
    case 2: {
        string nombre = vista->capturarNombre(); 
        int existenciaNueva = vista->capturarExistencia(); 
        modelo->actulizarExistenciaPorNombre(nombre,existenciaNueva);
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
        cout << "Antes de continuar ";
        if (modelo->verificarCod(vista->capturarCodigo()) == false) {
            system("pause");
            system("cls");
            ingresarProducto();
            system("pause");
        }
        else {
            cout << "Ya existe un producto con ese código, Si desea actualizarlo o saber más información, diríjase al apartado respectivo (Actualizar)." << endl;
            system("pause");
            return;
        }
       
        break;
    }
    case 2: {
        eliminarProducto();
        break;
    }
    case 3: {
        menuActualizar(); 
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
        
        modelo->reporteCategorias(vista->captuarCategoria()); 
        system("pause"); 
        break;
    }
    case 3: {
        modelo->reporteProductosPorDebajoDelMinimo(); 
        system("pause");
        break;
    }
    case 4: {
        
        factura->MostrarVentaClienteCedula(vista->capturarCedula());
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

void Controladora::menuActualizar()
{
    int opcion = vista->menuActualizacionProducto(); 
    switch (opcion){
    case 1: {
        actualizarProductoPrecio(); 
        system("pause");
        break;
    }
    case 2: {
        actualizarProductoExistencia(); 
        system("pause");
        break;
    }
    case 3: {
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
    
    Cliente* cliente = new Cliente(vista->capturarNombre(), vista->capturarCedula()); 
   
    Carrito* carrito = new Carrito(cliente, modelo->seleccionarProductosPorCodigo()); 
    Fecha* f2 = new Fecha(6, 8, 2024); 
    Venta* venta = new Venta(carrito, f2); 
    factura->agregarVenta(venta); 
    cout << factura->toStringUltimo() << endl; 
    system("pause"); 
    system("cls"); 
   
  
}



