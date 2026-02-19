/*
Dado un listado de valores numéricos i y x, donde i es un entero mayor que
0 y x un real, almacenar x en la posición i de un vector. El listado no se ingresa
ordenado por posición. Informar la cantidad de números y el contenido del
vector indicando la posición ocupada por cada número a partir de la primera
posición. 
*/

# include <stdio.h>

# define MF 10

typedef float Tvec[MF];

void ValidarPosicion(int *posicion){
    while (*posicion < 0 || *posicion > MF){ // Como validamos las posiciones desde 1 entonces va hasta el MF INCLUIDO
        printf("Ingrese la posicion del vector (0 para finalizar) (positivo y menor/igual a %i): ", MF);
        scanf("%i", posicion);
    }
}

void IncializarVector(Tvec vector){
    int contador;

    for (contador = 0; contador < MF; contador++){
        vector[contador] = 0.0; //Como es flotante en vez de poner 0 se pone 0.0
    }
}

void CargarDatos(Tvec vector, int posicion, float numero){
    int contador;

    contador = 0;

    while ((posicion != 0) && (contador < MF)){
        printf("Ingrese un numero real: ");
        scanf("%f", &numero);
        vector[posicion-1] = numero; //Es posicion -1 porque las posiciones siempre empiezan en 0 (y como la validacion da posiciones desde 1 hasta MF (incluido) --> hacemos resta) (gracias aria)
        
        posicion = -1; // Reinciamos el valor de la posicion (fuera del rango)

        if (contador < MF){
            ValidarPosicion(&posicion);
        }
    }
}

void MostrarCantidadNumeros(Tvec vector){
    int contador, cantidad_numeros;

    // HAY QUE SIEMPRE INCIALIZAR LOS CONTADORES!!!!!!!!!!!
    cantidad_numeros = 0; 

    for (contador = 0; contador < MF; contador++){
        if (vector[contador] != 0){
            cantidad_numeros++;
        }
    }
    printf("La cantidad numeros que tiene el vector es: %i\n", cantidad_numeros);
}

void MostrarContenido(Tvec vector){
    int contador;

    for (contador = 0; contador < MF; contador++){ // Como no sabemos en que posicion se guardan los valores, entonces usamos el Maximo Fisico y recorremos todo el vector
        if(vector[contador] != 0){
            printf("El contenido del vector en la posicion %i es: %f \n", contador, vector[contador]);
        }
    }
}

void main(){
    Tvec vector;
    int i;
    float x;

    i = -1; // Incializamos a i fuera del rango permitido
    x = -1; // Incializamos a x para que no joda C (pero esta bien no incializarla)

    ValidarPosicion(&i); //Validamos que i este dentro del rango

    IncializarVector(vector); // Como no sabemos que posicion ocupa cada numero real, lo incializamos todo en 0

    CargarDatos(vector, i, x);

    MostrarCantidadNumeros(vector);

    MostrarContenido(vector);
}