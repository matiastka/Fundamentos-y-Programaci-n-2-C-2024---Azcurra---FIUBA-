/*
Modificá el programa del ejercicio anterior para que en lugar de inicializar la cadena con tu nombre y apellido, solicite el ingreso del mismo.
No pierdas la solución realizada para el ejercicio anterior, generá una nueva versión para la solución de este ejercicio.
*/

# include <stdio.h>
# include <string.h>

# define MF 40

void main(){
    char cadena[MF];

    printf("Ingrese su nombre y apellido: ");
    fgets(cadena, MF, stdin); // Es el scanf de los strings

    fflush(stdin); // Limpia al buffer (stdin)

    int i, cant_consonantes;
    
    cant_consonantes = 0;

    for (i = 0; i < strlen(cadena); i++){
            if (cadena[i] != ' ' && ((cadena[i] >= 'A' && cadena[i] <= 'Z' && (cadena[i] != 'A' && cadena[i] != 'E' && cadena[i] != 'I' && cadena[i] != 'O' && cadena[i] != 'U')) || (cadena[i] >= 'a' && cadena[i] <= 'z' && (cadena[i] != 'a' && cadena[i] != 'e' && cadena[i] != 'i' && cadena[i] != 'o' && cadena[i] != 'u')))) { 
            printf("%c\n", cadena[i]);
            cant_consonantes++;
        }
    }
    printf("La cantidad de consonantes que tiene %ses: %i", cadena, cant_consonantes);
}