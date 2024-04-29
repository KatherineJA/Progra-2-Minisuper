#include "Conserva.h"

Conserva::Conserva()
{
    codigo = " ";
    nombreComercial = "new string()";
    descripcion = "new string()";
    categoria = 0;
    precioCosto = 0.0; 
    existencia = 0; 
    limite = 0; 
    envasado = true; 

}

Conserva::Conserva(string codigo, string nombreComercial, string descripcion, int categoria, double precioCosto, int existencia, int limite, bool envasado)
{
    this->codigo = codigo; 
    this->nombreComercial = nombreComercial; 
    this->descripcion = descripcion; 
    this->categoria = categoria; 
    this->precioCosto = precioCosto; 
    this->existencia = existencia; 
    this->limite = limite; 
    this->envasado = envasado; 
}

string Conserva::getCodigo()
{
    return codigo; 
}

string Conserva::getNombreComercial()
{
    return nombreComercial; 
}

string Conserva::getDescripcion()
{
    return descripcion; 
}

int Conserva::getCategoria()
{
    return categoria; 
}

double Conserva::getPrecioCosto()
{
    return precioCosto; 
}

int Conserva::getExistencia()
{
    return existencia; 
}

int Conserva::getLimite()
{
    return limite; 
}

void Conserva::setCodigo(string codigo )
{
    this->codigo = codigo; 
}

void Conserva::setNombreComercial(string nombre)
{
    this->nombreComercial = nombre; 
}

void Conserva::setDescripcion(string descripion)
{
    this->descripcion = descripion; 
}

void Conserva::setCategoria(int c )
{
    this->categoria = c; 
}

void Conserva::setPrecio(double precio)
{
    this->precioCosto = precio; 
}

void Conserva::setExistencia(int existe)
{
    this->existencia = existe; 
}

void Conserva::setLimite(int limite)
{
    this->limite = limite; 
}

double Conserva::calculaPorcGanancia()
{
    double doble =  980 ; 
    return doble; 
}

string Conserva::toString()
{
    string result = "Codigo: " + getCodigo() + "\n";
    result += "Nombre Comercial: " + getNombreComercial() + "\n";
    result += "Descripcion: " + getDescripcion() + "\n";
    result += "Categoria: " + to_string(getCategoria()); +"\n";
    result += "\nPrecio Costo: " + to_string(getPrecioCosto()) + "\n";
    result += "Existencia: " + to_string(getExistencia()) + "\n";
    result += "Limite: " + to_string(getLimite()) + "\n";
    result += "Envasado?: ";
    if (esEnvasado()) {
        result += "Si\n";
    }
    else {
        result+="No\n";
    }

    return result;
}

string Conserva::toStringFactu()
{
    string result = "Codigo: " + getCodigo() + "\n"; 
    result += "Nombre Comercial: " + getNombreComercial() + "\n"; 
    result += "Descripcion: " + getDescripcion() + "\n";
    result += "\nPrecio Costo: " + to_string(getPrecioCosto()) + "\n";
    result += "Envasado?: "; 
    if (esEnvasado()) { 
        result += "Si\n"; 
    }
    else {
        result += "No\n"; 
    }
     
    return result; 
}

bool Conserva::esEnvasado()
{
    return envasado;
}

