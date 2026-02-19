/*
7)
Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones

8)  Idem problema anterior, pero el vector está ordenado ascendente
*/

# include <stdio.h>

# include <stdbool.h>

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

        if (contador < MF){ // Evita preguntar una vez demas
            printf("Ingrese un valor a cargar al vector (0 para finalizar): ");
            scanf("%i", &numero);
        }
    }
    *ML = contador;
}

int BusquedaSecuencia(Tvec vector, int ML, int buscado){
    int contador, posicion;
    bool encontrado;

    encontrado = false;
    contador = 0;
    posicion = -1;

    while((encontrado == false) && (contador < ML)){
        if (vector[contador] == buscado){
            encontrado = true;
            posicion = contador;
        }
        contador++;
    }
    return posicion;
}

void Ordenar(Tvec vector, int Cantidad_elementos){ // Por metodo de Seleccion
    int i, j, aux;

    for (i = 0; i < Cantidad_elementos-1; i++){
        for (j = i+1; j < Cantidad_elementos; j++){
            if (vector[i] > vector[j]){ // Se fija si el vector en la posicion i (empieza en 0) es mayor al vector en la proxima posicion (hasta terminar la iteracion de j)
                aux = vector[i]; // Guardamos el valor que vamos a mover
                vector[i] = vector[j]; // Sobreescribimos el valor del vector en la posicion i por la proxima posicion
                vector[j] = aux; // Sobreescribimos el valor del vector en la proxima posicion por aux
            }
        }
    }
}

void MostrarVector(Tvec vector, int ML){
    int contador;
    contador = 0;

    for (contador = 0; contador < ML; contador++){
        printf("%i ", vector[contador]);
    }
    printf("\n");
}

int BusquedaBinaria(Tvec vector, int ML, int buscado){
    int posicion, primera_posicion, ultima_posicion, posicion_del_medio;
    bool encontrado;

    posicion = -1;
    primera_posicion = 0;
    ultima_posicion = ML-1;
    posicion_del_medio = 0;
    encontrado = false;

    while (encontrado == false){
        if((buscado < vector[primera_posicion]) || (buscado > vector[ultima_posicion])){ // Si esta fuera del rango del vector, no lo encuentra
            encontrado = true;
            posicion = -1; 
        }
        else{
            posicion_del_medio = (primera_posicion + ultima_posicion)/2;

            if(buscado == vector[posicion_del_medio]){
                encontrado = true;
                posicion = posicion_del_medio;
            }
            else{
                if (buscado > vector[posicion_del_medio]){
                    primera_posicion = posicion_del_medio + 1;
                }
                if (buscado < vector[posicion_del_medio]){
                    ultima_posicion = posicion_del_medio - 1;
                }
            }
        }
    }
    return posicion;
}

void MostrarResultado(int buscado, int posicion){
    if (posicion == -1){
        printf("El valor %i no fue encontrado en el vector", buscado);
    }
    else{
        printf("El valor %i fue encontrado en la posicion %i", buscado, posicion);
    }
}

void main(){
    Tvec vector;
    int n, p, posicion;

    printf("Ingrese el valor 'p' que desea buscar: ");
    scanf("%i", &p);

    CargarDatos(vector, &n);

    /*  Por Busqueda Secuencial (no importa si esta ordenado): */

    // posicion = BusquedaSecuencia(vector, n, p);

    // MostrarResultado(p,posicion);

    /* Por Busqueda Binaria (importa si esta ordenado y como conozco la longitud puede ser por Burbujeo o por Selección): */

    // Y depaso Resolucion para el 8. En vez de suponer que esta ordenado de forma ascendente, lo ordenamos de forma ascendente.
    Ordenar(vector, n);

    MostrarVector(vector, n);

    posicion = BusquedaBinaria(vector, n, p);

    MostrarResultado(p, posicion);
    
}