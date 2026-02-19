/* 

Ingresar las notas de los alumnos del curso de Algoritmos y programación 1 (finalizar la carga ingresando cero) 
y luego mostrar la cantidad de alumnos que aprobaron, considerando la nota de aprobación igual o mayor a cuatro.

notas: 
	- almacenar las notas en un vector, considerar un máximo fisico adecuado.
	- hacer un adecuado uso del máximo lógico
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 120
#define NOTA_MIN 4

typedef int TVnum[MAX];

void carga_datos(TVnum vnum, int *ml) {
	int i=0, nota;
	printf("Ingrese nota (0 para finalizar): \n");
	scanf("%d", &nota);
	
	while (nota != 0 && i<MAX) {
		vnum[i]=nota;
		i++;

		printf("Ingrese nota (0 para finalizar): ");		
		scanf("%d", &nota);
	}

	*ml = i;
}

int cantidad_aprobados(TVnum vnum, int ml) {
	int cant=0, i;

	for (i=0; i<ml; i++)	
		if (vnum[i] >= NOTA_MIN)
			cant++;
	return cant;
}

int main() {
	TVnum notas;
	int ml;

	// carga de ntotas
	carga_datos(notas, &ml);
	printf("La cantidad de aprobados es: %d \n", cantidad_aprobados(notas, ml));

	return 0;
}

