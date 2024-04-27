#include "Fecha.h"

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    annio = 2000;
}

Fecha::Fecha(int d, int m, int a) {
    dia = d;
    mes = m;
    annio = a;
}

Fecha::~Fecha() {
   
}

void Fecha::setDia(int d) {
   dia = d;
}
void Fecha::setMes(int m) {
    mes = m;
}
void Fecha::setAnnio(int a) {
    annio = a;
}

int Fecha::getDia() {
    return dia;
}
int Fecha::getMes() {
    return mes;
}
int Fecha::getAnnio() {
    return annio;
}

string Fecha::toStringFecha() {
    stringstream s;
    s << dia << "/" << mes << "/" << annio;
    return s.str();
}

void Fecha::obtenerFechaActual()
{
    // Obtener el tiempo actual en segundos desde epoch
    time_t tiempoActual;
    time(&tiempoActual);

    // Obtener la fecha y hora local de manera segura
    struct tm fechaBuffer;
    localtime_s(&fechaBuffer, &tiempoActual);

    // Actualizar los valores de día, mes y año
    dia = fechaBuffer.tm_mday;
    mes = fechaBuffer.tm_mon + 1; // tm_mon es 0-indexado
    annio = fechaBuffer.tm_year + 1900;
}
