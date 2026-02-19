// Uso de strcat: concatenar un valor a la cadena existente.

# include <stdio.h>
# include <string.h>

void main(){
    char cadena1[15] = "Hola";
    char cadena2[] = "Mundo";
    char cadena3[] = " " ;

    // Concateno valores a la cadena1, usando strcat(cadena_a_modificar, cadena_a_concatenar)
    // La longitud maxima de cadena1 debe ser suficente para recbiir todas las nuevas concatenaciones que queramos hacer. No se puede superar la #bytes reservados

    strcat(cadena1, cadena3); // esto modifica a cadena 1 y le suma cadena 3 --> cadena1 va a ser: Hola + " "
    strcat(cadena1, cadena2); // esto modifica a cadena 1 y le suma cadena 2 --> cadena1 va a ser: (Hola + " ") + Mundo
    printf("En cadena1 asigno Cadena1 + Cadena3 + Cadena2: %s \n\n", cadena1);

    return;
}