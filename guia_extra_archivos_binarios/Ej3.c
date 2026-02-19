/*
Dada la siguiente estructura:

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

Escribir un programa que permita almacenar y consultar datos en un archivo de alumnos.
El programa deberá tener 2 opciones:
1 - Cargar Datos Alumnos
2 - Listar Alumnos

Los datos que se guardan de los alumnos son los indicados en la estructura inicial.
La carga de datos, termina cuando el padron ingresado sea 0.
La carga de datos, puede reanudarse, y en este caso no se deben perder los datos existentes.
El listado debe ser de todos los datos, encolumnados, y en el orden que se encuentran almacenados.
*/

# include <stdio.h>
# include <string.h>
# include <stdbool.h>

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
} Talumno;

void ValidarOpciones(int *numero){
	printf("Ingrese la opcion que desea usar (1 para Cargar Datos, 2 para Mostrar/Listar o -1 para finalizar): ");
	scanf("%i", numero);

	while ((*numero != 1) && (*numero != 2) && (*numero != -1)){
		printf("Ingrese la opcion que desea usar (1 para Cargar Datos, 2 para Mostrar/Listar o -1 para finalizar): ");
		scanf("%i", numero);
	}
}

void CargarArchivo(FILE *archivo){
	Talumno alumno;

	printf("Ingrese el padron del alumno (0 para finalizar): ");
	scanf("%i", &alumno.padron);
	fflush(stdin);

	while (alumno.padron != 0){
		printf("Ingrese el nombre del alumno (30 caracteres como maximo): ");
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

void MostrarArchivo(FILE *archivo){
	Talumno alumno;

	fread(&alumno, sizeof(alumno), 1, archivo); // Leemos el archivo para iniciar su contador

	printf("Padron\tNombre y Apellido\tNota\n"); // Encabezado

	while (!feof(archivo)){ // Mientras no llegue al final del archivo
		printf("%i\t%s\t\t%f\n", alumno.padron, alumno.ape_nom, alumno.nota); // Imprime los datos del archivo en esa posicion con la estructura Talumno
		fread(&alumno, sizeof(alumno), 1, archivo); // Volvemos a leer el archivo para avanza su contador de a 1
	}
}

void main(){
	FILE *archivo; // Definimos un archivo logico
	int opciones; 
	bool creado_por_primera_vez;

	ValidarOpciones(&opciones);
	creado_por_primera_vez = false;
	
	while (opciones != -1){
		if (opciones == 1){
			if (creado_por_primera_vez ==  false){ // Si el archivo no fue creado lo abre en modo w (write)
				archivo = fopen("alumnos.dat", "wb");
			}
			else{ // Si el archivo ya fue creado lo abre en modo a (append)
				archivo = fopen("alumnos.dat", "ab");
			}
			
			if (archivo == NULL){ // SI falla avisa
				printf("No se pudo abrir el archivo\n");
			}
			else{ // Sino falla
				creado_por_primera_vez = true; // Declara que fue creado
				CargarArchivo(archivo); 
				fclose(archivo); // Cerramos el archivo
			}
		}
		else{
			archivo = fopen("alumnos.dat", "rb");
			if (archivo == NULL){
				printf("No se pudo abrir el archivo\n");
			}
			else{
				MostrarArchivo(archivo);
				fclose(archivo);
			}
		}
		
		ValidarOpciones(&opciones);
	}
}