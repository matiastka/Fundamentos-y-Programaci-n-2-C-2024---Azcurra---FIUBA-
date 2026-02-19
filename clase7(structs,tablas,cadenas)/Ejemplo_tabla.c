// Hacemos lo mismo que el ejemplo tabla_simple solo que mucho mejor y esta vez recorremos toda la tabla para poder agregar cada registro

# include <stdio.h>
# include <string.h>

# define TAMANIO 3

typedef struct {
    char nombre[30];
    int padron;
    char email[50];
    int notas[2];
    float promedio;
} alumno;

void Cargar(alumno vec[TAMANIO]){ // No olvidar de poner los & para los scanf que no son arreglos
    int i;
    for (i = 0; i < TAMANIO; i++){
        printf("\nCargando Alumno %i (Alumnos[%i])", i+1, i); //i+1 es #cantidad de alumno e i es el contador/posicion
        printf("\n Ingrese el nombre (sin espacios, use guion o guion bajo): ");
        scanf("%s", vec[i].nombre);

        printf("\n Ingrese el padron: ");
        scanf("%i", &vec[i].padron);

        printf("\n Ingrese el email: ");
        scanf("%s", vec[i].email);

        printf("\n Ingrese la 1er nota: ");
        scanf("%i", &vec[i].notas[0]);

        printf("\n Ingrese la 2da nota: ");
        scanf("%i", &vec[i].notas[1]);

        vec[i].promedio = (float) (vec[i].notas[0] + vec[i].notas[1]/2);
    }
}

void Mostrar(alumno vec[TAMANIO]){
    int i;
    for (i = 0; i < TAMANIO; i++){
        printf("\nMostrando Alumno %i (Alumnos[%i])", i+1, i);
        printf("\nEl nombre es: %s ", vec[i].nombre);
        printf("\nEl padron es: %i ", vec[i].padron);
        printf("\nEl email es: %s ", vec[i].email);
        printf("\nLa nota del 1er parcial es: %i ", vec[i].notas[0]);
        printf("\nLa nota del 2do parcial es: %i ", vec[i].notas[1]);
        printf("\nEl promedio es: %f\n ", vec[i].promedio);
    }
}

int main(void){
    alumno Alumnos[TAMANIO];

    // Cargamos los elementos/registros con una funcion a la tabla
    Cargar(Alumnos);

    // Mostramos los datos que tiene dicha tabla
    Mostrar(Alumnos);

    return 0;
}

