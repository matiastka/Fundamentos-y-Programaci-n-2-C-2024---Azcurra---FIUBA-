# include <stdio.h>

# define MAX 40

void main(){
    FILE *archivo;

    archivo = fopen("texto1.txt", "r");

    if (archivo == NULL){ // Si no fue exitosa la apertura indica el error
        printf("\nError de apertura del archivo\n");
    }
    else{
        char cadena[MAX];
        fscanf(archivo, "%s", cadena);  // Leemos la cadena en el archivo (usando el archivo como origen), nos permite leer cadenas o caracteres

        while( feof(archivo) == 0){ // Es lo mismo a escribir !feof(arcihvo)
            printf("%s\n", cadena); // Imprimimos la cadena
            fscanf(archivo, "%s", cadena); // Seguimos leyendo el archivo
        }
        fclose(archivo);
    }
}