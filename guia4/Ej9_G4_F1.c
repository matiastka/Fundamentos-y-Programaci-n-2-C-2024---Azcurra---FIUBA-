/*
Dado un vector a de longitud n ordenado ascendente y un elemento p del
mismo tipo que los elementos del vector, intercalar p en el vector a de modo
que siga ordenado. 
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

void OrdenarModificado(Tvec vector, int ML){ // Por metodo de seleccion (modificado)
    int i, j, aux;

    for (i = 0; i < ML; i++){ // En este caso es i < ML y no i < ML-1 porque en ML va a estar el valor insertado (caso unico)
        for (j = i+1; j <= ML; j++){ // En este caso es j <= ML y no j < ML idem justificacion anterior
            if (vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void InsertarNumero(Tvec vector, int ML, int numero_a_insertar){ // Usamos método de Inserrcion Simple (se puede si el vector si esta ordenado y si no se sabe la # de elementos)
    vector[ML] = numero_a_insertar;
}

void MostrarVectorModificado(Tvec vector, int ML){ // Modificado a los anteriores
    int contador;

    for (contador = 0; contador <= ML; contador++){ // En este caso el contador <= ML y no contador < ML porque el contador 
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
        InsertarNumero(vector, n, p);

        OrdenarModificado(vector, n);

        MostrarVectorModificado(vector, n);

    }
    else{
        printf("El vector esta a su maxima capacidad, no se puede insertar ningun valor.\n");
        printf("El vector queda como estaba originalmente:\n");
        
        OrdenarModificado(vector, n-1); //Va a ser n-1 porque es el ordenar modificado
        
        MostrarVectorModificado(vector, n-1); //Va a ser n-1 porque es el MostrarVector modificado
    }
}
