/*
Cargar una serie de números reales en un vector. No se conoce la cantidad
exacta de datos, pero se sabe que no superan los 100. No se conocen cotas
para los datos. Informar el valor máximo, la cantidad de veces que aparece y
la/s posición/es que ocupa.

Aria: "Nose conocen cotas para los datos" = se puede ingresar cualquier cosa
*/

# include <stdio.h>

# define MF 100

typedef float Tvec[MF];

void CargarDatos(Tvec vector, int *ML){
    int contador; 
    float numero;

    contador = 0;
    numero = -1;

    printf("Ingrese un numero real para cargar al vector (0 para finalizar): ");
    scanf("%f", &numero);

    while ((numero != 0) && (contador < MF)){
        vector[contador] = numero;
        contador++;

        if (contador < MF){
            printf("Ingrese un numero real para cargar al vector (0 para finalizar): ");
            scanf("%f", &numero);
        }
    }
    *ML = contador;
}

void ObtenerMayorValor(Tvec vector, int ML, float *mayor_valor){
    int contador;

    *mayor_valor = vector[0];
    
    for (contador = 0; contador < ML; contador++){
        if (vector[contador] > *mayor_valor){ 
            *mayor_valor = vector[contador]; 
        }
    }
}

void MostrarDatos(Tvec vector, int ML, float mayor_valor){
    int contador, cant_veces;

    cant_veces = 0;

    printf("El mayor valor es: %i\n", mayor_valor);

    for (contador = 0; contador < ML; contador++){
        if (vector[contador] == mayor_valor){
            cant_veces++;
            printf("El %f aparece en la posicion: %i\n", mayor_valor, contador);
        }
    }
    printf("La cantidad de veces que aparece %f es: %i\n", mayor_valor, cant_veces);
}

void main(){
    Tvec vector;
    int ML;
    float mayor_valor;

    CargarDatos(vector, &ML);

    if (ML != 0){
        ObtenerMayorValor(vector, ML, &mayor_valor);
        MostrarDatos(vector, ML, mayor_valor);        
    }
    else{
        printf("No hay mayor valor porque nose ingresaron datos");
    }
}