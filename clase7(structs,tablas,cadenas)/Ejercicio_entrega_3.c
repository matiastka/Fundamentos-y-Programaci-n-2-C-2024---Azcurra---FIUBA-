/*
Escribir una función en C, que reciba una cadena de no más de 50 caracteres.
La función debe devolver la cantidad de vocales minúsculas, no acentuadas, que hay en la cadena recibida.
Escribe un programa que haga uso de la función y que la pruebe al menos con 5 casos, por ejemplo:
contar_vocales("El sol es una estrella")
mostrar por cada invocación el valor que devuelve. 
Definir un tipo adecuado para la cadena a utilizar.
*/

# include <stdio.h>

# include <string.h>

# define MF 50

typedef char Cadena[MF];

int contar_vocales(char cadena[]){ // Cadena como para parametro
    int cant_vocales, i; 
    
    cant_vocales = 0;

    for (i = 0; i < strlen(cadena); i++){
        if (cadena[i] != ' ' && (cadena[i] >= 'a' && cadena[i] <= 'z' && (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u'))) {
           cant_vocales++; 
        }
    }
    return cant_vocales;
}

void main(){
    Cadena cadena;
    int resultado;

    printf("Ingrese un texto de menos de %i caracteres: ", MF);
    fgets(cadena, MF, stdin); // Es el scanf de los strings

    fflush(stdin); // Limpia al buffer (stdin)

    resultado = contar_vocales(cadena);
    printf("La cantidad de vocales no acentuadas son: %i\n", resultado);

    resultado = contar_vocales("El sol es una estrella");
    printf("La cantidad de vocales no acentuadas son: %i\n", resultado);

    resultado = contar_vocales("Su talento llenará su corazón de alegria");
    printf("La cantidad de vocales no acentuadas son: %i\n", resultado);

    resultado = contar_vocales("Se bella voz han conmovido por generaciones");
    printf("La cantidad de vocales no acentuadas son: %i\n", resultado);
}