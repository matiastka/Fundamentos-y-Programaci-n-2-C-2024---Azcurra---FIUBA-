/*
Dada la siguiente estructura:

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

Escriba un programa modular que permita listar el contenido del archivo creado en el punto 1.

*/

# include <stdio.h>
# include <string.h>

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
} Talumno;

void MostrarArchivo(FILE *archivo){
	Talumno alumno;

	fread(&alumno, sizeof(alumno), 1, archivo); // Leemos el archivo para poder inicializar su contador

	printf("Padron\tApellido y Nombre\tNota\n"); // Escribimos el encabezado

	while ( !feof(archivo) ){ // Mientras no se llegue al fin del archivo
		printf("%i\t%s\t\t%f\n", alumno.padron, alumno.ape_nom, alumno.nota); // Imprimimos los datos del archivo con el formato de la estrucutra Talumno
		fread(&alumno, sizeof(alumno), 1, archivo); // Leemos el archivo para poder avanzar el contador del mismo de a 1
	}
}

void main(){
	FILE *archivo;

	archivo = fopen("archivo.dat", "rb");

	if (archivo == NULL){
		printf("El archivo no se pudo abrir");
	}
	else{
		MostrarArchivo(archivo);
		fclose(archivo);
	}
}