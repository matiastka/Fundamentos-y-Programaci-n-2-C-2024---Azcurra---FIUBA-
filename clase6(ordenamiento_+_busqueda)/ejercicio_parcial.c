/* 
Hacer un vector con 10 numeros enteros desordenados y hacer una funcion que los ordene (implcitamente piden que se devuelva el vector)
*/

# include <stdio.h>

# define MF 10

typedef int Tvec[MF];

void CargarDatos(Tvec vector, int *ML){
    int contador, numero;

    contador = 0;

    printf("Ingresar un numero para cargar al vector (0 para finalizar): ");
    scanf("%i", &numero);

    while ((contador < MF) && (numero != 0)){
        vector[contador] = numero;
        contador++;

        if (contador < MF){
            printf("Ingresar un numero para cargar al vector (0 para finalizar): ");
            scanf("%i", &numero);  
        }
    }
    *ML = contador;
}

void Ordenar1(Tvec vector, int n){ // Ordenar por Burbujeo
    int i, j, aux;

    for (i = 1; i < n; i++){
        for (j = 0; j < n-i; j++){
            if (vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

void Ordenar2(Tvec vector, int n){ // Ordenar por Seleccion
    int i, j, aux;

    for (i = 0; i < n-1; i++){
        for (j = i+1; j < n; j++){
            if (vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void Ordenar3(Tvec vector, int n){ // Ordenamos por Inserccion
    int k, contador, aux;

    for (k = 1; k < n; k++){
        aux = vector[k];

        contador = k - 1;

        while ((contador >= 0) && (aux > vector[contador])){
            vector[contador + 1] = vector[contador];
            contador = contador - 1;
        }
        vector[contador + 1] = aux;
    }
}

void MostrarDatos(Tvec vector, int ML){
    int contador;

    printf("\n(");
    for (contador = 0; contador < ML; contador++){
        printf("%i ", vector[contador]);
    }
    printf(")");
}

void main(){
    Tvec vector;
    int ML;

    CargarDatos(vector, &ML);

    Ordenar1(vector, ML);

    //Ordenar2(vector, ML);
    
    //Ordenar3(vector, ML);

    MostrarDatos(vector, ML);
}