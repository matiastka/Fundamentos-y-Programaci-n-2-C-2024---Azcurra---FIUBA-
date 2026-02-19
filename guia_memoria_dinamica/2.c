/*
Escribir un programa el cual reserve memoria dinámica para almacenar una cierta cantidad de números enteros (n * int), este valor n debe ser ingresado porel usuario. 
Luego solicitarle que ingresé n valores enteros ingresados de a uno y almacenarlos en la memoria previamente reservada. Mostrar luego todos los valores ingresados. 
Liberar la memoria reservada al finalizar el programa.
*/

# include <stdio.h>
# include <stdlib.h>

void main(){
    int *puntero = NULL, cant_numeros, contador;

    printf("Ingrese la cantidad de numeros que va a ingresar: ");
    scanf("%i", &cant_numeros);

    puntero = malloc(cant_numeros * sizeof(int));

    if (puntero != NULL){ // Cargamos e imprimimos los numeros como si fuera un arreglo (haciendo puntero[i] para imprimir un valor y &puntero[i] si el valor cargado no es una cadena/arreglo)
        printf("Espacio de memoria reservado exitosamente\n");

        for (contador = 0; contador < cant_numeros; contador++){
            printf("Ingrese un numero: ");
            scanf("%i", &puntero[contador]); 
        }

        for (contador = 0; contador < cant_numeros; contador++){
            printf("El numero ingresado en la posicion %i es: %i\n", contador, puntero[contador]);
        }

        free(puntero); // Esto libera toda la memoria ocupada por el puntero que tendrá n espacios ocupados
        printf("Memoria Liberada");
    }
    else{
        printf("No se pudo reservar memoria");
    }
}