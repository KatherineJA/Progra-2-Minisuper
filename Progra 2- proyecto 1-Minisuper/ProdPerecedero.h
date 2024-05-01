#ifndef PRODPERECEDERO_H
#define PRODPERECEDERO_H
#include "Producto.h"
#include "Categoria.h"
#include "Perecedero.h"
#include <iomanip>
//Decorador
class ProdPerecedero : public Producto
{
protected:
    bool nacional;
    double peso;
    Perecedero* perecedero; 
    Producto* ptrProducto; // Component* compo
public:

   
    virtual bool getNacional() = 0 ;
    virtual double getPeso()= 0;

    virtual void setNacional(bool nacional)=0;
    virtual void setPeso(double peso)=0;

    virtual string getCodigo()=0;
    virtual string getNombreComercial()=0;
    virtual string getDescripcion()=0;
    virtual int getCategoria()=0;
    virtual double getPrecioCosto()=0;
    virtual int getExistencia()=0;
    virtual int getLimite()=0;
    

    virtual void setCodigo(string codigo)=0;
    virtual void setNombreComercial(string nombre)=0;
    virtual void setDescripcion(string descripcion)=0;
    virtual void setCategoria(int categoria)=0;
    virtual void setPrecio(double precio)=0;
    virtual void setExistencia(int existencia)=0;
    virtual void setLimite(int limite)=0;
    virtual bool esNacional()=0;

    virtual double calculaPorcGanancia()=0;

    virtual string toString()=0;
};
#endif PRODPERECEDERO_H