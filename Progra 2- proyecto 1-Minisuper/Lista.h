#pragma once
#include "Nodo.h"
#include <sstream>
#include <string>

template <class T>
class Lista {
private:
    Nodo<T>* primero;
    Nodo<T>* actual;
    Nodo<T>* ultimo;

public:
    Lista();
    ~Lista();

    // Setters
    void setPrimero(Nodo<T>* primero);
    void setActual(Nodo<T>* actual);
    void setUltimo(Nodo<T>* ultimo);

    // Getters
    Nodo<T>* getPrimero();
    Nodo<T>* getActual();
    Nodo<T>* getUltimo();

    // Operaciones con la lista
    void insertarFinal(T* objeto);
    bool eliminarFinal();
    bool eliminarPorID(const std::string& id);
    T* obtenerObjetoPorID(const std::string& id);
    bool existeObjetoPorID(const std::string& id);
    bool listaVacia();

    // Representación como cadena
    std::string toString();
};

// Constructor por defecto
template <class T>
Lista<T>::Lista() : primero(nullptr), actual(nullptr), ultimo(nullptr) {}

// Destructor
template <class T>
Lista<T>::~Lista() {
    while (primero != nullptr) {
        Nodo<T>* temp = primero;
        primero = primero->getSiguiente();
        delete temp;
    }
}

// Setters
template <class T>
void Lista<T>::setPrimero(Nodo<T>* primero) {
    this->primero = primero;
}

template <class T>
void Lista<T>::setActual(Nodo<T>* actual) {
    this->actual = actual;
}

template <class T>
void Lista<T>::setUltimo(Nodo<T>* ultimo) {
    this->ultimo = ultimo;
}

// Getters
template <class T>
Nodo<T>* Lista<T>::getPrimero() {
    return primero;
}

template <class T>
Nodo<T>* Lista<T>::getActual() {
    return actual;
}

template <class T>
Nodo<T>* Lista<T>::getUltimo() {
    return ultimo;
}

// Operaciones con la lista
template <class T>
void Lista<T>::insertarFinal(T* objeto) {
    if (objeto == nullptr) {
        throw std::runtime_error("Intento de insertar un objeto nulo.");
    }

    Nodo<T>* nuevoNodo = new Nodo<T>(objeto);
    if (primero == nullptr) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    }
    else {
        ultimo->setSiguiente(nuevoNodo);
        ultimo = nuevoNodo;
    }
}

template <class T>
bool Lista<T>::eliminarFinal() {
    if (primero == nullptr) {  // Lista vacía
        return false;
    }

    if (primero == ultimo) { // Solo hay un nodo
        delete primero;
        primero = ultimo = nullptr;
        return true;
    }

    Nodo<T>* actual = primero;
    while (actual->getSiguiente() != ultimo) {
        actual = actual->getSiguiente();
    }

    delete ultimo;
    ultimo = actual;
    actual->setSiguiente(nullptr);
    return true;
}

template <class T>
bool Lista<T>::eliminarPorID(const std::string& id) {
    if (primero == nullptr) {
        return false;
    }

    if (primero->getInfo()->getId() == id) {
        Nodo<T>* temp = primero;
        primero = primero->getSiguiente();
        delete temp;
        if (primero == nullptr) {
            ultimo = nullptr;
        }
        return true;
    }

    Nodo<T>* actual = primero;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr && actual->getInfo()->getId() != id) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) {
        return false;
    }

    if (actual == ultimo) {
        ultimo = anterior;
    }

    anterior->setSiguiente(actual->getSiguiente());
    delete actual;
    return true;
}

template <class T>
T* Lista<T>::obtenerObjetoPorID(const std::string& id) {
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        T* objeto = actual->getInfo();
        if (objeto->getId() == id) {
            return objeto;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

template <class T>
bool Lista<T>::existeObjetoPorID(const std::string& id) {
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        if (actual->getInfo()->getId() == id) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

template <class T>
bool Lista<T>::listaVacia() {
    return primero == nullptr;
}

template <class T>
std::string Lista<T>::toString() {
    std::stringstream s;
    Nodo<T>* actual = primero;
    while (actual != nullptr) {
        s << actual->getInfo()->toString() << std::endl;
        actual = actual->getSiguiente();
    }
    return s.str();
}
