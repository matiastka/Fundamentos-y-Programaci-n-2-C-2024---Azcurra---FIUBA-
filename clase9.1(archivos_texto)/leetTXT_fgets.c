/*
Leemos una cadena de caracteres
Recibe la referencia a la cadena en donde dejar los datos leidos, la cant de bytes a leer y el puntero de tipo FILE.
Lee n-1 caracteres o hasta el fin de linea o hasta el fin de archivo 
*/

# include <stdio.h>
# define MAX 80

void main(){
    FILE *archivo;

    archivo = fopen("texto1.txt", "r");

    if (archivo == NULL){ // Si no fue exitosa la apertura indica el error
        printf("\nError de apertura del archivo\n");
    }
    else{
        char caracteres[MAX]; // Declaramos una cadena con una longitud especifica, en este caso de 80 caracteres

        while (feof(archivo) == 0){ // Recorremos hasta fin de archivo (es lo mismo a !feof(archivo))
            fgets(caracteres, MAX, archivo); // Vamos leyendo de a cadenas con fgets y lo que leemos del archivo con la longitud especificada se envia a la variable caracteres
            printf("%s\n", caracteres); // Imprimimos esa cadena
        }
        fclose(archivo);
    }
}