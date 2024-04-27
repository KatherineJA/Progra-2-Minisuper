//#include "ProdPerecedero.h"
//
//ProdPerecedero::ProdPerecedero() {
//	this->nacional = true;
//	this->peso = 0.0; 
//	this->perecedero = new Perecedero(); 
//	
//}
//
//
//ProdPerecedero::ProdPerecedero::ProdPerecedero(Producto* productoBase, bool nacionalidad, double peso,Perecedero* perecedero)
//	: producto(productoBase), nacional(nacionalidad), peso(peso),perecedero(perecedero)  {}
//
//
//bool ProdPerecedero::getNacional()
//{
//	return nacional;
//}
//
//double ProdPerecedero::getPeso()
//{
//	return peso;
//}
//
//void ProdPerecedero::setNacional(bool nacional)
//{
//	this->nacional = nacional;
//}
//
//void ProdPerecedero::setPeso(double peso)
//{
//	this->peso = peso;
//}
//
//string ProdPerecedero::getCodigo()
//{
//	return codigo;
//}
//
//string ProdPerecedero::getNombreComercial()
//{
//	return nombreComercial;
//}
//
//string ProdPerecedero::getDescripcion()
//{
//	return descripcion;
//}
//
//int ProdPerecedero::getCategoria()
//{
//	return categoria;
//}
//
//double ProdPerecedero::getPrecioCosto()
//{
//	return precioCosto;
//}
//
//int ProdPerecedero::getExistencia()
//{
//	return existencia;
//}
//
//int ProdPerecedero::getLimite()
//{
//	return limite;
//}
//
//
//
//void ProdPerecedero::setCodigo(string codigo)
//{
//	producto->setCodigo(codigo);
//}
//
//void ProdPerecedero::setNombreComercial(string nombre)
//{
//	setNombreComercial(nombre);
//}
//
//void ProdPerecedero::setDescripcion(string descripcion)
//{
//	setDescripcion(descripcion);
//}
//
//void ProdPerecedero::setCategoria(string categoria)
//{
//	setCategoria(categoria);
//}
//
//void ProdPerecedero::setPrecio(double precio)
//{
//	setPrecio(precio);
//}
//
//void ProdPerecedero::setExistencia(int existencia)
//{
//	setExistencia(existencia);
//}
//
//void ProdPerecedero::setLimite(int limite)
//{
//	setLimite(limite);
//}
//
//bool ProdPerecedero::esNacional()
//{
//	return nacional;
//}
//
//
//
//double ProdPerecedero::calculaPorcGanancia()
//{
//	double ganancia = 0.0;
//
//	ganancia = Categoria::porceGanancia(categoria) * (getPrecioCosto());
//	return ganancia;
//}
//
//string ProdPerecedero::toString()
//{
//	string result = producto->toString(); // Llamada a toString() del component
//	result += "Nacional: ";
//	if (esNacional()) {
//		result += "Si\n";
//	}
//	else {
//		result += "No\n";
//	}
//	result += "Peso: "    "\n";
//
//	return result;
//
//}
