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
		delete listaProductos; // Liberar la lista anterior
		listaProductos = lista; // Asignar la nueva lista
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

void Almacen::actualizarProductoPorCodigo(string codigo, double nuevoPrecioCosto, int nuevaExistencia)
{
    if (ListaProductoVacia()) {
        cout << "El almacen esta vacio. No se puede actualizar ningun producto." << endl;
        return;
    }

    // Recorrer la lista de productos para buscar el producto por su c�digo
    Nodo<Producto>* actual = listaProductos->getPrimero();
    while (actual != nullptr) {
        Producto* producto = actual->getInfo();
        
        if (producto->getCodigo() == codigo) {
            producto->setPrecio(nuevoPrecioCosto);
            producto->setExistencia(nuevaExistencia);
            cout << "Producto actualizado correctamente." << endl;
            
        }
        else {
            cout << "No se encontro ningun producto con el codigo especificado." << endl;
        }
        actual = actual->getSiguiente();
    }

}

void Almacen::actualizarProductoPorNombre(string nombre, double nuevoPrecioCosto, int nuevaExistencia) {
    
    if (ListaProductoVacia()) {
        cout << "El almacen esta vacio. No se puede actualizar ningun producto." << endl;
        return;
    }

    Nodo<Producto>* actual = listaProductos->getPrimero();
    while (actual != nullptr) {
        Producto* producto = actual->getInfo();
        
        if (producto->getNombreComercial() == nombre) {
            producto->setPrecio(nuevoPrecioCosto);
            producto->setExistencia(nuevaExistencia);
            cout << "Producto actualizado correctamente." <<endl;
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

void Almacen::eliminarPorCodigo(string codigo)
{
    Nodo<Producto>* actual = listaProductos->getPrimero(); 
    Nodo<Producto>* anterior = nullptr; 

    
    while (actual != nullptr) {
        if (actual->getInfo()->getCodigo() == codigo) {
            // Si encontramos el producto, lo eliminamos
            if (anterior == nullptr) {
                // Si el producto a eliminar es el primero en la lista
                listaProductos->setPrimero(actual->getSiguiente()); 
            }
            else {
                // Si el producto a eliminar no es el primero
                anterior->setSiguiente(actual->getSiguiente());
            }

            // Limpiar el nodo que se elimina evita fugas de memoria
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

    // Recorrer la lista buscando el producto por su código
    while (actual != nullptr) {
        if (actual->getInfo()->getNombreComercial() == nombreCM) { 
            // Si encontramos el producto, lo eliminamos
            if (anterior == nullptr) {
                // Si el producto a eliminar es el primero en la lista
                listaProductos->setPrimero(actual->getSiguiente()); 
            }
            else {
                // Si el producto a eliminar no es el primero
                anterior->setSiguiente(actual->getSiguiente()); 
            }

            // Limpiar el nodo que se elimina para evitar fugas de memoria
            delete actual;

            // Imprimir mensaje de éxito
            cout << "El producto fue eliminado correctamente." << endl;
            return; // Salir del método
        }

        anterior = actual;
        actual = actual->getSiguiente();
    }

    // Si llegamos aquí, el producto no se encontró en la lista
    cout << "Producto de nombre ' " << nombreCM << " ' no encontrado." << endl;
}

Producto* Almacen::buscarProductoCodigo(string codigo)
{  // Verificar que el puntero de listaProductos no es nullptr
    if (listaProductos == nullptr) { 
        std::cerr << "Error: La lista de productos no está inicializada ." << std::endl;
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
            return producto; // Producto encontrado
        }

        actual = actual->getSiguiente(); // Avanzar al siguiente nodo
    }

    cout << "Producto con codigo " << codigo << " no encontrado." << endl; 
    return nullptr; // Producto no encontrado 

}

Producto* Almacen::buscarProductoCategoria(int categoria)
{
    // Verificar que el puntero de listaProductos no es nullptr
    if (listaProductos == nullptr) {
        std::cerr << "Error: La lista de productos no esta inicializada." << endl;
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

Lista<Producto>* Almacen::seleccionarProductosPorCodigo(string codigo, int cantidad)
{
    if (ListaProductoVacia()) {
        std::cout << "El almacén esta vacio. No se puede seleccionar productos." << std::endl;
        return nullptr;
    }

    // Buscar el producto por código
    Producto* producto = buscarProductoCodigo(codigo);

    // Verificar que el producto exista
    if (producto == nullptr) {
        std::cout << "Producto con codigo " << codigo << " no encontrado en el almacen." << std::endl;
        return nullptr;
    }

    // Verificar la existencia suficiente
    int existencia = (producto->getExistencia());
    if (cantidad > existencia) {
        std::cout << "Cantidad solicitada excede la existencia disponible." << std::endl;
        return nullptr;
    }

    // Crear la lista para los productos comprados
    Lista<Producto>* listaComprados = new Lista<Producto>();

    // Establecer la existencia del producto a la cantidad solicitada
    producto->setExistencia(cantidad);

    listaComprados->insertarFinal(producto);

    // Reducir la existencia en el almacén
    int nuevaExistencia = existencia - cantidad;
    producto->setExistencia(nuevaExistencia);

    return listaComprados;  
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






