#include "Abarrote.h"
#include <sstream>
Abarrote::Abarrote(Producto* producto, string nombreEmpresa,double peso,bool nacional)
{
    this->ptrProducto = producto; 
    this->empresaNombre = nombreEmpresa; 
    this->peso = peso; 
    this->nacional = nacional; 

}



string Abarrote::getEmpresaNombre() {
    return empresaNombre;
}

void Abarrote::setEmpresaNombre(string empresa) {
    empresaNombre = empresa;
}

string Abarrote::toString()
{
    string result = ptrProducto->toString(); 

    result += "Nacional: "; 
    if (esNacional()) { 
        result += "Si\n"; 
    }
    else {
        result += "No\n"; 
    }
    result += "Peso: " + to_string(getPeso()) + "\n"; 
    result += "Empresa: " + (empresaNombre)+"\n";

    return result; 
}



bool Abarrote::getNacional()
{
    return nacional;
}

double Abarrote::getPeso()
{
    return peso;
}

void Abarrote::setNacional(bool nacional)
{
    this->nacional = nacional; 
}

void Abarrote::setPeso(double peso)
{
   this->peso = peso; 
}

string Abarrote::getCodigo()
{
    return codigo;
}

string Abarrote::getNombreComercial()
{
    return nombreComercial;
}

string Abarrote::getDescripcion()
{
    return descripcion;
}

int Abarrote::getCategoria()
{
    return categoria;
}

double Abarrote::getPrecioCosto()
{
    return precioCosto;
}

int Abarrote::getExistencia()
{
    return  existencia;
}

int Abarrote::getLimite()
{
    return limite;
}

void Abarrote::setCodigo(string codigo)
{
    this->codigo = codigo;
}

void Abarrote::setNombreComercial(string nombre)
{
    this->nombreComercial = nombre; 
}

void Abarrote::setDescripcion(string descripcion)
{
    this->descripcion = descripcion; 
}

void Abarrote::setCategoria(int categoria)
{
    this->categoria = categoria;
}

void Abarrote::setPrecio(double precio)
{
    this->precioCosto = precio; 
}

void Abarrote::setExistencia(int existencia)
{
    this->existencia = existencia; 
}

void Abarrote::setLimite(int limite)
{
    this->limite = limite; 
}

bool Abarrote::esNacional()
{
    return nacional; 
}

double Abarrote::calculaPorcGanancia()
{
    double calculo = 0.9; 
    return calculo; 
}
