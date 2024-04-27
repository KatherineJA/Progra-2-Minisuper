//#include "Controladora.h"
//
//int main() {
//	Controladora contro;
//	contro.ejecutar();
//
//
//
//
//	return 0;
//}
//#include <iostream>
//#include "ConcreteProducto.h"
//#include "Perecedero.h"
//#include "Fecha.h"
//#include "Abarrote.h"
//#include "Carne.h"
//#include "Lista.h"
//
//int main() {
//
//    //Fechas
//    Fecha* f1 = new Fecha(new int(1), new int(10), new int(2024)); 
//
//    Perecedero* p1 = new Perecedero(f1);
//        
//
//    Lista<Producto>* C1 = new Lista<Producto>();
//    Producto *concreto = new ConcreteProducto(new string("001"), new string("Cereal"), new string("Cereal de maiz"), new string("Alimentos"), new double(5400.0), new int(2), new int(2)); 
//    // Crear un producto base
//    ProdPerecedero productoBase(concreto, new bool(true),new double(2.2),p1);
//    
//    // Mostrar la información del producto sin decorar
//    cout << "Informacion del producto base:" << endl;
//    cout << productoBase.toString() << endl;
//
//    // Agregar características de perecedero y abarrote al producto base
//    bool nacionalidadAbarrote = true;
//    double pesoAbarrote = 0.5; //Nota:Por el amor a Dios no lo descomente
//    string empresa = "ABC";
//
//    Producto* a= new Abarrote(&productoBase, &nacionalidadAbarrote, &pesoAbarrote, &empresa);
//
//    C1->insertarFinal(a);
//    // Mostrar la información del producto con decoración de abarrote
//   /* cout << "\nInformacion del producto abarrote:" << endl;
//    cout << abarrote.toString() << endl;*/
//   cout<< C1->toString();
//    // Crear un nuevo producto base
//    ConcreteProducto productoBase2(new string("002"), new string("Pollo"), new string("Pollo fresco"), new string("Alimentos"), new double(5.0), new int(20), new int(50));
//
//    // Mostrar la información del segundo producto base sin decorar
//    cout << "\nInformacion del segundo producto base:" << endl;
//    cout << productoBase2.toString() << endl;
//
//    // Agregar características de carne al segundo producto base
//    bool nacionalidadCarne = false;
//    double pesoCarne = 1.0;
//    string animal = "Res";
//    string parteAnimal = "Costilla";
//    bool tripa = false; // Cambia este valor según sea necesario
//    string marca = "Marca XYZ";
//
//    Carne carne(&productoBase2, &nacionalidadCarne, &pesoCarne, &animal, &parteAnimal, &tripa, &marca);
//
//    // Mostrar la información del producto con decoración de carne
//    cout << "\nInformacion del producto carne:" << endl;
//    cout << carne.toString() << endl;
////   
//    return 0;
//}
#include <iostream>
#include "Cliente.h"
#include "Producto.h"
#include "Carrito.h"
#include "Venta.h"
#include "ConcreteProducto.h"
#include "Factura.h"
#include "Abarrote.h"
#include "Carne.h"
#include "Controladora.h"

