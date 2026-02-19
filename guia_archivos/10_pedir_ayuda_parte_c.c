/*
Una escuela tiene en el archivo ARCHIVO.DAT, los siguientes datos de sus alumnos: NOMBRE, AÑO, DIVISION, PROMEDIO GENERAL. 
El archivo está ordenado en forma creciente por año y división. 
Se pide:
a) Imprimir un listado por año y división con los nombres de los alumnos y sus promedios
b) Informar, al final del proceso, el nombre del alumno de mejor promedio de la escuela
c) Grabar en un archivo los siguientes datos de cada año y división: AÑO, DIVISION, CANTIDAD DE ALUMNOS 
*/

# include <stdio.h>
# include <string.h>
# define MAX 5

typedef struct{
    char nombre[35];
    int anio;
    char division;
    float promedio;
}Talumno;

typedef Talumno Tvecalumnos[MAX]; // Para definir una tabla con los structs de los alumnos se le pone un MAX (para que entre en memoria)

// a) y b) (parte c ni idea)
void MostrarAlumnosOrdenadosporAnioyDivision(FILE *archivo){
    Talumno alumno;

    float mejor_promedio;
    char mejor_alumno[35];

    mejor_promedio = -1; // Incializamos el promedio fuera del rango

    fread(&alumno, sizeof(alumno), 1, archivo);

    printf("Nombre\tAnio\tDivision\tPromedio General"); // Encabezado

    while (!feof(archivo)){
        printf("%s\t%i\t%s\t%f", alumno.nombre, alumno.anio, alumno.division, alumno.promedio);

        if (alumno.promedio > mejor_promedio){ // Si el campo promedio es mayor a mayor_promedio entonces:
            mejor_promedio = alumno.promedio;
            strcpy(mejor_alumno, alumno.nombre); // Asigna a la variable mejor_alumno el nombre del alumno (como es string no se hace directamente)
        }
        fread(&alumno, sizeof(alumno), 1, archivo);

    }
    printf("El nombre del alumno con mejor promedio en la escuela es: %s", mejor_alumno);
}

void main(){
    FILE *archivo;

    archivo = fopen("ARCHIVO.DAT", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarAlumnosOrdenadosporAnioyDivision(archivo);
        fclose(archivo);
    }
}