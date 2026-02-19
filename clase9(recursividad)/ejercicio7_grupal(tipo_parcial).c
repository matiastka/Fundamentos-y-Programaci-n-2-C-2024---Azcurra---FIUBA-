/*
Una función recursiva en C que suma los elementos en posiciones pares de un arreglo
*/

# include <stdio.h>

# define MF 100

typedef int Tvec[MF];

int sumar_elementos(int vector[], int ML){
    if(ML < 0){
        return 0;
    }
    else{ // Caso recursivo
        if (ML % 2 == 0){ // Parte 1
            return vector[ML] + sumar_elementos(vector, ML-1);
        }
        else{ // Parte 2
            return 
            
            sumar_elementos(vector, ML-1);
        }
    }
}

void main(){
    int vector[] = {48,23,2,5,18};
    int resultado;
    int ML = 4;

    resultado = sumar_elementos(vector, ML);

    printf("La suma de los elementos en posiciones pares del vector es: %i", resultado);
    
}