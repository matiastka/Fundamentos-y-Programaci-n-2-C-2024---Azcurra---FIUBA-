/*
Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada. Informar la
cantidad de números y el contenido del vector indicando la posición ocupada
por cada número a partir de la primera posición
*/

# include <stdio.h>

# define MF 5  // Definimos Maximo Fisico

typedef float Tvec[MF]; // Definimos el tipo de dato y el Maximo Fisico que puede tomar Tvec

void CargarDatos(Tvec vector, int *ML){
    int contador;
    float numero;

    contador = 0;

    printf("Ingrese un valor a cargar al vector (0 para finalizar): "); // Me tomo licencia, y digo que 0 es la finalizacion
    scanf("%f", &numero);

    while ((numero != 0) && (contador < MF)){
        vector[contador] = numero;
        contador++;

        if (contador < MF){ //Evita preguntar 1 vez demas
            printf("Ingrese un valor a cargar al vector (0 para finalizar): ");
            scanf("%f", &numero);
        }
    }
    *ML = contador; //Guardamos el contador en el ML (como mucho es igual a MF)
}

void MostrarDatos(Tvec vector, int ML){
    int contador;

    printf("La cantidad de numeros que tiene el vector es: %i\n", ML);

    for (contador = 0; contador < ML; contador++){
        printf("El contenido del vector en la posicion %i es: %f\n", contador, vector[contador]);
    }
}

void main(){
    int ML;
    Tvec vector;

    ML = 0;

    CargarDatos(vector, &ML);

    MostrarDatos(vector, ML);
}