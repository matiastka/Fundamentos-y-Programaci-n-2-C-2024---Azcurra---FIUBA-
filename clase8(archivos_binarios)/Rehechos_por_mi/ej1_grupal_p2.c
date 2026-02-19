/*
Realizar un programa que permtia mostrar todos los alumnos que se encuentran inscriptos en las carreras de informatica de FIUBA (DNI, Nombre, Email, Sede))
*/

# include <stdio.h>
# include <string.h>

typedef struct{
    int dni;
    char nombre[35];
    char email[75];
    int sede;
} Talumno;

void MostrarArchivo(FILE *archivo){

    Talumno alumno;

    fread(&alumno, sizeof(alumno), 1, archivo); // Primero leemos el archivo para que incie a leer la 1ra linea e incie el contador del archivo en 0

    // Encabezado
    printf("\nDNI\t\tNombre\t\tEmail\t\t\tSede\n");

    while ( !feof(archivo) ){ // Mientras no se llegue a fin de linea
        printf("%i\t%s\t%s\t%i\n", alumno.dni, alumno.nombre, alumno.email, alumno.sede);
        fread(&alumno, sizeof(alumno), 1, archivo); // Volvemos a leer el archivo para que avance el contador del archivo
    }

}

int main(){
    FILE *archivo;

    archivo = fopen("alumnos2.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarArchivo(archivo);
        fclose(archivo);
    }
    return 0;
}
