#include "Categoria.h"

double Categoria::porceGanancia(int categ){

    if (categ == 1) {
        return 0.15; // Porcentaje de ganancia para productos en conserva
    }
    else if (categ == 2) {
        return 0.20; // Porcentaje de ganancia para abarrotes
    }
    else if (categ == 3) {
        return 0.30; // Porcentaje de ganancia para embutidos 
    }
    else {
        return 0.0;
    }
}
