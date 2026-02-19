/*
Realizar un programa que permtia guardar todos los alumnos que se encuentran inscriptos en las carreras de informatica de FIUBA (DNI, Nombre, Email, Sede)
*/

# include <stdio.h>
# include <string.h>

typedef struct {
    int dni;
    char nombre[35];
    char email[75];
    int sede;
} Talumno;

void CargarArchivo(FILE *archivo){ // El archivo se lo pasa como puntero (SIEMPRE)
    
    Talumno alumno;

    printf("Ingrese el dni del alumno (0 para finalizar): ");
    scanf("%i", &alumno.dni);
    fflush(stdin); // Para cada ingreso se usa fflush(stdin) mas que nada para los char

    while (alumno.dni != 0){
        printf("Ingrese el nombre del alumno (maximo 35 caracteres): ");
        scanf("%s", alumno.nombre);
        fflush(stdin);

        printf("Ingrese el email del alumno (maximo 75 caracteres): ");
        scanf("%s", alumno.email);
        fflush(stdin);

        printf("Ingrese la sede del alumno (1 PC, 2 LH): ");
        scanf("%i", &alumno.sede);
        fflush(stdin);

        fwrite (&alumno, sizeof(alumno), 1, archivo); // Escribimos el archivo (que ingrementa el contador del archivo en 1)

        // Volvemos a preguntar por el dni del alumno
        printf("Ingrese el dni del alumno (0 para finalizar): ");
        scanf("%i", &alumno.dni);
        fflush(stdin); // Para cada ingreso se usa fflush(stdin) mas que nada para los char 
    }

}

int main(){
    FILE *archivo; // Como son de tipo file, se declaran como puntero y despues ya se los usa normalmente
    archivo = fopen("alumnos2.dat", "wb"); // Siempre hay que abrir los archivos con una ruta (en este caso /..clase8/output) y el modo que queramos

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        CargarArchivo(archivo);
        fclose(archivo); // Una vez que hacemos lo que queremos cerramos el archivo
    }
    return 0;
}