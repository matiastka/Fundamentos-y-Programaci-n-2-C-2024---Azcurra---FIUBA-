/*
fputs() permite grabar/escirbir una cadena completa
*/

# include <stdio.h>

# define MAX 100

void main(){
    FILE *archivo;
    archivo = fopen("texto2.txt", "a"); // Abrimos al final del archivo para no pisar los datos que ya tenia (hacemos append porque por el metodo secuencial no queremos editar los datos ya existentes)
    char cadena[MAX];

    if (archivo == NULL){
        printf("Error de apertura del archivo");
    }
    else{
        printf("Ingrese un texto para agregar al archivo: ");
        fgets(cadena, MAX, stdin); // Guarda la cadena en la variable cadena con su respectivo maximo y con stdin actualizado

        if (fputs(cadena, archivo) == 0){ // Si se actualizo el archivo, fputs devuelve 0
            printf("\nEl archivo fue actualizado");
        }
        else{ // Sino no pudo
            printf("\nNo fue posible agregar el texto al archivo");
        }
        fclose(archivo);
    }
}   