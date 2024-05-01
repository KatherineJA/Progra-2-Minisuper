#include "Almacen.h"

Almacen::Almacen()
{
	this->listaProductos = new Lista<Producto>();
}

Almacen::Almacen(Lista<Producto>* lista)
{
	this->listaProductos = lista;
}

Almacen::~Almacen()
{

}

void Almacen::setListaProductos(Lista<Producto>* lista)
{
	if (listaProductos != lista) {
		delete listaProductos; 
		listaProductos = lista;
	}
}

Lista<Producto>* Almacen::getListaProductos()
{
	return listaProductos;
}

void Almacen::agregarProductoAlmacen(Producto* producto)
{
    if (listaProductos != nullptr) {
        listaProductos->insertarFinal(producto);
    }
   
}

void Almacen::actualizarProductoPrecioPorCodigo(string codigo, double nuevoPrecioCosto)
{
    if (ListaProductoVacia()) {
        cout << "El almacen esta vacio. No se puede actualizar ningun producto." << endl;
        return;
    }

    // Recorre la lista de productos y busca el producto por su codigo
    Nodo<Producto>* actual = listaProductos->getPrimero();
    while (actual != nullptr) {
        Producto* producto = actual->getInfo();
        
        if (producto->getCodigo() == codigo) {
            producto->setPrecio(nuevoPrecioCosto);
            cout << "Precio del producto actualizado correctamente." << endl;
            
        }
        else {
            cout << "No se encontro ningun producto con el codigo especificado." << endl;
        }
        actual = actual->getSiguiente();
    }

}

void Almacen::actualizarProductoPrecioPorNombre(string nombre, double nuevoPrecioCosto) {
    
    if (ListaProductoVacia()) {
        cout << "El almacen esta vacio. No se puede actualizar ningun producto." << endl;
        return;
    }

    Nodo<Producto>* actual = listaProductos->getPrimero();
    while (actual != nullptr) {
        Producto* producto = actual->getInfo();
        
        if (producto->getNombreComercial() == nombre) {
            producto->setPrecio(nuevoPrecioCosto);
            cout << "Precio del producto actualizado correctamente." <<endl;
            return;
        }
        else {
           cout << "No se encontro ningun producto con el nombre especificado." << endl;
        }
        actual = actual->getSiguiente();
    }

}


bool Almacen::ListaProductoVacia()
{
	return listaProductos ? listaProductos->listaVacia() : true;
}

void Almacen::actualizarExistenciaPorCodigo(string codigo, int cantidad)
{
    Producto* producto = buscarProductoCodigo(codigo); 

    if (producto != nullptr) { 
        int nuevaExistencia = producto->getExistencia() + cantidad; 
        producto->setExistencia(nuevaExistencia);
        cout << "Existencia actualizada. Nueva cantidad para el producto con codigo "
            << codigo << ": " << nuevaExistencia << endl;
    }
    else {
        cout << "No se encontro ningun producto con el codigo " << codigo << "." << endl; 
    } 
}

void Almacen::actulizarExistenciaPorNombre(string nombre, int existencia)
{
    if (ListaProductoVacia()) { 
        cout << "El almacen esta vacio. No se puede actualizar ningun producto." << endl;
        return;
    }

    Nodo<Producto>* actual = listaProductos->getPrimero(); 
    while (actual != nullptr) { 
        Producto* producto = actual->getInfo(); 

        if (producto->getNombreComercial() == nombre) {
            producto->setExistencia(existencia);
            cout << "Existencia del producto actualizado correctamente." << endl;
            return;
        }
        else {
            cout << "No se encontro ningun producto con el nombre especificado." << endl;
        }
        actual = actual->getSiguiente();
    }

}

