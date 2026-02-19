// Uso de strstr: Buscar una cadena dentro de otra cadena

# include <stdio.h>
# include <string.h>

void main(){
    char cadena1[10] = "Mundo";
    char cadena2[] = "Hola Mundo";

    // Busco si en la cadena2 existe la cadena1, usando strstr(cadena_a_analizar, cadena_a_buscar).
    // strstr devuelve un puntero al comienzo de la cadena buscada, si una se encuentra dentro de otra. Sino devuelve NULL

    char *posicion; // Definimos al puntero posicion que es un char

    posicion = strstr(cadena2, cadena1); // Se fija en la cadena2 si existe la cadena 1
    if (posicion == NULL){ // Sino existe entonces el puntero devuelve NULL
        printf("La cadena1: %s no existe en la cadena2: %s", cadena1, cadena2);
    }
    else{ // Si existe devuelve un puntero que a punta a la M de "Mundo"
        printf("La cadena1 (%s) esta en la cadena2 (%s)..!\n", cadena1, cadena2);
    }
    
    return;
}