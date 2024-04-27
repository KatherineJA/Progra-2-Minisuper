#include "InterfazUsuario.h"
#include "Excepciones.h"
#include "ConcreteProducto.h"

void InterfazUsuario::cabeza() {
    system("cls");
    cout << "\033[1;33m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "                Bienvenido al Mini Super\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
}
int InterfazUsuario::opcion() {

    int opc;
    cout << "Por favor, seleccione una opcion:\n";
    //Poner aqui un manejo de excepciones
    cin >> opc;
    if (cin.fail()) {
        cin.clear(); // Limpiar el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar la entrada incorrecta
        throw ExcepcionCaracterInvalido();
    }

    return opc;
}

void InterfazUsuario::pause() {
    system("pause");
}

int InterfazUsuario::menuPrincipal() {
    cabeza();
    cout << "\033[1m1. Mantenimiento\n";
    cout << "2. Ventas\n";
    cout << "3. Reportes\n";
    cout << "4. Salir\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int InterfazUsuario::menuMantenimiento() {
    cabeza();
    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "                    Menu de Mantenimiento\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";

    cout << "\033[1m1. Ingreso de Producto\n";
    cout << "2. Eliminacion de Producto\n";
    cout << "3. Actualizacion de Producto\n";
    cout << "4. Retornar al Menu Principal\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int InterfazUsuario::menuVentas()
{
    cout << "\033[1;35m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "                      Menu de Ventas\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
    cout << "\033[1m1. Crear Factura Nueva\n";
    cout << "2. Retornar al Menu Principal\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int InterfazUsuario::menuReporte()
{
    cout << "\033[1;32m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "                      Menu de Reportes\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";

    cout << "\033[1m1. Reportar todos los productos del Mini Super\n";
    cout << "2. Reportar productos por categoria\n";
    cout << "3. Reportar productos por debajo del minimo de existencia\n";
    cout << "4. Reportar facturas por cedula de cliente\n";
    cout << "5. Reportar las cedulas de los 5 mejores clientes\n";
    cout << "6. Retornar al Menu Principal\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int InterfazUsuario::menuIngresoProducto()
{
    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "             Ingreso de Producto\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
    cout << "\033[1m1. Tipo Conserva\n";
    cout << "2. Tipo Abarrote\n";
    cout << "3. Tipo Embutido\n";
    cout << "4. Retornar al Menu de Mantenimiento\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

//int InterfazUsuario::menuEliminacionProducto()
//{
//    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//    cout << "             Eliminacion de Producto\n";
//    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
//    cout << "\033[1m1. Eliminacion por codigo\n";
//    cout << "2.Eliminacion por nombre comercial \n";
//    cout << "3. Retornar al Men� de Mantenimiento\n\n\033[0m";
//    return opcion(); 
//}
//
//int InterfazUsuario::menuActualizacionProducto()
//{
//    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//    cout << "             Actualiacion de Producto\n";
//    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
//    cout << "\033[1m1.  Actualiacion por codigo\n";
//    cout << "2. Actualiacion por nombre comercial \n";
//    cout << "3. Retornar al Men� de Mantenimiento\n\n\033[0m";
//    return opcion();
//
//}

int InterfazUsuario::menuNombreCodigo()
{
    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "             Nombre Comercial o Codigo \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
    cout << "\033[1m1. Por codigo\n";
    cout << "2. Por nombre comercial \n";
    cout << "3. Retornar al Menu Anterior\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }

}


int InterfazUsuario::menuFacturas()
{
    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "             Manejo de Facturas\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
    cout << "\033[1m1. Eliminar factura\n";
    cout << "2.Actualizar factura \n";
    cout << "3. Retornar al Men� de Mantenimiento\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}


int InterfazUsuario::menuProductos()
{
    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "            Manejo de Productos\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
    cout << "\033[1m1.Ingreso Producto\n";
    cout << "2.Eliminacion Producto \n";
    cout << "3.Modificar Producto \n";
    cout << "4. Retornar al Men� de Mantenimiento\n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int InterfazUsuario::menuActualizacionProducto()
{
    cout << "1. Actualizacion del precio: " << endl; 
    cout << "2. Actualizacion de la existencia:  " << endl; 
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}



Producto* InterfazUsuario::capturarAbarrote()
{
    string codigo ;
    string NombreCM ;
    string Des ;
    int catgoria;
    string empresa ; 
    double precio ;
    int cantidad ;
    int existencia ;
    bool nacionalidad ; 
    double peso ; 

    cout << "Ingrese el código del producto: ";
    cin >> codigo;  // Leer entrada para 'codigo'

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();   // Limpiar el buffer para getline
    cin >> NombreCM;// Leer entrada para 'nombreCM '

    cout << "Ingrese la descripción del producto: ";
    getline(cin, Des);  // Leer entrada para 'descripcion'

    cout << "Ingrese la categoría del producto: ";
    cin>> catgoria;  // Leer entrada para 'categoria'

    cout << "Ingrese el precio del producto: ";
    cin >> precio;  // Leer entrada para 'precio'

    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;  // Leer entrada para 'cantidad'

    cout << "Ingrese la existencia del producto: ";
    cin >> existencia;  // Leer entrada para 'existencia'

    Producto* concreto = new ConcreteProducto(codigo, NombreCM, Des, catgoria, precio, existencia, cantidad); 
    int dia ;
    int anio ;
    int mes ;
    cout << "Ingrese el día de caducidad del perecedero: ";
    cin >> dia;
    cout << "Ingrese el mes de caducidad del perecedero: ";
    cin >> mes;
    cout << "Ingrese el año de caducidad del perecedero: ";
    cin >> anio;
    Fecha* f11 = new Fecha(dia, mes, anio);
    Perecedero* p1 = new Perecedero(f11);
    cout << "Es nacional? (0 para no, 1 para si): ";
    cin >> nacionalidad;
    cout << "Ingrese el peso del producto:"; 
    cin >> peso; 
    cout << "Ingrese la empresa del producto: ";
    cin >> empresa;  

    ProdPerecedero* abarrote = new Abarrote(concreto, empresa,peso,nacionalidad); 


   
    return abarrote; 
}

Producto* InterfazUsuario::capturarConserva()
{
    string codigo;
    string NombreCM ;
    string Des;
    int catgoria ;
    double precio ;
    int cantidad ;
    int existencia ;
    bool envasado; 
    cout << "Ingrese el código del producto: ";
    cin >> codigo;  // Leer entrada para 'codigo'

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();   // Limpiar el buffer para getline
    cin >> NombreCM;// Leer entrada para 'nombreCM '

    cout << "Ingrese la descripción del producto: ";
    getline(cin, Des);  // Leer entrada para 'descripcion'

    cout << "Ingrese la categoría del producto: ";
    cin >> catgoria;   // Leer entrada para 'categoria'

    cout << "Ingrese el precio del producto: ";
    cin >> precio;  // Leer entrada para 'precio'

    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;  // Leer entrada para 'cantidad'

    cout << "Ingrese la existencia del producto: ";
    cin >> existencia;  // Leer entrada para 'existencia'
    
    cout << "¿Está envasado? (0 para No, 1 para Si): ";
    cin >> envasado;

    Producto* conserva = new Conserva(codigo,NombreCM,Des,catgoria,precio,existencia,cantidad,envasado);
    return conserva; 

}

Producto* InterfazUsuario::capturarEmbutido()
{
    string codigo;
    string NombreCM;
    string Des;
    int catgoria;
    string marca;
    double precio;
    int cantidad;
    int existencia;
    bool nacionalidad;
    bool tripa; 
    double peso;
    string animal; 
    string parteAnimal; 
    cout << "Ingrese el código del producto: ";
    cin >> codigo;  // Leer entrada para 'codigo'

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();   // Limpiar el buffer para getline
    cin >> NombreCM;// Leer entrada para 'nombreCM '

    cout << "Ingrese la descripción del producto: ";
    getline(cin, Des);  // Leer entrada para 'descripcion'

    cout << "Ingrese la categoría del producto: ";
    cin >> catgoria;  // Leer entrada para 'categoria'

    cout << "Ingrese el precio del producto: ";
    cin >> precio;  // Leer entrada para 'precio'

    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;  // Leer entrada para 'cantidad'

    cout << "Ingrese la existencia del producto: ";
    cin >> existencia;  // Leer entrada para 'existencia'

    Producto* concreto = new ConcreteProducto(codigo, NombreCM, Des, catgoria, precio, existencia, cantidad);
    int dia;
    int anio;
    int mes;
    cout << "Ingrese el día de caducidad del perecedero: ";
    cin >> dia;
    cout << "Ingrese el mes de caducidad del perecedero: ";
    cin >> mes;
    cout << "Ingrese el año de caducidad del perecedero: ";
    cin >> anio;
    Fecha* f11 = new Fecha(dia, mes, anio);
    Perecedero* p1 = new Perecedero(f11);
    cout << "Es nacional? (0 para no, 1 para si): ";
    cin >> nacionalidad;
    cout << "Ingrese el peso del producto:";
    cin >> peso;
    cout << "Ingrese la marca del producto: ";
    getline(cin, marca);
    cout << "Ingrese el nombre del animal del producto: ";
    getline(cin, animal);
    cout << "Ingrese la parte del animal del producto: ";
    getline(cin, parteAnimal);
    cout << "Es de tripa el producto 1 para si 0 para no ";
    cin >> tripa; 

    ProdPerecedero* carne = new Carne(concreto, animal, parteAnimal,peso,nacionalidad); 
    Producto* embutido = new Embutido(carne, marca, tripa);


    return embutido;
}





