/*
Lectura de un archivo caracter a caracter usando fgetc
char fgetc(FILE *nombre_archivo_logico)
Devuelve el caracter leido del archivo, apuntando por el punteor FILE o EOF si se encuentra al fin del archivo
*/
# include <stdio.h>

void main(){
    FILE *archivo; // Declaramos el archivo logico
    archivo = fopen("texto1.txt", "r"); // Abrimos el archivo

    if (archivo == NULL){ // Si no fue exitosa la apertura indica el error
        printf("\nError de apertura del archivo\n");
    }
    else{ // Si fue exitosa
        char caracter;

        caracter = fegtc(archivo); // Leemos el archivo caracter a caracter con fgetc(archivo). Inicia el 'contador' del archivo 

        while (caracter != EOF){ // Mientras no se llegue al fin de archivo (que es EOF)
            printf("%c", caracter); // Imprime el caracter
            caracter = fgetc(caracter); // Avanza dentro de la lectura del archivo, avanza el 'contador' del archivo para leer el siguiente
        }
        fclose(archivo);
    }
}