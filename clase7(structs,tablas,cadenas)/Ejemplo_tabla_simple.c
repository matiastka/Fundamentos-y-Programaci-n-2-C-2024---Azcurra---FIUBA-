# include <stdio.h>
# include <string.h>

// Defininimos una estructura alumno (de forma estandar [a partir de ahora la vamos a definir asi])
typedef struct {
    char nombre[30];
    int padron;
    char email[50];
    int notas[2];
    float promedio;
} alumno;

int main(void){
    alumno Alumnos[3]; // Creamos la tabla Alumno con 3 registros (es igual a definir un registro solo que le ponemos la su nombre[#registros que tiene])

    // Cargamos el 1er alumno:
    strcpy(Alumnos[0].nombre, "Miguel Lopez"); // Alumnos[0] se para en la 1er posicion de la tabla que sería el 1er registro.
    Alumnos[0].padron = 23251;
    strcpy(Alumnos[0].email, "mloprez@gmail.com");
    Alumnos[0].notas[0] = 8;
    Alumnos[0].notas[1] = 7;
    Alumnos[0].promedio = (float) (Alumnos[0].notas[0] + Alumnos[0].notas[1])/2;

    // El usuario carga al 2do alumno (cuidado con los &, los string no van porque son arreglos pero los otros datos tienen que tener &):
    printf("Ingrese al 2do usuario: \n");
    printf("Ingrese el nombre (sin espacios, use guion o guion_bajo): \n");
    scanf("%s", Alumnos[1].nombre);

    printf("Ingrese el padron: \n");
    scanf("%i", &Alumnos[1].padron);

    printf("Ingrese el email: \n");
    scanf("%s", Alumnos[1].email);

    printf("Ingrese la 1er nota: \n");
    scanf("%i", &Alumnos[1].notas[0]);

    printf("Ingrese la 2da nota: \n");
    scanf("%i", &Alumnos[1].notas[1]);

    Alumnos[1].promedio = (float) (Alumnos[1].notas[0] + Alumnos[1].notas[1])/2;

    printf("\n Alumno 1 (Alumnos[0])");
    printf("\n El nombre: %s ", Alumnos[0].nombre);
    printf("\n El padron: %i ", Alumnos[0].padron);
    printf("\n El email: %s", Alumnos[0].email);
    printf("\n Nota del 1er parcial: %i Nota del 2do parcial: %i", Alumnos[0].notas[0], Alumnos[0].notas[1]);
    printf("\n El promedio es: %f\n", Alumnos[0].promedio);

    printf("\n Alumno 2 (Alumnos[1])");
    printf("\n El nombre: %s ", Alumnos[1].nombre);
    printf("\n El padron: %i ", Alumnos[1].padron);
    printf("\n El email: %s", Alumnos[1].email);
    printf("\n Nota del 1er parcial: %i Nota del 2do parcial: %i", Alumnos[1].notas[0], Alumnos[1].notas[1]);
    printf("\n El promedio es: %f\n", Alumnos[1].promedio);
}