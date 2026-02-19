/*
Dada la siguiente estructura:

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

Escriba un programa modular que permita dar de alta registros de tipo t_regAlumno.
El usuario debe poder continuar ingresando datos hasta que ingrese un padron igual a 0.
Asuma que el archivo es inexistente.

*/

# include <stdio.h>
# include <string.h>

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
} Talumno;

void CargarArchivo(FILE *archivo){
	Talumno alumno;

	printf("Ingrese el padron del alumno (0 para finalizar): ");
	scanf("%i", &alumno.padron);
	fflush(stdin);

	while (alumno.padron != 0){
		printf("Ingrese el nombre y apellido del alumno (maximo 35 caracteres): ");
		scanf("%s", alumno.ape_nom);
		fflush(stdin);

		printf("Ingrese la nota del alumno: ");
		scanf("%f", &alumno.nota);
		fflush(stdin);

		fwrite(&alumno, sizeof(alumno), 1, archivo);

		printf("Ingrese el padron del alumno (0 para finalizar): ");
		scanf("%i", &alumno.padron);
		fflush(stdin);
	}
}

void main(){
	FILE *archivo;

	archivo = fopen("archivo.dat", "wb");

	if (archivo == NULL){
		printf("El archivo no se pudo abrir");
	}
	else{
		CargarArchivo(archivo);
		fclose(archivo);
	}
}
