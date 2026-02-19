// Generar 1 archivo independiente por cada una de las 2 sedes "PaseoColon" y "LasHeras" considerando como sede 1 Paseo Colon y sede 2 Las Heras

# include <stdio.h>
# include <string.h>

typedef struct {
    int dni;
    char nombre[35];
    char email[75];
    int sede;
} Talumno;

void DividirArchivo(FILE *archivo, FILE *sede1, FILE *sede2){

    Talumno alumno;

    fread(&alumno, sizeof(alumno), 1, archivo); // Recordar que primero leemos el archivo para que el contador del mismo empiece...

    while (!feof(archivo)){ // Mientras no se llegue al fin de linea del archivo
        if (alumno.sede == 1){
            fwrite(&alumno, sizeof(alumno), 1, sede1);
        }
        if (alumno.sede == 2){
            fwrite(&alumno, sizeof(alumno), 1, sede2);
        }
        fread(&alumno, sizeof(alumno), 1, archivo); // ... y volvemos a leer para que el mismo avance
    }
}

void main(){
    FILE *archivo;
    FILE *sede1;
    FILE *sede2;

    archivo = fopen("alumnos2.dat", "rb");
    sede1 = fopen("PaseColon2.dat", "wb");
    sede2 = fopen("LasHeras2.dat", "wb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        DividirArchivo(archivo, sede1, sede2);
        // Siempre hay que cerrar todos los archivos abiertos una vez trabajados con ellos
        fclose(archivo);
        fclose(sede1);
        fclose(sede2);
    }
}