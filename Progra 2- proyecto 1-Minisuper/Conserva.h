#ifndef CONSERVA_H
#define CONSERVA_H
#include "Producto.h"
class Conserva : public Producto
{
private:
	bool envasado;
public:
	Conserva();
	Conserva(string codigo, string nombreComercial, string descripcion, int categoria, double precioCosto, int existencia, int limite, bool envasado);


	// Heredado v�a Producto
	string getCodigo() override;

	string getNombreComercial() override;

	string getDescripcion() override;

	int getCategoria() override;

	double getPrecioCosto() override;

	int getExistencia() override;

	int getLimite() override;

	void setCodigo(string) override;

	void setNombreComercial(string) override;

	void setDescripcion(string) override;

	void setCategoria(int) override;

	void setPrecio(double) override;

	void setExistencia(int) override;

	void setLimite(int) override;

	double calculaPorcGanancia() override;

	string toString() override;
	string toStringFactu() override;
	bool esEnvasado();

	// Heredado via Producto
}; 

#endif CONSERVA_H