void Almacen::eliminarPorCodigo(string codigo)
{
    Nodo<Producto>* actual = listaProductos->getPrimero(); 
    Nodo<Producto>* anterior = nullptr; 

    
    while (actual != nullptr) {
        if (actual->getInfo()->getCodigo() == codigo) {
            // Si encontramos el producto, lo eliminamos
            if (anterior == nullptr) {
                
                listaProductos->setPrimero(actual->getSiguiente()); 
            }
            else {
                
                anterior->setSiguiente(actual->getSiguiente());
            }

            
            delete actual;

            
            cout << "El producto fue eliminado correctamente." << endl;
            return; 
        }

        anterior = actual;
        actual = actual->getSiguiente();
    }

    
    cout << "Producto con codigo " << codigo << " no encontrado." << endl;
}

void Almacen::eliminarPorNombreCM(string nombreCM)
{
    Nodo<Producto>* actual = listaProductos->getPrimero(); 
    Nodo<Producto>* anterior = nullptr; 

    // Recorre la lista buscando el producto por su código
    while (actual != nullptr) {
        if (actual->getInfo()->getNombreComercial() == nombreCM) { 
            
            if (anterior == nullptr) {
                
                listaProductos->setPrimero(actual->getSiguiente()); 
            }
            else {
               
                anterior->setSiguiente(actual->getSiguiente()); 
            }

            
            delete actual;

            
            cout << "El producto fue eliminado correctamente." << endl;
            return; 
        }

        anterior = actual;
        actual = actual->getSiguiente();
    }

    
    cout << "Producto de nombre ' " << nombreCM << " ' no encontrado." << endl;
}

bool Almacen::verificarCod(string cod)
{
    
    if (listaProductos == nullptr) {
        cerr << "Error: La lista de productos no esta inicializada." << endl;
        return false;
    }

    Nodo<Producto>* actual = listaProductos->getPrimero(); 

    while (actual != nullptr) {
        Producto* producto = actual->getInfo(); 

        if (producto != nullptr && producto->getCodigo() == cod) { 
            return true; 
        }

        actual = actual->getSiguiente(); 
    }

    
    return false; 
}

Producto* Almacen::buscarProductoCodigo(string codigo)
{  
    if (listaProductos == nullptr) { 
        cerr << "Error: La lista de productos no está inicializada ." << endl;
        return nullptr;
    } 

   

    Nodo<Producto>* actual = listaProductos->getPrimero();  

    while (actual != nullptr) {
        Producto* producto = actual->getInfo();  

        if (producto == nullptr) {
            cerr << "Error: Nodo contiene producto nulo." << endl; 
            actual = actual->getSiguiente();  
            continue; 
        }

        

        if (producto->getCodigo() == codigo) {
            return producto; 
        }

        actual = actual->getSiguiente();
    }

    cout << "Producto con codigo " << codigo << " no encontrado." << endl; 
    return nullptr; 
}

Producto* Almacen::buscarProductoCategoria(int categoria)
{
    // Verificar que el puntero de listaProductos no es nullptr
    if (listaProductos == nullptr) {
        cerr << "Error: La lista de productos no esta inicializada." << endl;
        return nullptr;
    }

    Nodo<Producto>* actual = listaProductos->getPrimero();

    while (actual != nullptr) {
        Producto* producto = actual->getInfo();

       
        if (producto == nullptr) {
            cerr << "Error: Nodo contiene producto nulo." << endl;
            actual = actual->getSiguiente();
            continue; 
        }



        if (producto->getCategoria() == categoria) {
            return producto; 
        }

        actual = actual->getSiguiente(); 
    }

    cout << "No hay productos de categoria:  " << categoria << " intente mas tarde para quejas a soporte tecnico con Katherine Jara 88888888" <<endl;
    return nullptr; 
}

