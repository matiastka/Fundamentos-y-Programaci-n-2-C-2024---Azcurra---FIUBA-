# include <stdio.h>

# define MF 10

typedef int Tvec[MF];

int buscar(Tvec vector, int buscado, int primera_posicion, int ultima_posicion){
    
    int mitad = (primera_posicion + ultima_posicion) / 2;

    if (ultima_posicion < primera_posicion){ // Si esta fuera de rango, devuelve que no lo encontro
        return -1;
    }
    else{
        if (buscado < vector[mitad]){ // Si esta a la izquierda de la mitad se fija entre primera_posicion y la mitad -1
            return buscar(vector, buscado, primera_posicion, mitad - 1);
        }
        else{
            if (buscado > vector[mitad]){ // Si esta a la derecha de la mitad se fija entre mitad + 1 y ultima_posicion
                return buscar(vector, buscado, mitad + 1, ultima_posicion);
            }
            else{
                if (buscado == vector[mitad]){ // Si esta en la mitad, devuelve
                    return mitad;
                }
                else{ // Sino devuelve que no lo encontro
                    return -1;
                }
            }
        }
    }
}