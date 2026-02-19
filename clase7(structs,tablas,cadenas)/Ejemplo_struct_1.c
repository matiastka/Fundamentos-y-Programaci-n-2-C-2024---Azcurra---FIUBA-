# include <stdio.h>
# include <string.h>

// Definimos una estructura alumno usando typedef (para no repetir el uso de struct cada vez que quiero incializar un registro)
typedef struct {
    char nombre[30];
    int padron;
    char email[50];
    int notas[2];
    float promedio;
} alumno; // Define el tipo de struct con los campos 

int main(void){
    alumno Alumno2; // Creamos la estructura/registro Alumno2 para hacerle inputs

    strcpy(Alumno2.nombre, "Enrique"); 
    Alumno2.padron = 12345;
    strcpy(Alumno2.email, "raulernesto.kay@hotmail.com" );
    Alumno2.notas[0] = 4; 
    Alumno2.notas[1] = 6; 
    Alumno2.promedio = (float) (Alumno2.notas[0] + Alumno2.notas[1])/2;

    printf("\n Alumno2: ");
    printf("\n El nombre: %s ", Alumno2.nombre);
    printf("\n El padron: %i ", Alumno2.padron);
    printf("\n El email: %s", Alumno2.email);
    printf("\n Nota del 1er parcial: %i Nota del 2do parcial: %i", Alumno2.notas[0], Alumno2.notas[1]);
    printf("\n El promedio es: %f\n", Alumno2.promedio);
}
