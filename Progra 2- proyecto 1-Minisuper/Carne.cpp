#include "Carne.h"

Carne::Carne() : ProdPerecedero() {
    animal = "";

    parteDelAnimal = " ";
}


Carne::Carne(Producto* producto, string animal, string parteDeAnimal,double peso, bool nacional,Perecedero* p1) {
    this->ptrProducto = producto; 
    this->animal = animal;
    this->parteDelAnimal = parteDeAnimal;
    this->peso = peso;
    this->nacional = nacional;
    this->perecedero = p1; 
}



void Carne::setAnimal(string animal) {
    this->animal = animal;
}

string Carne::getAnimal() {
    return animal;
}

void Carne::setParteDeAnimal(string parteDeAnimal) {
    this->parteDelAnimal = parteDeAnimal;
}

string Carne::getParteDeAnimal() {
    return parteDelAnimal;
}

string Carne::toString()
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

    result += "Animal: " + (animal) + "\n" + "Parte del animal: " + (parteDelAnimal) + "\n";
    return result;

}



void Carne::setCategoria(int categoria)
{
    this->categoria = categoria;
}

bool Carne::getNacional()
{
    return nacional;
}

double Carne::getPeso()
{
    return peso;
}

void Carne::setNacional(bool nacional)
{
    this->nacional = nacional;
}

void Carne::setPeso(double peso)
{
    this->peso = peso;
}

string Carne::getCodigo()
{
    return codigo;
}

string Carne::getNombreComercial()
{
    return nombreComercial;
}

string Carne::getDescripcion()
{
    return descripcion;
}

int Carne::getCategoria()
{
    return categoria;
}

double Carne::getPrecioCosto()
{
    return precioCosto;
}

int Carne::getExistencia()
{
    return  existencia;
}

int Carne::getLimite()
{
    return limite;
}

void Carne::setCodigo(string codigo)
{
    this->codigo = codigo;
}

void Carne::setNombreComercial(string nombre)
{
    this->nombreComercial = nombre;
}

void Carne::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}



void Carne::setPrecio(double precio)
{
    this->precioCosto = precio;
}

void Carne::setExistencia(int existencia)
{
    this->existencia = existencia;
}

void Carne::setLimite(int limite)
{
    this->limite = limite;
}

bool Carne::esNacional()
{
    return nacional;
}

double Carne::calculaPorcGanancia()
{
    double calculo = 0.0;
    return calculo;
}
