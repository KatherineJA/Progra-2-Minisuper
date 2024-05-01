#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class Nodo {
private:
    T* info;
    Nodo<T>* siguiente;

public:
    Nodo();
    Nodo(T* info, Nodo<T>* siguiente = nullptr);
    ~Nodo();

    // Setters
    void setInfo(T* info);
    void setSiguiente(Nodo<T>* siguiente);

    // Getters
    T* getInfo();
    Nodo<T>* getSiguiente();

   
    string toString() const;
};

template <class T>
Nodo<T>::Nodo() : info(nullptr), siguiente(nullptr) {}

template <class T>
Nodo<T>::Nodo(T* info, Nodo<T>* siguiente)
    : info(info), siguiente(siguiente) {}

template <class T>
Nodo<T>::~Nodo() {
    delete info; // Destruccion  del objeto info
}

template <class T>
void Nodo<T>::setInfo(T* info) {
    this->info = info;
}

template <class T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

template<class T>
inline T* Nodo<T>::getInfo()
{
    return info;
}

template<class T>
inline Nodo<T>* Nodo<T>::getSiguiente()
{
    return siguiente;
}


template <class T>
string Nodo<T>::toString() const {
    if (info != nullptr) {
        return info->toString(); // Suponiendo que T tiene un metodo toString
    }
    else {
        return "Nodo vacío";
    }
}
