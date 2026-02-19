/* 
Ingresar una serie de números positivos (validar) (una funcion) en un vector.
Invertir el vector (una funcion) y mostrar (una funcion) la serie invertida. 

1. pensar forma de reincia valor de numero (solo hacer un scanf en ValidarNumero)
*/

# include <stdio.h>

# define MF 10

typedef float Tvec[MF];

void ValidarNumero(float *valor){
    printf("Ingrese un numero positivo (0 para finalizar): ");
    scanf("%f", valor);

    while (*valor < 0){
        printf("Ingrese un numero positivo (0 para finalizar): ");
        scanf("%f", valor);
    }
}

void CargarDatos(Tvec vector, int *ML){
    int contador;
    float numero;

    ValidarNumero(&numero);

    while ((numero != 0) && (contador < MF)){
        vector[contador] = numero;
        contador++;

        if (contador < MF){
            ValidarNumero(&numero);
        }
    }
    *ML = contador;
}

void InvertirVector(Tvec vector, int ML){ // INVERION NO ES UNA LOGICA DE ORDENAMIENTO, ES DAR VUELTA EL VECTOR!!!!!!
    int contador, mitad, aux;

    mitad = ML/2;

    for (contador = 0; contador < mitad; contador++){
        aux = vector[contador];
        vector[contador] = vector[ML-1-contador];
        vector[ML-1-contador] = aux;
    }
}

void MostrarDatos(Tvec vector, int ML){
    int contador;

    printf("\n(");
    for (contador = 0; contador < ML; contador++){
        printf("%f ", vector[contador]);
    }
    printf(")");
}

void main(){
    Tvec vector;
    int ML;

    CargarDatos(vector, &ML);

    InvertirVector(vector, ML);

    MostrarDatos(vector, ML);
}