Lista<Producto>* Almacen::seleccionarProductosPorCodigo() {
    Lista<Producto>* listaComprados = new Lista<Producto>();

   
    string codigo;
    int cantidad;

    while (true) {
        cout << "Ingrese el codigo del producto que desea comprar (o ingrese 0 para terminar):" << endl;
        cin >> codigo;

      
        if (codigo == "0") {
            if (listaComprados->listaVacia()) {
                cout << "No se han seleccionado productos." << endl;
                delete listaComprados; 
                return nullptr;
            }
            else {
               cout << "Seleccion de productos finalizada." << endl;
                return listaComprados;
            }
        }

      
        Producto* producto = buscarProductoCodigo(codigo);

       
        if (producto == nullptr) {
            cout << "Producto con codigo " << codigo << " no encontrado en el almacen." << endl;
            continue;
        }

        
        int limite = producto->getLimite();
        int existencia = producto->getExistencia();
        int disponible = (existencia - limite);

        
        if (existencia <= limite) {
            std::cout << "Producto Agotado, vuelva despues." << std::endl;
            continue;
        }

      cout << "Ingrese la cantidad de productos que desea comprar para el codigo " << codigo << ":" << endl;
       cin >> cantidad;

        // Si la cantidad solicitada excede la existencia disponible
        if (cantidad > existencia) {
            cout << "La cantidad solicitada (" << cantidad
                << ") excede la existencia disponible (" << existencia << "). Cantidad de productos disponibles:" << disponible
                << endl;
            continue;
        }

        // Si la cantidad solicitada es mayor que la diferencia entre la existencia y el límite
        if ((existencia - cantidad) < limite) {
            cout << "La cantidad solicitada (" << cantidad
                << ") hará que la existencia caiga por debajo del limite permitido. "
                << "Cantidad de productos disponibles:" << disponible << endl;
            continue;
        }

        // Reducir la existencia del producto en el almacén por la cantidad solicitada
        producto->setExistencia(existencia - cantidad);

        // Agregar el producto 
        listaComprados->insertarFinal(producto);
        cout << "Aprete cualquier boton para continuar" << endl;
    }
}



string Almacen::toString()
{
stringstream s;

    if (listaProductos == nullptr) { 
        s << "El almacén no esta inicializado." << endl;
        return s.str(); 
    }

    if (ListaProductoVacia()) {
        s << "El almacen está vacío." << endl;
        return s.str(); 
    }

    Nodo<Producto>* actual = listaProductos->getPrimero();

    
   
    s << "Lista de productos en el almacen:" << std::endl;

    while (actual != nullptr) { 
        Producto* producto = actual->getInfo(); 

        if (producto != nullptr) { 
            s << "----------------------------------------------------------" << endl;
            s << producto->toString() << std::endl;
            s << "----------------------------------------------------------" << endl; 
        }
        else {
            s << "Producto nulo encontrado en la lista." << std::endl; 
        }

        actual = actual->getSiguiente(); 
    }

    return s.str(); 
}

Lista<Producto>* Almacen::reporteCategorias(int categoria)
{
    if (ListaProductoVacia()) {
        cout << "El almacen esta vacio. No hay productos que mostar." << endl;
        return nullptr;
    }
   

    Nodo<Producto>* actual = listaProductos->getPrimero();
    while (actual != nullptr) {
        Producto* producto = actual->getInfo();
        if (producto != nullptr && producto->getCategoria() == categoria) {
           
               cout <<  producto->toString();
            
        }
        else {
            cout << "No hay productos de esa categoria (" << categoria << ") vuelva mas tarde." << endl;
        }

        actual = actual->getSiguiente();
       
    }

    
}

Lista<Producto>* Almacen::reporteProductosPorDebajoDelMinimo()
{
    if (ListaProductoVacia()) {
        cout << "El almacen esta vacio. No hay productos, vuelva despues del restock" << endl;
        return nullptr;
    }

    Nodo<Producto>* actual = listaProductos->getPrimero();
    while (actual != nullptr) {
        Producto* producto = actual->getInfo();

        if (producto != nullptr && producto->getExistencia() <= 0) {

            cout << producto->toString();

        }
        else {
            cout << "Aun hay stock de todos los productos" << endl;
        }
        actual = actual->getSiguiente();
    }
     
}






