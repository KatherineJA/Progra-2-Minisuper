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
    //Producto* producto;
    //ConcreteProducto* productoConcreto;
    //Fecha* fechaVencimiento;
    //Embutido* embutido;
    //Abarrote* abarrote;
    //Conserva* conserva;
    //Perecedero* perecedero;
    //ProdPerecedero* productoPerecedero;
    ////Abarrote
    //    //PRODUCTO BASE
    //string* codigo = vista->capturarCodigoProducto();
    //string* nombreConercial = vista->capturarNombreProducto();
    //string* descripcion = vista->capturarDescripcion();
    //string* categoria = vista->capturarCategoriaProducto();
    //double* precioCosto = vista->capturarPrecioProducto();
    //int* existencia = vista->capturarExistenciaProducto();
    //int* limite = vista->capturarLimiteProducto();
    //bool* nacional = vista->capturarNacional();
    //double* peso = vista->capturarPesoProducto();
    ////Abarrote
    //string* nombreEmpresa = vista->capturarNombreEmpresaProducto();
    ////FECHA
    //int* dia = vista->capturarDia();
    //int* mes = vista->capturarMes();
    //int* anio = vista->capturarAnnio();

    //fechaVencimiento = new Fecha(dia, mes, anio);

    //perecedero = new Perecedero(fechaVencimiento);

    //producto = new ConcreteProducto(codigo, nombreConercial, descripcion, categoria, precioCosto, existencia, limite);

    //productoPerecedero = new ProdPerecedero(producto, nacional, peso, perecedero);

    //Producto* productoN = new Abarrote(productoPerecedero, nacional, peso, nombreEmpresa);

   
}

void Controladora::agregarConserva()
{
    modelo->agregarProductoAlmacen(vista->capturarConserva());
    //Producto* producto;
    //ConcreteProducto* productoConcreto;
    //Fecha* fechaVencimiento;
    //Embutido* embutido;
    //Abarrote* abarrote;
    //Conserva* conserva;
    //Perecedero* perecedero;
    //ProdPerecedero* productoPerecedero;

    ////Conserva
    //string* codigo = vista->capturarCodigoProducto();
    //string* nombreConercial = vista->capturarNombreProducto();
    //string* descripcion = vista->capturarDescripcion();
    //string* categoria = vista->capturarCategoriaProducto();
    //double* precioCosto = vista->capturarPrecioProducto();
    //int* existencia = vista->capturarExistenciaProducto();
    //int* limite = vista->capturarLimiteProducto();
    //bool* embasado = vista->capturaEnvasado();

    //producto = new Conserva(codigo, nombreConercial, descripcion, categoria, precioCosto, existencia, limite, embasado);

}

void Controladora::agregarEmbutido()
{
    modelo->agregarProductoAlmacen(vista->capturarEmbutido());
    //Producto* producto;
    //ConcreteProducto* productoConcreto;
    //Fecha* fechaVencimiento;
    //Embutido* embutido;
    //Abarrote* abarrote;
    //Conserva* conserva;
    //Perecedero* perecedero;
    //ProdPerecedero* productoPerecedero;
    ////Embutido
    //   //PRODUCTO BASE
    //string* codigo = vista->capturarCodigoProducto();
    //string* nombreComercial = vista->capturarNombreProducto();
    //string* descripcion = vista->capturarDescripcion();
    //string* categoria = vista->capturarCategoriaProducto();
    //double* precioCosto = vista->capturarPrecioProducto();
    //int* existencia = vista->capturarExistenciaProducto();
    //int* limite = vista->capturarLimiteProducto();
    //bool* nacional = vista->capturarNacional();
    //double* peso = vista->capturarPesoProducto();
    ////Embutido 
    //string* marca = vista->capturarMarca();
    //bool* tripa = vista->capturarTripa();
    ////FECHA
    //int* dia = vista->capturarDia();
    //int* mes = vista->capturarMes();
    //int* anio = vista->capturarAnnio();

    //fechaVencimiento = new Fecha(dia, mes, anio);

    //perecedero = new Perecedero(fechaVencimiento);

    //producto = new ConcreteProducto(codigo, nombreComercial, descripcion, categoria, precioCosto, existencia, limite);

    //productoPerecedero = new ProdPerecedero(producto, nacional, peso, perecedero);

    //Producto* productoN = new Embutido(productoPerecedero, marca, tripa);

   
}
//
//void Controladora::actualizarPorNombre()
//{
//    string* nombre = vista->capturarNombreProducto(); 
//    double* nuevoPrecio = vista->capturarPrecioProducto();
//    int* nuevaExistencia = vista->capturarExistenciaProducto();
//    modelo->actualizarProductoPorNombre(nombre,nuevoPrecio,nuevaExistencia); 
//}
//
//void Controladora::actualizarPorCodigo()
//{
//    string* codigo = vista->capturarCodigoProducto(); 
//    double* nuevoPrecio = vista->capturarPrecioProducto();
//    int* nuevaExistencia = vista->capturarExistenciaProducto(); 
//    modelo->actualizarProductoPorCodigo(codigo, nuevoPrecio,nuevaExistencia);
//}
//
//void Controladora::eliminarPorNombre()
//{
//    string* nombreP = vista->capturarNombreProducto();
//    modelo->eliminarPorNombreCM(nombreP);
//}
//
//void Controladora::eliminarPorCodigo()
//{
//    string* codigo = vista->capturarCodigoProducto();
//    modelo->eliminarPorCodigo(codigo);
//}

