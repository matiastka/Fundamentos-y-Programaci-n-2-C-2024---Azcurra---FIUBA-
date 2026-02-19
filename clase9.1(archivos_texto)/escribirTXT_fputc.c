/* 
Este metodo permite escribir/grabar caracter a caracter
*/

# include <stdio.h>

void main(){
    FILE *archivo;
    archivo = fopen("texto2.txt", "a");
    char caracter;

    if (archivo == NULL){
        printf("Error de apertura");
    }
    else{
        printf("Ingrese un texto al archivo: ");

        caracter = getchar(); // Guarda el caracter (usamos la funcion getchar(), es parecida a scanf, solo que espera que el usuario ingrese un caracter y se lo da a la variable caracter)

        while( caracter != '\n'){ // Agrega caracter/es (uno a uno) hasta que se de enter
            fputc(caracter, archivo); // Se graba el caracter que se ingres
            caracter = getchar(); // Se vuelve a pedir otro caracter
        }
        fclose(archivo);
    }
}