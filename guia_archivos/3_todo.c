/*
Dado un archivo de números enteros entre 0 y 255, imprimir los caracteres correspondientes según el código ASCII. 
*/

# include <stdio.h>
# include <string.h>

# define MAX 100

void CargarArchivo(FILE *archivo){
    char cadena[MAX];
    int cant_caracteres;

    cant_caracteres = 0;

    printf("Ingrese el texto a agregar al archivo: ");
    fgets(cadena, MAX, stdin); // Guarda la cadena en la variable cadena con su respectivo maximo y con stdin actualizado

    cant_caracteres = fprintf(archivo, "\n%s", cadena); //fprintf() recibe al archivo_logico luego el formato de la cadena a grabar y finalmente la variable de la cadena. fprintf() devuelve la cant de caracteres que se grabaron

    printf("\nSe escribieron %i caracteres\n", cant_caracteres);
}

void MostrarArchivo_1(FILE *archivo){ // Mostramos un archivo de texto (usando fscanf)
    char cadena[MAX];
    fscanf(archivo, "%s", cadena); // Leemos el archivo y guardamos la cadena en esa linea

    while (!feof(archivo)){
        printf("%s\n", cadena); // Imprimimos la cadena
        fscanf(archivo, "%s", cadena); // Avanzamos en la lectura del archivo ('su contador')
    }
}

void MostrarArchivo(FILE *archivo){ // Mostramos un archivo de texto (usando fgets)
    char cadena[MAX];

    while (!feof(archivo)){
        fgets(cadena, MAX, archivo);
        printf("%s", cadena); // Imprimimos la cadena
    }
}

void main(){
    FILE *archivo;
    
    archivo = fopen("archivo_eje3.txt", "a");
    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        CargarArchivo(archivo);
        fclose(archivo);
    }
        
    archivo = fopen("archivo_eje3.txt", "r");
    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarArchivo(archivo);
        fclose(archivo);
    }
}