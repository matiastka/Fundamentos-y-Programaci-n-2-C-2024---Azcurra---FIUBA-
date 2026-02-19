/*
 Escribir un subprograma que dada una matriz de números reales, de n x m, 
 devuelva un vector que en cada posición i almacene el elemento mínimo de cada fila i de la matriz. 
*/

# include <stdio.h>

# define FILAS 2

# define COLUMNAS 2

# define MF FILAS

typedef float Tmat[FILAS][COLUMNAS];

typedef float Tvec[MF];

void CargarDatosMatriz(Tmat matriz){
    int contador_1, contador_2;
    float numero;

    for (contador_1 = 0; contador_1 < FILAS; contador_1++){
        for(contador_2 = 0; contador_2 < COLUMNAS; contador_2++){
            printf("Ingrese un valor para cargar a la matriz en la posicion [%i][%i]: ", contador_1, contador_2);
            scanf("%f", &numero);
            matriz[contador_1][contador_2] = numero; // Forma 2 de cargar un numero en la matriz
        }
    }
}

void ObtenerElementoMinimo(Tmat matriz, Tvec vector){
    int contador_1, contador_2;
    float valor_minimo;

    for (contador_1 = 0; contador_1 < FILAS; contador_1++){
        valor_minimo = matriz[0][0]; // Cada vez que inciamos el recorrido por las filas, se incia y reinicia el valor_minimo en la 1er posicion de la matriz
        for(contador_2 = 0; contador_2 < COLUMNAS; contador_2++){
            if (matriz[contador_1][contador_2] <= valor_minimo){
                valor_minimo = matriz[contador_1][contador_2]; 
            }
        }
        vector[contador_1] = valor_minimo; // Cargamos en el vector en la posicion de las filas el valor minimo
    }
}

void MostrarDatosVector(Tvec vector){ 
    int contador;

    for (contador = 0; contador < MF; contador++){ // Va a ser hasta el MF porque como se carga completamente el vector entonces MF = ML
        printf("%f ", vector[contador]);
    }
}

void main(){ // Me tomo licencia y n y m son constantes arbritarias que se editan por fuera del programa
    Tmat matriz;
    Tvec vector;

    CargarDatosMatriz(matriz);

    ObtenerElementoMinimo(matriz, vector);

    //MostrarDatosVector(vector);
}