//int main() {
////    // Crear un cliente
////    Cliente* cliente = new Cliente((new string("Ivan Alonso")), new string("1234567890"));
////    Fecha* f11 = new Fecha(new int(1), new int(10), new int(2024));
////    Perecedero* p1 = new Perecedero(f11);
//string* nombre = new string(); 
//string* cedula = new string();
//
//cout << "Nombre:";
//cin >> *nombre;
//cout << "Cedula: ";
//cin >> *cedula;
//Cliente* cliente = new Cliente(nombre,cedula);
//int* dia= new int();
//int* anio = new int();
//int* mes = new int();
//    cout << "Ingrese el día de caducidad del perecedero: ";
//    cin >> *dia;
//    cout << "Ingrese el mes de caducidad del perecedero: ";
//    cin >> *mes;
//    cout << "Ingrese el año de caducidad del perecedero: ";
//    cin >> *anio; 
//    Fecha* f11 = new Fecha(dia, mes, anio);
//    Perecedero* p1 = new Perecedero(f11);
//
////    Producto* concreto = new ConcreteProducto(new string("001"), new string("Cereal"), new string("Cereal de maiz"), new string("Alimentos"), new double(5400.0), new int(2), new int(2));
////    ProdPerecedero productoBase(concreto, new bool(true), new double(2.2), p1);
////    // Crear algunos productos
////    bool nacionalidadAbarrote = true;
////        double pesoAbarrote = 0.5; //Nota:Por el amor a Dios no lo descomente
////      string empresa = "ABC";
//    string* codigo = new string();
//    string* NombreCM = new string();
//    string* Des = new string();
//    string* catgoria = new string();
//    double* precio = new double();
//    int* cantidad = new int();
//    int* existencia = new int();
//    cout << "Ingrese el código del producto: ";
//    cin >> *codigo;  // Leer entrada para 'codigo'
//
//    cout << "Ingrese el nombre del producto: ";
//    cin.ignore();   // Limpiar el buffer para getline
//    cin >> *NombreCM;// Leer entrada para 'nombreCM '
//
//    cout << "Ingrese la descripción del producto: ";
//    getline(cin, *Des);  // Leer entrada para 'descripcion'
//
//    cout << "Ingrese la categoría del producto: ";
//    cin.ignore();
//    getline(cin, *catgoria);  // Leer entrada para 'categoria'
//
//    cout << "Ingrese el precio del producto: ";
//    cin >> *precio;  // Leer entrada para 'precio'
//
//    cout << "Ingrese la cantidad del producto: ";
//    cin >> *cantidad;  // Leer entrada para 'cantidad'
//
//    cout << "Ingrese la existencia del producto: ";
//    cin >> *existencia;  // Leer entrada para 'existencia'
//
//    Producto* concreto = new ConcreteProducto(codigo, NombreCM, Des, catgoria,precio,existencia, cantidad);
//    bool n = true;
//    double* N2 = new double();
//  
//    cout << "Double:";
//    cin >> *N2;
//    ProdPerecedero productoBase(concreto,&n, N2, p1);
//
//    bool nacionalidadAbarrote = true;
//            double pesoAbarrote = 0.5; //Nota:Por el amor a Dios no lo descomente
//          string empresa = "ABC";
//
////      Producto* producto1= new Abarrote(&productoBase, &nacionalidadAbarrote, &pesoAbarrote, &empresa);
////     /* Producto* producto2 = new Abarrote(&productoBase,new bool (false),new double (23.3),new string("Marimar"));*/
//          Producto* producto1 = new Abarrote(&productoBase, &nacionalidadAbarrote, &pesoAbarrote, &empresa);
////    //Crear un carrito y agregar productos
////    
////    /*carrito->agregarProducto(producto1);*/
//    Almacen* alma = new Almacen(); 
//    alma->agregarProductoAlmacen(producto1); 
//    cout<< alma->toString() << endl;/*
////    alma->seleccionarProductosPorCodigo(new string("001"), new int(1));*/
//    string* codigoProdu = new string();
//    int* cantiadproducts = new int();
//    cout << "Codigo P:";
//    cin >> *codigoProdu;
//    cout << "Cantidad P";
//    cin >> *cantiadproducts;
//
//    Carrito* carrito = new Carrito(cliente, alma->seleccionarProductosPorCodigo(codigoProdu, cantiadproducts)); 
////    //carrito->agregarProducto(producto2);
////
////    // Crear una venta con el carrito y la fecha actual
//    Fecha* f1 = new Fecha(new int(1), new int(10), new int(2024));
//    Fecha* f2 = new Fecha(new int(6), new int(8), new int(2024));
//    Venta* venta = new Venta(carrito,f2);
//
//    // Crear una factura y agregar la venta
//    Factura* factura = new Factura(new Lista<Venta>());
//    factura->agregarVenta(venta);
//
//    // Mostrar la factura
//    cout << factura->toString() << endl;
//
//    // Liberar la memoria
//    delete cliente;
//    delete alma;
//    delete carrito;
//    delete factura;
//    delete venta;
//
//    return 0;
//}

