/*
Cargar un conjunto de números de documento en un vector. No se conoce la
cantidad de datos válidos. Informar el número de documento más alto del
conjunto y la posición que ocupa. Puede haber repetición, en este caso
informar todas las posiciones que ocupa
*/

# include <stdio.h>

# include <stdbool.h>

# define MF 10

typedef int Tvec[MF];

void CargarDatos(Tvec vector, int *ML){
    int contador, numero;
    contador = 0;

    numero = -1;
    
    while ((numero != 0) && (contador < MF)){
        printf("Ingrese un numero (0 para finalizar): ");
        scanf("%i", &numero);
        if ((numero != 0) && (contador < MF)){
            vector[contador] = numero;
            contador++;
        }
    }
    *ML = contador;
}


void ObtenerMayorNumero(Tvec vector, int ML, int *mayor_numero){ // Cortesia de Jose.
    int contador;

    *mayor_numero = vector[0];

    for (contador = 0; contador < ML; contador++){
        if (vector[contador] > *mayor_numero){
            *mayor_numero = vector[contador];
        }
    }
}


void MostrarMayorNumero(Tvec vector, int ML, int mayor_numero){ 
    int contador;

    contador = 0;

    for (contador = 0; contador < ML; contador++){
        if (vector[contador] == mayor_numero){
            mayor_numero = vector[contador];
            printf("El mayor numero es: %i.\nEn la posicion: %i\n", mayor_numero, contador);
        }
    }

}


void main(){
    Tvec vector;
    int ML, mayor_numero;

    CargarDatos(vector, &ML);

    ObtenerMayorNumero(vector, ML, &mayor_numero);

    MostrarMayorNumero(vector, ML, mayor_numero);

}