void Controladora::crearFacturaCompra()
{
    string nombre  ;
    string cedula  ;

    cout << "Nombre del cliente:";
    cin >> nombre;
    cout << "Cedula del cliente: ";
    cin >> cedula;
    Cliente* cliente = new Cliente(nombre, cedula);
    string codigoProdu ;
    int cantiadproducts ;
    cout << "Codigo del producto:";
    cin >>codigoProdu;
    cout << "Cantidad del producto a llevar";
    cin >> cantiadproducts;

    Carrito* carrito = new Carrito(cliente, modelo->seleccionarProductosPorCodigo(codigoProdu, cantiadproducts));
    Fecha* f2 = new Fecha(6, 8, 2024);
    Venta* venta = new Venta(carrito, f2);
    Factura* factura = new Factura(new Lista<Venta>());
    factura->agregarVenta(venta);
    cout << factura->toString() << endl;
}

//Cliente* Controladora::crearCliente()
//{
//    string* nombreCliente = vista->capturarNombre(); 
//    string* cedula = vista->capturarId(); 
//
//    if (nombreCliente == nullptr || cedula == nullptr) { 
//        throw std::runtime_error("Datos del cliente no válidos"); 
//    }
//
//    Cliente* clientela = new Cliente(nombreCliente, cedula); 
//    return clientela; 
//}

//void Controladora::actualizarPorNombre()
//{
//    string* nombreP = vista->capturarNombreProducto(); 
//   POR EL AMOR DE DIOS NO DESCOMENTAR
//}

//void Controladora::agregarProducto()
//{
//    int tipo = vista->capturarTipo();
//    Producto* producto;
//    ConcreteProducto* productoConcreto;
//    Fecha* fechaVencimiento;
//    Embutido* embutido;
//    Abarrote* abarrote;
//    Conserva* conserva;
//    Perecedero* perecedero;
//    ProdPerecedero* productoPerecedero;
//    if (tipo == 1) {
//        //Conserva
//        string* codigo = vista->capturarCodigoProducto();
//        string* nombreConercial = vista->capturarNombreProducto();
//        string* descripcion = vista->capturarDescripcion();
//        string* categoria = vista->capturarCategoriaProducto();
//        double* precioCosto = vista->capturarPrecioProducto();
//        int* existencia = vista->capturarExistenciaProducto();
//        int* limite = vista->capturarLimiteProducto();
//        bool* embasado = vista->capturaEnvasado();
//
//        producto = new Conserva(codigo, nombreConercial, descripcion, categoria, precioCosto, existencia, limite, embasado);
//        modelo->agregarProductoAlmacen(producto);
//    }
//    if (tipo == 2) {
//        //Abarrote
//        //PRODUCTO BASE
//        string* codigo = vista->capturarCodigoProducto();
//        string* nombreConercial = vista->capturarNombreProducto();
//        string* descripcion = vista->capturarDescripcion();
//        string* categoria = vista->capturarCategoriaProducto();
//        double* precioCosto = vista->capturarPrecioProducto();
//        int* existencia = vista->capturarExistenciaProducto();
//        int* limite = vista->capturarLimiteProducto();
//        bool* nacional = vista->capturarNacional();
//        double* peso = vista->capturarPesoProducto();
//        //Abarrote
//        string* nombreEmpresa = vista->capturarNombreEmpresaProducto();
//        //FECHA
//        int* dia = vista->capturarDia();
//        int* mes = vista->capturarMes();
//        int* anio = vista->capturarAnnio();
//
//        fechaVencimiento = new Fecha(dia, mes, anio);
//
//        perecedero = new Perecedero(fechaVencimiento);
//
//        producto = new ConcreteProducto(codigo, nombreConercial, descripcion, categoria, precioCosto, existencia, limite);
//
//        productoPerecedero = new ProdPerecedero(producto, nacional, peso, perecedero);
//      
//        Producto* productoN = new Abarrote(productoPerecedero, nacional, peso, nombreEmpresa);
//
//        modelo->agregarProductoAlmacen(productoN);
//    }
//    if (tipo == 3) {
//        //Embutido
//        //PRODUCTO BASE
//        string* codigo = vista->capturarCodigoProducto();
//        string* nombreConercial = vista->capturarNombreProducto();
//        string* descripcion = vista->capturarDescripcion();
//        string* categoria = vista->capturarCategoriaProducto();
//        double* precioCosto = vista->capturarPrecioProducto();
//        int* existencia = vista->capturarExistenciaProducto();
//        int* limite = vista->capturarLimiteProducto();
//        bool* nacional = vista->capturarNacional();
//        double* peso = vista->capturarPesoProducto();
//        //Embutido 
//        string* marca = vista->capturarMarca(); 
//        bool* tripa = vista->capturarTripa(); 
//        //FECHA
//        int* dia = vista->capturarDia();
//        int* mes = vista->capturarMes();
//        int* anio = vista->capturarAnnio();
//
//        fechaVencimiento = new Fecha(dia, mes, anio);
//
//        perecedero = new Perecedero(fechaVencimiento);
//
//        producto = new ConcreteProducto(codigo, nombreConercial, descripcion, categoria, precioCosto, existencia, limite);
//
//        productoPerecedero = new ProdPerecedero(producto, nacional, peso, perecedero);
//
//        Producto* productoN = new Embutido(productoPerecedero,marca, tripa);
//
//        modelo->agregarProductoAlmacen(productoN);
//    }
//}

