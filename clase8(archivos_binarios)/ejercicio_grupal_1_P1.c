/*
Realizar un programa que permtia guardar todos los alumnos que se encuentran inscriptos en las carreras de informatica de FIUBA (DNI, Nombre, Email, Sede)
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

void Cargar(FILE *archivo){
    
    Tregistro alumno; // Definimos alumno como un struct de los campos de Tregistro

    printf("Ingrese el DNI del alumno (0 para finalizar): ");
    scanf("%i", &alumno.DNI);
    fflush(stdin); // Se hace fflush por estar cargando datos a un archivo (ver 01_cargarArchivos)
    
    while (alumno.DNI != 0){
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", alumno.Nombre);
        fflush(stdin); 

        printf("Ingrese el mail del alumno: ");
        scanf("%s", alumno.Email);
        fflush(stdin);

        printf("Ingrese la sede del alumno (1 PH y 2 LH): ");
        scanf("%i", &alumno.Sede);
        fflush(stdin);

        fwrite(&alumno, sizeof(alumno), 1, archivo); // Escribimos el struct recien ingresado al archivo y avanza el puntero dentro del archivo (su contador interno) [esto es una mentira, es para que lo entendamos nosotros]
        
        printf("Ingrese el DNI del alumno (0 para finalizar): ");
        scanf("%i", &alumno.DNI);
        fflush(stdin);
    }
}

int main(){
    FILE *Archivo;

    Archivo = fopen("alumnos.dat", "wb");

    if (Archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        Cargar(Archivo);
        fclose(Archivo);
    }
    return 0;
}