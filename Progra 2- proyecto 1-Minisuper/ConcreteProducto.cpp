#include "ConcreteProducto.h"
#include "ConcreteProducto.h"

ConcreteProducto::ConcreteProducto()
{
    this->codigo = "vacio"; 
    this->nombreComercial = "VACIO"; 
    this->descripcion = "VACIO";
    this->categoria = 0; 
    this->precioCosto = 0.0;
    this->existencia = 0; 
    this->limite = 0; 
}

ConcreteProducto::ConcreteProducto(ConcreteProducto* otro)
{
    this->codigo = otro->codigo;
    this->nombreComercial = otro->nombreComercial;
    this->descripcion = otro->descripcion;
    this->categoria =otro->categoria;
    this->precioCosto = otro->precioCosto;
    this->existencia = otro->existencia;
    this->limite = otro->limite;

}

ConcreteProducto::ConcreteProducto(string codigo, string nombreComercial, string descripcion, int categoria, double precioCosto, int existencia, int limite)
{
    this->codigo = codigo;
    this->nombreComercial = nombreComercial;
    this->descripcion = descripcion;
    this->categoria = categoria;
    this->precioCosto = precioCosto;
    this->existencia = existencia;
    this->limite = limite;

}

string ConcreteProducto::getCodigo()
{
    return codigo;
}

string ConcreteProducto::getNombreComercial()
{
    return nombreComercial;
}

string ConcreteProducto::getDescripcion()
{
    return descripcion;
}

int ConcreteProducto::getCategoria()
{
    return categoria;
}

double ConcreteProducto::getPrecioCosto()
{
    return precioCosto;
}

int ConcreteProducto::getExistencia()
{
    return existencia;
}

int ConcreteProducto::getLimite()
{
    return limite;
}

void ConcreteProducto::setCodigo(string codigo)
{
    this->codigo = codigo;
}

void ConcreteProducto::setNombreComercial(string nombre)
{
    this->nombreComercial = nombre;
}

void ConcreteProducto::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void ConcreteProducto::setCategoria(int categoria)
{
    this->categoria = categoria;
}

void ConcreteProducto::setPrecio(double precio)
{
    this->precioCosto = precio;
}

void ConcreteProducto::setExistencia(int existencia)
{
    this->existencia = existencia;
}

void ConcreteProducto::setLimite(int limite)
{
    this->limite = limite;
}



double ConcreteProducto::calculaPorcGanancia()
{
    double ganancia = 0.0; 
    ganancia = precioCosto * Categoria::porceGanancia(categoria); 
    return ganancia; 
}

string ConcreteProducto::toString()
{

    string result = "Codigo: " + getCodigo() + "\n";
    result += "Nombre Comercial: " + getNombreComercial() + "\n";
    result += "Descripcion: " + getDescripcion() + "\n";
    result += "Categoria: " + to_string(getCategoria()); +"\n";
    result += "\nPrecio Costo: " + to_string(getPrecioCosto()) + "\n";
    result += "Existencia: " + to_string(getExistencia()) + "\n";
    result += "Limite: " + to_string(getLimite()) + "\n";
    return result;
}