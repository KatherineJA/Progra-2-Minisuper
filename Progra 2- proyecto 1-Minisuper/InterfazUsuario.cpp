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
    cin >> opc;
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
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
    cout << "3. Retornar al Menu de Mantenimiento\n\n\033[0m";
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
    cout << "\033[1;36m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "           Actualizacion Productos\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m\n\n";
    cout << "\033[1m1.Actualizar Precio\n";
    cout << "2.Actualizar Existencia \n";
    cout << "3. Retornar al menu anterior \n\n\033[0m";
    try {
        return  opcion();
    }
    catch (const excepciones& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

string InterfazUsuario::capturarCodigo()
{
    string codigo;

    while (true) { 
        cout << "Ingrese el codigo del producto: ";
        cin >> codigo;

        if (codigo == "0") {
            cout << "El código '0' no es válido. Intente de nuevo." << endl;
        }
        else {
            break; 
        }
    }

    return codigo;
}

string InterfazUsuario::capturarNombre()
{
    string nombre; 
    cout << "Ingrese el Nombre: " ;
    cin>> nombre;
    return nombre; 
}

string InterfazUsuario::capturarCedula()
{
    string cedula; 
    cout << "Ingrese la cedula del cliente: " ; 
 
    cin>> cedula; 
    return cedula; 
}

string InterfazUsuario::capturarDescripcion()
{
    string Des; 
    cout << "Ingrese la descripcion del producto: ";
   
    cin >> Des;
    return Des; 
}

string InterfazUsuario::capturarEmpresa()
{
    string Empresa;
    cout << "Ingrese el nombre de la Empresa : ";
   
    cin>>Empresa;
    return Empresa;
}

string InterfazUsuario::capturarMarca()
{
    string Marca;
    cout << "Ingrese el nombre de la Marca: ";
    
    cin >> Marca;
    return Marca;
}

string InterfazUsuario::capturarAnimal()
{
    string Animal;
    cout << "Ingrese el nombre del Animal: ";

   cin>> Animal;
    return Animal; 
}

string InterfazUsuario::capturarParteAnimal()
{
    string ParteAnimal;
    cout << "Ingrese el nombre de la parte del Animal : ";
  
    cin>> ParteAnimal;
    return ParteAnimal;
}

double InterfazUsuario::capturarPrecio()
{
    double precio; 
    cout << "Ingrese el precio: " ; 
    cin >> precio; 
    return precio; 
}

double InterfazUsuario::capturarPeso()
{
    double peso;
    cout << "Ingrese el peso: ";
    
    cin >> peso;
    return peso;
}

int InterfazUsuario::captuarCategoria()
{
    int categoria; 
    cout << " Ingrese la categoria del producto "; 
    cin >> categoria; 
    return categoria; 
}

int InterfazUsuario::capturarLimite()
{
    int limite; 
    cout << " Ingrese el limite del producto: "; 
    cin >> limite; 
    return limite; 
}

int InterfazUsuario::capturarCantidad()
{
    int cantidad;
    cout << "Ingrese la cantidad de productos que desea comprar: ";
    cin >> cantidad;
    return cantidad;
}

int InterfazUsuario::capturarExistencia()
{
    int existencia; 
    cout << "Ingrese la existencia del producto: ";
    cin >> existencia;  
    return existencia; 
}

int InterfazUsuario::capturarDia()
{
    int dia; 
    cout << "Ingrese el dia: "; 
    cin >> dia; 
    return dia; 
}

int InterfazUsuario::capturarAnnio()
{
    int annio;
    cout << "Ingrese el annio: ";
    cin >> annio;
    return annio;
}

int InterfazUsuario::capturarMes()
{
    int mes;
    cout << "Ingrese el mes: ";
    cin >> mes;
    return mes;
}

bool InterfazUsuario::capturarEnvasado()
{
    bool envasado; 
    cout << " Esta envasado? (0 para No, 1 para Si): ";
    cin >> envasado;
    return envasado; 
}

bool InterfazUsuario::capturarNacionalidad()
{
    bool nacional;
    cout << " Es nacional? (0 para No, 1 para Si): ";
    cin >> nacional;
    return nacional;
}

bool InterfazUsuario::capturarTripa()
{
    bool tripa;
    cout << " Es de tripa? (0 para No, 1 para Si): ";
    cin >> tripa;
    return tripa;
}



Producto* InterfazUsuario::capturarAbarrote()
{
    int catgoria = 2;
    string nombre = capturarNombre(); 
    string codigo = capturarCodigo(); 
    string descripcion = capturarDescripcion(); 
    string empresa = capturarEmpresa(); 
    int existencia = capturarExistencia();
    double precio = capturarPrecio(); 
    int limite = capturarLimite(); 
    bool nacionalidad = capturarNacionalidad() ; 
    double peso = capturarPeso() ;  
    Producto* concreto = new ConcreteProducto(codigo,nombre, descripcion, catgoria, precio, existencia,limite);
    int dia = capturarDia();
    int anio = capturarAnnio();
    int mes = capturarMes();
    Fecha* f11 = new Fecha(dia, mes, anio);
    Perecedero* p1 = new Perecedero(f11);
    ProdPerecedero* abarrote = new Abarrote(concreto, empresa, peso , nacionalidad,p1);
    return abarrote; 
}

Producto* InterfazUsuario::capturarConserva()
{
    string codigo = capturarCodigo();
    string nombre = capturarNombre(); 
    string descripcion = capturarDescripcion();
    int catgoria = 1;
    int precio = capturarPrecio();
    int limite = capturarLimite();
    int existencia = capturarExistencia() ;
    bool envasado = capturarEnvasado(); 
    Producto* conserva = new Conserva(codigo,nombre,descripcion,catgoria,precio,existencia,limite,envasado);
    return conserva; 

}

Producto* InterfazUsuario::capturarEmbutido()
{
    string codigo = capturarCodigo(); 
    string nombre = capturarNombre();
    string descripcion = capturarDescripcion();
    int catgoria = 3;
    string marca = capturarMarca();
    double precio = capturarPrecio();
    int cantidad = capturarLimite();
    int existencia = capturarExistencia();
    bool nacionalidad = capturarNacionalidad();
    bool tripa = capturarTripa(); 
    double peso = capturarPeso();
    string animal = capturarAnimal(); 
    string parteAnimal = capturarParteAnimal(); 
    Producto* concreto = new ConcreteProducto(codigo, nombre, descripcion, catgoria, precio, existencia, cantidad);
    int dia = capturarDia();
    int anio = capturarAnnio();
    int mes = capturarMes();
    Fecha* f11 = new Fecha(dia, mes, anio);
    Perecedero* p1 = new Perecedero(f11);
    ProdPerecedero* carne = new Carne(concreto, animal, parteAnimal,peso,nacionalidad,p1); 
    Producto* embutido = new Embutido(carne, marca, tripa);
    return embutido;
}





