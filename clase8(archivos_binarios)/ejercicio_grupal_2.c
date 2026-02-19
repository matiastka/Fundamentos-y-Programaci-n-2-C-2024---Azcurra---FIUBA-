/*
Generar 1 archivo independiente por cada una de las 2 sedes "PaseoColon" y "LasHeras" considerando como sede 1 Paseo Colon y sede 2 Las Heras
*/

# include <stdio.h>
# include <string.h>

# define MAX_CHAR 100

typedef char string[MAX_CHAR];

typedef struct {
    int DNI;
    string Nombre;
    string Email;
    int Sede;
} Tregistro;

void Dividir(FILE *archivo, FILE *sede1, FILE *sede2){
    Tregistro alumno;

    fread(&alumno, sizeof(alumno), 1, archivo); // Leemos el archivo (del archivo pasamos los datos al registro)

    while( !feof(archivo) ){ //Mientras el 'contador' del archivo no llegue al final
        if (alumno.Sede == 1){ // Si la sede es 1
            fwrite(&alumno, sizeof(alumno),1, sede1); // Escribimos dicho registro al archivo sede1
        }
        else{
            fwrite(&alumno, sizeof(alumno), 1, sede2); // Escribimos dicho registro al archivo sede2
        }
        fread(&alumno, sizeof(alumno), 1, archivo); // Leemos el archivo de nuevo para que siga aumentando el 'contador' (puntero) del archivo
    }
}

int main(){
    FILE *Archivo, *sede1, *sede2;

    Archivo = fopen("alumnos.dat", "rb");
    sede1 = fopen("PaseoColon.dat", "wb");
    sede2 = fopen("LasHeras.dat", "wb");

    if (Archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        Dividir(Archivo, sede1, sede2);
        fclose(Archivo);
        fclose(sede1);
        fclose(sede2);
    }
    return 0;
}

