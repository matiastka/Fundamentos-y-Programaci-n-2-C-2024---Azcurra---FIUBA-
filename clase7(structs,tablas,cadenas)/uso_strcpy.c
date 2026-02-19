// Uso de strcpy: asignar un nuevo valor a la cadena

# include <stdio.h>
# include <string.h>

void main(){
    char cadena1[10] = "Hola";

    // Le asigno un nuevo valor a la cadena usando strcpy(destino, fuente)
    // Debo tener en cuenta cual es la longitud maxima de la cadena
    strcpy(cadena1, "Chau"); // A cadena1 le asigno Chau. Ojo con exceder el maximo de bytes de la cadena
    printf("\n Ahora Cadena1 vale: %s \n\n", cadena1);
    
    return;
}