/*
fprintf() permite grabar/escribir una cadena completa (recomendado usar)
*/

# include <stdio.h>

# define MAX 100

void main(){
    FILE *archivo;
    archivo = fopen("texto2.txt", "a");
    
    if (archivo == NULL){
        printf("Error de apertura del archivo");
    }
    else{
        char cadena[MAX];
        int cant_caracteres;

        cant_caracteres = 0;

        printf("Ingrese el texto a agregar al archivo: ");
        fgets(cadena, MAX, stdin); // Guarda la cadena en la variable cadena con su respectivo maximo y con stdin actualizado

        cant_caracteres = fprintf(archivo, "\n%s", cadena); //fprintf() recibe al archivo_logico luego el formato de la cadena a grabar y finalmente la variable de la cadena. fprintf() devuelve la cant de caracteres que se grabaron

        printf("\nSe escribieron %i caracteres\n", cant_caracteres);

        fclose(archivo);
    }
}