int main() {
	Controladora c1; 
	c1.ejecutar(); 



	return 0; 
}

    //int main() {
    //    // Crear un cliente
    //    string nombreCliente, telefonoCliente;  
    //    cout << "Ingrese el nombre del cliente: ";
    //    getline(cin, nombreCliente); 
    //    cout << "Ingrese el cedula del cliente: ";
    //    getline(cin, telefonoCliente);

    //    Cliente* cliente = new Cliente(&nombreCliente, &telefonoCliente);

    //    // Crear un producto perecedero
    //    int dia, mes, año;
    //    cout << "Ingrese el día de caducidad del perecedero: ";
    //    cin >> dia;
    //    cout << "Ingrese el mes de caducidad del perecedero: ";
    //    cin >> mes;
    //    cout << "Ingrese el año de caducidad del perecedero: ";
    //    cin >> año;

    //    Fecha* fechaCaducidad = new Fecha(&dia, &mes, &año);
    //    Perecedero* perecedero = new Perecedero(fechaCaducidad);

    //    // Crear un producto base para los perecederos
    //    string codigo, nombre, descripcion, categoria;
    //    double precio;
    //    int cantidad;
    //    int exist;
    //    cout << "Ingrese el código del producto: ";
    //    cin >> codigo;
    //    cout << "Ingrese el nombre del producto: ";
    //    cin.ignore();  // Para limpiar el buffer
    //    getline(cin, nombre);
    //    cout << "Ingrese la descripción del producto: ";
    //    getline(cin, descripcion);
    //    cout << "Ingrese la categoría del producto: ";
    //    getline(cin, categoria);
    //    cout << "Ingrese el precio del producto: ";
    //    cin >> precio;
    //    cout << "Ingrese la cantidad de unidades: ";
    //    cin >> cantidad;
    //    cout << "Ingrese existencia: " << endl;
    //     cin >> exist;
    //    Producto* concreto = new ConcreteProducto(&codigo, &nombre, &descripcion, &categoria, &precio, &cantidad, &exist);
    //    bool H;
    //    double P;
    //    cout << "Ingrese 1 o 0:" << endl;
    //    cin >> H;
    //    cout << "Ingrese un double: " << endl;
    //    cin >> P;
    //    ProdPerecedero* productoBase = new ProdPerecedero(concreto, &H,&P, perecedero);

    //    // Crear un producto de tipo abarrote
    //    bool nacionalidadAbarrote;
    //    double pesoAbarrote;
    //    string empresa;
    //    cout << "¿El abarrote es nacional? (1 para sí, 0 para no): ";
    //    cin >> nacionalidadAbarrote;
    //    cout << "Ingrese el peso del abarrote: ";
    //    cin >> pesoAbarrote;
    //    cout << "Ingrese el nombre de la empresa del abarrote: ";
    //    cin.ignore();  // Limpia el buffer
    //    getline(cin, empresa);

    //    Producto* productoAbarrote = new Abarrote(productoBase, &nacionalidadAbarrote, &pesoAbarrote, &empresa);

    //    // Crear un almacén y agregar productos
    //    Almacen* almacen = new Almacen();
    //    almacen->agregarProductoAlmacen(productoAbarrote);
    //    cout << almacen->toString() << endl;
    //    // Crear un carrito y agregar productos del almacén
    //    cout << "Ingrese la cantidad de productos que desea agregar al carrito: ";
    //    int cantidadPro;
    //    string codiPro;
    //    cin >> cantidadPro;
    //    cout << "Ingrese codigo: " << endl;
    //    cin>> codiPro;

    //    
    //    
    //    Carrito* carrito = new Carrito(cliente,almacen->seleccionarProductosPorCodigo(&codiPro, &cantidadPro));

    //  /*  Producto* producto = almacen->seleccionarProductosPorCodigo(codigoPro,cantidadPro);
    //    if (producto != nullptr) {
    //        for (int i = 0; i < cantidadPro; i++) {
    //            carrito->agregarProducto(producto);
    //        }
    //    }
    //    else {
    //        cout << "Producto no encontrado en el almacén." << endl;
    //    }*/

    //    // Crear una venta con el carrito y la fecha de venta
    //    cout << "Ingrese el día de la fecha de venta: ";
    //    cin >> dia;
    //    cout << "Ingrese el mes de la fecha de venta: ";
    //    cin >> mes;
    //    cout << "Ingrese el año de la fecha de venta: ";
    //    cin >> año;

    //    Fecha* fechaVenta = new Fecha(&dia, &mes, &año);

    //    Venta* venta = new Venta(carrito, fechaVenta);

    //    // Crear una factura y agregar la venta
    //    Factura* factura = new Factura();
    //    factura->agregarVenta(venta);

    //    // Mostrar la factura
    //    cout << "Factura generada:" << endl;
    //    cout << factura->toString() << endl;

    //    // Liberar memoria
    //    delete cliente;
    //    delete almacen;
    //    delete carrito;
    //    delete factura;
    //    delete venta;
    //    delete fechaCaducidad;

    //    return 0;
    //}
