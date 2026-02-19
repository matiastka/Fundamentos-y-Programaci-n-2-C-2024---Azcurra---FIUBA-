/*
Ejemplo de uso de malloc() y free() para reservar de espacio de memoria para almacenar 4 valores enteros, asignando los valores al espacio reservado con artimética de punteros 
(para recorrer con un for ver ejemplo 04)
*/

#include <stdio.h>
#include <stdlib.h>

void main() {
    // 1. Declaramos un puntero para almacenar la dirección de inicio del espacio que vamos a reservar
    int *enteros = NULL;

    // 2. Reservamos el espacio usando la función malloc que nos devuelve la dirección de inicio
    int cantidad_enteros = 4;
    enteros = malloc(cantidad_enteros * sizeof(int));

    // 3. Evaluamos si la reserva del espacio fue existosa
    if (enteros != NULL) {
        printf("Espacio de memoria reservado exitosamente.\n");

        // 4. Asignamos valores al espacio reservado, usando aritmética de punteros
        *enteros = 100; // al 1er espacio de tamaño de un entero, le asignamos 100
        *(enteros + 1) = 200; // al 2do espacio de tamaño de un entero, le asignamos 200
        *(enteros + 2) = 300; // al 3er espacio de tamaño de un entero, le asignamos 300
        *(enteros + 3) = 400; // al 4to espacio de tamaño de un entero, le asignamos 400

        // 5. Mostramos los valores almacenados con su respectva dirección
        printf("Direccion: H:%x Valor en 1er. posicion:%d \n", enteros, *enteros);
        printf("Direccion: H:%x Valor en 2da. posicion:%d \n", enteros + 1, *(enteros + 1));
        printf("Direccion: H:%x Valor en 3ra. posicion:%d \n", enteros + 2, *(enteros + 2));
        printf("Direccion: H:%x Valor en 4ta. posicion:%d \n", enteros + 3, *(enteros + 3));

        free(enteros);
    }
    else
        printf("Error al reservar espacio de memoria.");
    return;
}