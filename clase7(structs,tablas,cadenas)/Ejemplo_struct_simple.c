# include <stdio.h>
# include <string.h>

// Definimos una estructura alumno
struct alumno{
    char nombre[30]; // Como es de tipo char, marcó el máximo de bytes que va a tener el campo nombre.
    int padron;
    char email[50];
    int notas[2]; // Como es de tipo int, el [2] quiere decir que se pueden cargar como mucho 2 notas para ese campo
    float promedio;
} Alumno1 = /* Incializamos la estructura */ {
    "Miguel Lopez", // nombre
    23251, // padron
    "mloprez@gmail.com", //email
    {8,7}, // notas
    7.5 // promedio
};

int main(void){
    struct alumno Alumno2; // Creamos la estructura Alumno2 para hacerle inputs

    strcpy(Alumno2.nombre, "Enrique"); // A la estructura Alumno2 al campo nombre se le guarda Enrique (como es un string se hace con strcpy)
    Alumno2.padron = 12345;
    strcpy(Alumno2.email, "raulernesto.kay@hotmail.com" );
    Alumno2.notas[0] = 4; // Guardamos la 1er nota
    Alumno2.notas[1] = 6; // Guardamos la 2da nota
    Alumno2.promedio = (float) (Alumno2.notas[0] + Alumno2.notas[1])/2;

    // Para imprimir los datos de Alumno1:
    printf("\n Alumno1: ");
    printf("\n El nombre: %s ", Alumno1.nombre);
    printf("\n El padron: %i ", Alumno1.padron);
    printf("\n El email: %s", Alumno1.email);
    printf("\n Nota del 1er parcial: %i Nota del 2do parcial: %i", Alumno1.notas[0], Alumno1.notas[1]);
    printf("\n El promedio es: %f\n", Alumno1.promedio);

    // Para imprimir los datos de Alumno2:
    printf("\n Alumno2: ");
    printf("\n El nombre: %s ", Alumno2.nombre);
    printf("\n El padron: %i ", Alumno2.padron);
    printf("\n El email: %s", Alumno2.email);
    printf("\n Nota del 1er parcial: %i Nota del 2do parcial: %i", Alumno2.notas[0], Alumno2.notas[1]);
    printf("\n El promedio es: %f\n", Alumno2.promedio);
}
