#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std; 

class Fecha
{
private:
	int dia;
	int mes;
	int annio; 
	 


public: 
	Fecha(); 
	Fecha(int, int, int);
	~Fecha(); 
	void setDia(int); 
	void setMes(int); 
	void setAnnio(int); 
	
	int getDia(); 
	int getMes(); 
	int getAnnio(); 
	
	string toStringFecha(); 
	/*void obtenerFechaActual(); */
	int obtenerDiaActual();
	int obtenerMesActual();
	int obtenerAnnioActual();

};

#endif FECHA_H