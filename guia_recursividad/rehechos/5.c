/*
Desarrollar una función recursiva para obtener en mayor valor en un vector de números enteros
*/

# include <stdio.h>

# define MF 3

typedef int Tvec[MF];

int obtener_mayor_valor(Tvec vector, int ML, int MAX){
    if (ML > 0){
        return MAX;
    }
    else{
        if (vector[ML] > MAX){
            return obtener_mayor_valor(vector, ML-1, vector[ML]);
        }
        else{
            return obtener_mayor_valor(vector, ML-1, MAX);
        }
    }
}

void main(){
    Tvec vector =  {2,4,3};
    int ML, MAX;
    ML = 3;

    MAX = vector[0];

    obtener_mayor_valor(vector, ML, MAX);

    printf("El mayor valor es: %i", MAX);

}