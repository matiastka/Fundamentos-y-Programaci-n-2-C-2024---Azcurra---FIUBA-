/*
Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente
y el segundo ordenado descendente, crear un nuevo vector c de n + m
elementos intercalando los elementos de a y b de modo que c quede ordenado
ascendente. 

longitud siempre es a ml
*/

# include <stdio.h>

# define MF 20

typedef int Tvec[MF];

void CargarVector(Tvec c, int a[], int b[], int n, int m){ //Ayudado, me falta hacer que se intercalen
    int contador, k;

    // 1ro guardar el 1er vector en c
    for (contador = 0; contador < n; contador++){ // Contador va desde 0 hasta n-1
        c[contador] = a[contador];
    }
    // 2do guardar el 2do vector en c. El truco esta en empezar el contador en la posicion siguiente de la ultima pos de el 1er vector.
    for (contador = n; contador < n+m; contador++){ // Contador va desde n hasta n+m (es lo mismo que contador <= n+m-1)
        c[contador] = b[contador-n];
    }
}

void Ordenar(Tvec vector, int cant_elementos_a_ordenar){ // Uso metodo de Burbujeo
    int contador_1, contador_2, aux;
    
    for (contador_1 = 1; contador_1 < cant_elementos_a_ordenar; contador_1++){
        for (contador_2 = 0; contador_2 < cant_elementos_a_ordenar-contador_1; contador_2++){
            if (vector[contador_2] > vector[contador_2+1]){
                aux = vector[contador_2];
                vector[contador_2] = vector[contador_2+1];
                vector[contador_2+1] = aux;
            }
        }
    }
}

void MostrarVector(Tvec vector, int n, int m){
    int contador;

    for (contador = 0; contador < n+m; contador++){
        printf("%i ", vector[contador]);
    }
}

void main(){
    Tvec c;
    int n, m;
    int vector_a[] = {10,9,8,7,6,5,4,3,2,1};
    n = 10;
    int vector_b[] = {1,2,3,4,5};
    m = 5;

    CargarVector(c, vector_a, vector_b, n, m);

    Ordenar(c, n+m);

    MostrarVector(c, n, m);

}