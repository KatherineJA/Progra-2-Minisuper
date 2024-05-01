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
		delete listaProductos; // Libera la lista anterior
		listaProductos = lista; // Asigna la nueva lista
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
           cout << "No se encontró ningún producto con el nombre especificado." << endl;
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
        cout << "Existencia actualizada. Nueva cantidad para el producto con código "
            << codigo << ": " << nuevaExistencia << endl;
    }
    else {
        cout << "No se encontró ningún producto con el código " << codigo << "." << endl; 
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
            cout << "No se encontró ningún producto con el nombre especificado." << endl;
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

        // Verificar que el producto y su código no son nullptr
        if (producto == nullptr) {
            cerr << "Error: Nodo contiene producto nulo." << endl; 
            actual = actual->getSiguiente();  
            continue; // Saltar al siguiente nodo
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

        // Verificar que el producto y su código no son nullptr
        if (producto == nullptr) {
            cerr << "Error: Nodo contiene producto nulo." << endl;
            actual = actual->getSiguiente();
            continue; // Saltar al siguiente nodo
        }



        if (producto->getCategoria() == categoria) {
            return producto; // Producto encontrado
        }

        actual = actual->getSiguiente(); // Avanzar al siguiente nodo
    }

    std::cout << "No hay productos de categoria:  " << categoria << " intente mas tarde. para quejas a soporte tecnico con Khaterine Jara 88349034" << std::endl;
    return nullptr; // Producto no encontrado 
}

Lista<Producto>* Almacen::seleccionarProductosPorCodigo() {
    Lista<Producto>* listaComprados = new Lista<Producto>();

   
    std::string codigo;
    int cantidad;

    while (true) {
        std::cout << "Ingrese el código del producto que desea comprar (o ingrese 0 para terminar):" << std::endl;
        std::cin >> codigo;

        // Verificar si se ha ingresado el código 0 para terminar
        if (codigo == "0") {
            if (listaComprados->listaVacia()) {
                std::cout << "No se han seleccionado productos." << std::endl;
                delete listaComprados; // Liberar memoria
                return nullptr;
            }
            else {
                std::cout << "Selección de productos finalizada." << std::endl;
                return listaComprados;
            }
        }

        // Buscar el producto por código
        Producto* producto = buscarProductoCodigo(codigo);

        // Verificar que el producto exista
        if (producto == nullptr) {
            std::cout << "Producto con código " << codigo << " no encontrado en el almacén." << std::endl;
            continue;
        }

        // Verificar la existencia y el límite
        int limite = producto->getLimite();
        int existencia = producto->getExistencia();
        int disponible = (existencia - limite);

        // Si la existencia es menor o igual al límite, no se puede seleccionar
        if (existencia <= limite) {
            std::cout << "Producto Agotado, vuelva después." << std::endl;
            continue;
        }

        std::cout << "Ingrese la cantidad de productos que desea comprar para el código " << codigo << ":" << std::endl;
        std::cin >> cantidad;

        // Si la cantidad solicitada excede la existencia disponible
        if (cantidad > existencia) {
            std::cout << "La cantidad solicitada (" << cantidad
                << ") excede la existencia disponible (" << existencia << "). Cantidad de productos disponibles:" << disponible
                << std::endl;
            continue;
        }

        // Si la cantidad solicitada es mayor que la diferencia entre la existencia y el límite
        if ((existencia - cantidad) < limite) {
            std::cout << "La cantidad solicitada (" << cantidad
                << ") hará que la existencia caiga por debajo del límite permitido. "
                << "Cantidad de productos disponibles:" << disponible << std::endl;
            continue;
        }

        // Reducir la existencia del producto en el almacén por la cantidad solicitada
        producto->setExistencia(existencia - cantidad);

        // Agregar el producto a la lista de productos comprados
        listaComprados->insertarFinal(producto);
        cout << "Aprete cualquier boton para continuar" << endl;
    }
}



string Almacen::toString()
{
    std::stringstream s;

    if (listaProductos == nullptr) { 
        s << "El almacén no esta inicializado." << std::endl;
        return s.str(); 
    }

    if (ListaProductoVacia()) { // Verificar si la lista está vacía
        s << "El almacen está vacío." << std::endl;
        return s.str(); // Devolver mensaje de error
    }

    Nodo<Producto>* actual = listaProductos->getPrimero(); // Obtener el primer nodo

    // Recorrer todos los productos en la lista
   
    s << "Lista de productos en el almacen:" << std::endl;

    while (actual != nullptr) { // Mientras haya nodos
        Producto* producto = actual->getInfo(); // Obtener la información del producto

        if (producto != nullptr) { // Verificar que el producto no sea nulo
            s << "----------------------------------------------------------" << endl;
            s << producto->toString() << std::endl; // Agregar la representación del producto
            s << "----------------------------------------------------------" << endl; 
        }
        else {
            s << "Producto nulo encontrado en la lista." << std::endl; // Manejar caso de producto nulo
        }

        actual = actual->getSiguiente(); // Avanzar al siguiente nodo
    }

    return s.str(); // Devolver la cadena generada
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






