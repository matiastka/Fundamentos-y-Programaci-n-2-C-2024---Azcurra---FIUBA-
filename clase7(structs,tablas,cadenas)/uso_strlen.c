// Uso de strlen: Longitud de la cadena
# include <stdio.h>
# include <string.h> // para strlen hay que importar la bibloteca

void main(){
    char cadena1[10] = "Hola"; // Incializamos la cadena 1 con máximo de 10 bytes y le asignamos "Hola"
    char cadena2[] = "Mundo"; // Incializamos la cadena2 sin un maximo (el maximo será el largo del string dado)
    char cadena3[] = " "; // Incializamos la cadena3 con un espacio en blanco

    // Muestro contenido y longitud de las cadenas usando strlen(cadena)
    printf("Cadena1: %s \t tiene: %i caracteres \n", cadena1, strlen(cadena1)); // \t es un tabeo de espacio
    printf("Cadena1: %s \t tiene: %i caracteres \n", cadena2, strlen(cadena2));
    printf("Cadena1: %s \t tiene: %i caracteres \n", cadena3, strlen(cadena3));

    return;
}