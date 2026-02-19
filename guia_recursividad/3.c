// Desarrollar una función recursiva para realizar una búsqueda binaria en un vector

# include <stdio.h>

# define MF 10

typedef int Tvec[MF];

int busqueda_binaria_recursiva(Tvec vector, int primera_posicion, int ultima_posicion, int buscado){
    int mitad;

    mitad = (primera_posicion + ultima_posicion)/2;

    if (primera_posicion > ultima_posicion){ // Si esta fuera de rango (Caso Base)
        return -1;
    }
    else{
        if (buscado == vector[mitad]){
            return mitad;
        }
        else{
            if (buscado > vector[mitad]){ // Caso Recursivo parte 1
                return busqueda_binaria_recursiva(vector, primera_posicion + 1, ultima_posicion, buscado);
            }
            else{ // Caso Recursivo parte 2
                return busqueda_binaria_recursiva(vector, primera_posicion, ultima_posicion - 1, buscado);
            }
        }
    }
}

void main(){
    Tvec vector = {1,3,5,7,9,11,13,15,17,19};
    int buscado, resultado, ML, primera_posicion, ultima_posicion;

    buscado = 15;
    ML = 10;
    primera_posicion = 0;
    ultima_posicion = ML - 1;

    resultado = busqueda_binaria_recursiva(vector, primera_posicion, ultima_posicion, buscado);

    if (resultado == -1){
        printf("No se encontro el numero buscado");
    }
    else{
        printf("El %i esta en la posicion %i", buscado, resultado);
    }
}