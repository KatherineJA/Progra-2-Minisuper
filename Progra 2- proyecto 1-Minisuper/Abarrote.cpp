#include "Abarrote.h"
#include <sstream>
Abarrote::Abarrote(Producto* producto, string nombreEmpresa,double peso,bool nacional,Perecedero* p1)
{
    this->ptrProducto = producto; 
    this->empresaNombre = nombreEmpresa; 
    this->peso = peso; 
    this->nacional = nacional; 
    this->perecedero = p1; 
    this->categoria = producto->getCategoria();
    this->codigo = producto->getCodigo();
    this->limite = producto->getLimite();
    this->existencia = producto->getExistencia();
    this->nombreComercial = producto->getNombreComercial();
    this->descripcion = producto->getDescripcion();
    this->precioCosto = producto->getPrecioCosto();
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

   result += ptrProducto->calculaPorcGanancia();
    result += "Nacional: "; 
    if (esNacional()) { 
        result += "Si\n"; 
    }
    else {
        result += "No\n"; 
    }
    result += "Peso: " + to_string(getPeso()) + "\n"; 
    result += "Empresa: " + (empresaNombre)+"\n";
    result += "Ganancai para la tienda: "; 
    result += to_string(calculaPorcGanancia());
    result += "\n";
    return result; 
}

string Abarrote::toStringFactu()
{
    string result = ptrProducto->toStringFactu();
    result += perecedero->toStringFechaCaducidad();
    result += "\nNacional: ";
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
