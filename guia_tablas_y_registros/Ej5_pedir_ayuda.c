/*
Dados dos 2 listados de inscripción de alumnos a 3 turnos de una misma materia, se pide generar un listado único ordenado por número de alumno.
La estructura de los listados es: número de alumno (5 dígitos), apellido y nombre, turno (1,2, 3). 
Puede ocurrir que un alumno se haya inscripto en más de un turno por lo cual en el listado generado deben aparecer todos
los turnos en los que se inscribió en un único registro de alumno con campo variable.
Los listados de entrada están ordenados por número de alumno
*/

# include <stdio.h>
# include <string.h>

# define MAX 100

typedef struct {
    int numero_alumno;
    char apellido_y_nombre[35]; // Heredado del Ej1
    int turno; 
} Talumno;

typedef Talumno TvecAlumnos[MAX];

void ValidarNumero(int *numero){ // Misma validacion que el Ej4 solo que para 5 cifras
    printf("Ingrese el numero del alumno (con 5 cifras, 0 para finalizar): ");
    scanf("%i", numero);
    while ((*numero < 10000) && (*numero != 0)){
        printf("Ingrese el numero del alumno (con 5 cifras, 0 para finalizar): ");
        scanf("%i", numero);
    }
}

void CargarAlumnos(TvecAlumnos alumnos, int *ML){
    int contador;

    contador = 0;

    ValidarNumero(&alumnos[contador].numero_alumno);

    while ((contador < MAX) && (alumnos[contador].numero_alumno != 0)){
        printf("Ingrese el nombre y el apellido del alumno: ");
        scanf("%s", alumnos[contador].apellido_y_nombre);

        printf("Ingrese el turno: (1 = mañana, 2 = tarde, 3 = noche) ");
        scanf("%i", &alumnos[contador].turno[0]);

        contador++;

        ValidarNumero(&alumnos[contador].numero_alumno);
    }
    *ML = contador;

}

void OrdenarporNumAlumno(TvecAlumnos alumnos, int ML){
    int i, j;
    Talumno aux; // Aux es del mismo tipo que la estructura de la tabla (vector de registros)

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML-i; j++){
            if (alumnos[j].numero_alumno > alumnos[j+1].numero_alumno){
                aux = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = aux;
            }
        }
    }
}

void MostrarAlumno(Talumno alumno){ 
    printf("%i\t\t",alumno.numero_alumno);
    printf("%s\t\t",alumno.apellido_y_nombre);
    printf("%i\n",alumno.turno);
}

void MostrarTablaAlumnos(TvecAlumnos alumnos, int ML){
    int contador;

    printf("Numero_Alumno\tApellido_y_Nombre\tTurno\n");
    for (contador = 0; contador < ML; contador++){
        MostrarAlumno(alumnos[contador]);
        printf("\n");
    }
}

void FusionarListados(TvecAlumnos alumnos_1, int ML_1, TvecAlumnos alumnos_2, int ML_2, TvecAlumnos alumnos_fusionados, int *ML_fusionado){ // Pedir ayuda
    int contador_1, contador_2, contador_nuevo;

    contador_1 = 0;
    contador_2 = 0;
    contador_nuevo = 0;

    while (contador_1 < ML_1 && contador_2 < ML_2){
        if (alumnos_1[contador_1].numero_alumno == alumnos_2[contador_2].numero_alumno){ // Si ambas listas tienen al mismo alumno, lo agregan (sin importar cual es)
            alumnos_fusionados[contador_nuevo] = alumnos_1[contador_1];
            alumnos_fusionados[contador_nuevo].turno[1] = alumnos_2[contador_nuevo].turno[0]; // Guardamos el turno del otro listado
            contador_nuevo++;
            contador_1++;
        }
        else{
            if (alumnos_1[contador_1].numero_alumno > alumnos_2[contador_2].numero_alumno){
                alumnos_fusionados[contador_nuevo] = alumnos_1[contador_1];
                contador_nuevo++;
                contador_1++;
            }
            else{
                alumnos_fusionados[contador_nuevo] = alumnos_2[contador_2];
                contador_nuevo++;
                contador_2++;
            }
        }
    }
    *ML_fusionado = contador_nuevo;
}

void main(){
    TvecAlumnos alumnos_1;
    TvecAlumnos alumnos_2;
    TvecAlumnos alumnos_fusionado;
    int ML_1, ML_2, ML_fusionado;

    printf("Ingresando el listado 1:\n");
    CargarAlumnos(alumnos_1, &ML_1);
    printf("Ingresando el listado 2:\n");
    CargarAlumnos(alumnos_2, &ML_2);
    
    OrdenarporNumAlumno(alumnos_1, ML_1);
    OrdenarporNumAlumno(alumnos_2, ML_2);

    MostrarTablaAlumnos(alumnos_1,ML_1);
    MostrarTablaAlumnos(alumnos_2,ML_2);

    FusionarListados(alumnos_1, ML_1, alumnos_2, ML_2, alumnos_fusionado, &ML_fusionado);
}