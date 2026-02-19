/*
Dado un vector a de longitud n ordenado ascendente y un elemento p del
mismo tipo que los elementos del vector, intercalar p en el vector a de modo
que siga ordenado. 

Usando logica de desplazamiento (gracias Aria)
*/

# include <stdio.h>

# define MF 10

typedef int Tvec[MF];

void CargarDatos(Tvec vector, int *ML){
    int contador, numero;

    contador = 0;

    printf("Ingrese un valor a cargar al vector (0 para finalizar): ");
    scanf("%i", &numero);

    while ((numero != 0) && (contador < MF)){
        vector[contador] = numero;
        contador++;

        if (contador < MF){
            printf("Ingrese un valor a cargar al vector (0 para finalizar): ");
            scanf("%i", &numero);
        }
    }
    *ML = contador;
}

void IntercalarNumero(Tvec vector, int *ML, int numero_a_insertar){  //Gracias Aria
    int i;

    i = *ML;

    while ((i > 0) && (vector[i-1] > numero_a_insertar)){ //Logica de desplazamiento hacia la derecha: Si el valor del vector en la ultima posicion es mayor al numero a insertar y no se llego a la 1ra posicion
        vector[i] = vector[i - 1]; // Guarda el valor del vector en la posicion i (que empieza siendo la ultima) por el valor de la posicion anterior a la ultima (i)
        i--; //Va moviendo la posicion de i a la izquierda
    }
    vector[i] = numero_a_insertar; // Colocamos el valor en la posicion correspondiente
}

void Ordenar(Tvec vector, int ML){ 
    int i, j, aux;

    for (i = 0; i < ML-1; i++){ 
        for (j = i+1; j < ML; j++){ 
            if (vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void MostrarVector(Tvec vector, int ML){
    int contador;

    for (contador = 0; contador < ML; contador++){
        printf("%i ", vector[contador]);
    }
}

void main(){
    Tvec vector;
    int n, p;

    printf("Ingrese el valor que desea intercalar al vector: ");
    scanf("%i", &p);

    CargarDatos(vector, &n);

    if (n < MF){
        IntercalarNumero(vector, &n, p);

        Ordenar(vector, n);
        
        MostrarVector(vector, n);
    }
    else{
        printf("El vector esta a su maxima capacidad, no se puede insertar ningun valor.\n");
        printf("El vector queda como estaba originalmente:\n");
        
        Ordenar(vector, n);
        
        MostrarVector(vector,n);
    }
}