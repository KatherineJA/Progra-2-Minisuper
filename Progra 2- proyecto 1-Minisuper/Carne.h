#ifndef CARNE_H
#define CARNE_H

#include "ProdPerecedero.h"
// ConcreteDecoratorB 

class Carne: public ProdPerecedero
{
protected:
	string animal;
	string parteDelAnimal;
	
public:
	Carne();
	Carne(Producto* producto, string animal, string parteDeAnimal,double peso, bool nacional,Perecedero* p1);

	void setAnimal(string animal);
	string getAnimal();

	void setParteDeAnimal(string animal);
	string getParteDeAnimal();

	string toString() override;
	string toStringFactu() override;


	// Heredado v�a ProdPerecedero
	bool getNacional() override;

	double getPeso() override;

	void setNacional(bool nacional) override;

	void setPeso(double peso) override;

	string getCodigo() override;

	string getNombreComercial() override;

	string getDescripcion() override;

	int getCategoria() override;

	double getPrecioCosto() override;

	int getExistencia() override;

	int getLimite() override;

	void setCodigo(string codigo) override;

	void setNombreComercial(string nombre) override;

	void setDescripcion(string descripcion) override;

	void setCategoria(int categoria) override;

	void setPrecio(double precio) override;

	void setExistencia(int existencia) override;

	void setLimite(int limite) override;

	bool esNacional() override;

	double calculaPorcGanancia() override;

	

};

#endif CARNE_H