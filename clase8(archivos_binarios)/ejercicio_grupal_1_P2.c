/*
Realizar un programa que permita mostrar todos los alumnos que se encuentran inscriptos en las carreras de informatica de FIUBA (DNI, Nombre, Email, Sede))
*/
# include <stdio.h>
# include <string.h>
# define MAX_NOM 100

typedef char string[MAX_NOM];

typedef struct {
    int DNI;
    string Nombre;
    string Email;
    int Sede;
} Tregistro;

void Mostrar(FILE *archivo){
    
    Tregistro alumno; // Definimos alumno como un struct de los campos de Tregistro

    fread(&alumno, sizeof(alumno), 1, archivo);

    printf("\nDNI\t\tNombre\t\tEmail\t\t\tSede\n"); // Encabezado

    while ( !feof(archivo) ){ // Mientras no se llegue al final de linea
        printf("%i\t%s\t%s\t%i\n", alumno.DNI, alumno.Nombre, alumno.Email, alumno.Sede);
        fread(&alumno, sizeof(alumno), 1, archivo);
    }
}

void main(){
    FILE *archivo;

    archivo = fopen("alumnos.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        Mostrar(archivo);
        fclose(archivo);
    }
}