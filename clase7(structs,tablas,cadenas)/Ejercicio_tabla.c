#include <stdio.h>
#include <stdlib.h>

#define TAMANIO 3 // 

/* definimos una estructura alumno */
typedef struct  
{
     char nombre[30];
     int padron;
     char email[50];
     int notas[2] ; // Esto quiere decir que se van a guardar 2 enteros 
     float promedio;
} alumno;

void mejor_promedio(alumno vec[TAMANIO]){
    int i, posicion_del_mayor_promedio;
    float mayor_promedio;
    
    posicion_del_mayor_promedio = 0;

    mayor_promedio = vec[0].promedio;

    for(i = 0; i < TAMANIO; i++) {
        if (vec[i].promedio > mayor_promedio){
            mayor_promedio = vec[i].promedio;
            posicion_del_mayor_promedio = i;
        }
    }
    printf("\nEl alumno con mayor promedio es: %s\n", vec[posicion_del_mayor_promedio].nombre);
}

void promedio_general(alumno vec[TAMANIO]){
    int i;
    float promedio_general_1er_parcial, suma;

    promedio_general_1er_parcial = 0;
    suma = 0;

    for (i = 0; i < TAMANIO; i++){
        suma = suma + vec[i].notas[0]; // Se para en las notas del 1er parcial
    }
    promedio_general_1er_parcial = suma/i; //Castear a float
    printf("El promedio general del 1er parcial es: %f", promedio_general_1er_parcial);
}

void ordenar_padron(alumno vec[TAMANIO]){ //Uso ordenamiento por burbujeo (para tablas)
    int i, j;
    alumno aux[TAMANIO];

    for (i = 1; i < TAMANIO; i++){
        for (j = 0; j < TAMANIO-i; j++){
            if (vec[j].padron > vec[j+1].padron){ //Ordenamos de forma ascendente
                aux[j] = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux[j];  
            }
        }
    }
}

void busqueda_binaria(){

}

void cargar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",vec[i].nombre); // Recomendado usar fgets pero se muestra con scanf por la gente que no vio el video

        printf("Ingrese el padron:\n");
        scanf("%d",&vec[i].padron);

        printf("Ingrese el email:\n");
        scanf("%s",vec[i].email);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&vec[i].notas[1]);

	vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
    }
}

void mostrar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
 	printf("\n\n Alumnos[%d]",i);
	printf("\n nombre: %s ", vec[i].nombre);
	printf("\n padron: %d ", vec[i].padron);	
	printf("\n email: %s ", vec[i].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
	printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

int main(void)
{
    alumno Alumnos[TAMANIO];

    // cargo los elementos con funcion cargar
    cargar(Alumnos);

 	/* Muestro datos del primer elemento de la tabla*/
    
    //mostrar(Alumnos);

    mejor_promedio(Alumnos);

    promedio_general(Alumnos);

    ordenar_padron(Alumnos);

    mostrar(Alumnos);

	printf("\n\n");
	return 0;
}