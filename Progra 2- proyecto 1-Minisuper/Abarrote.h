#ifndef ABARROTE_H
#define ABARROTE_H
#include "ProdPerecedero.h"
//ConcreteDecoratorA 
class Abarrote: public ProdPerecedero
{
protected:
	string empresaNombre;
public:

    Abarrote(Producto* producto, string nombreEmpresa,double peso,bool nacional,Perecedero* p1);

    string getEmpresaNombre();
    void setEmpresaNombre(string empresa);
    string toString() override;
    string toStringFactu() override;

    // Heredado via ProdPerecedero
    void setCategoria(int) override;

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

  

    void setPrecio(double precio) override;

    void setExistencia(int existencia) override;

    void setLimite(int limite) override;

    bool esNacional() override;

    double calculaPorcGanancia() override;

   


};

#endif ABARROTE_H