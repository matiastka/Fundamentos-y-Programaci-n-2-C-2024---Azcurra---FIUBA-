/*
Se tienen los siguientes datos de los empleados de una empresa:
Apellido y Nombre (35 caracteres)
Fecha de Nacimiento (día, mes y año)
Fecha de Ingreso (día, mes y año)
Sueldo Básico
Se conoce la cantidad N de empleados y la fecha de procesamiento.
Se pide: Imprimir un listado con los apellidos y nombres de las personas
que cumplan años en el mes y calcular e informar una suma de regalo
equivalente al uno por mil del sueldo por cada año cumplido. 
*/

# include <stdio.h>
# include <string.h>

# define N 1
# define dia_procesamiento 16
# define mes_procesamientio 6
# define anio_procesamiento 2024

typedef struct{
    char apellido_y_nombre[35];
    int fecha_nacimiento[3];
    int fecha_ingreso[3];
    int sueldo_basico;
} Templeado;

typedef Templeado TvecEmpleados[N]; // Esto es definir al registro como una tabla (vector de registros)

void CargarDatos(TvecEmpleados empleados){ // Usamos unf or porque te dicen que conoces la cantidad de datos y no se usa ML (para ninguna funcion)
    int contador;

    for(contador = 0; contador < N; contador++){
        printf("Ingrese el nombre y el apellido: ");
        scanf("%s", empleados[contador].apellido_y_nombre);
        
        printf("\n Ingrese la fecha de nacimiento:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleados[contador].fecha_nacimiento[0]);
        printf("\nIngrese el mes: ");
        scanf("%i", &empleados[contador].fecha_nacimiento[1]);
        printf("\nIngrese el anio: ");
        scanf("%i", &empleados[contador].fecha_nacimiento[2]);
        
        printf("\n Ingrese la fecha de ingreso:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleados[contador].fecha_ingreso[0]);
        printf("\nIngrese el mes: ");
        scanf("%i", &empleados[contador].fecha_ingreso[1]);
        printf("\nIngrese el anio: ");
        scanf("%i", &empleados[contador].fecha_ingreso[2]);

        printf("\n Ingrese el sueldo basico: ");
        scanf("%i", &empleados[contador].sueldo_basico);
    }
}

void MostrarCumplanierosPorMesYSumarSueldo(TvecEmpleados empleados){
    int sumar, contador, anios_en_la_empresa, salario_bonus;
    
    salario_bonus = 0;
    sumar = 0;
    anios_en_la_empresa = 0;

    printf("nombre y apellido\t\tsueldo_bonus\n"); // Encabezado
    
    for(contador = 0; contador < N; contador++){
        if (empleados[contador].fecha_nacimiento[1] == mes_procesamientio){
            anios_en_la_empresa = anio_procesamiento - empleados[contador].fecha_ingreso[2];
            if (anios_en_la_empresa < 0){ // Si el empleado entró despues, entonces no es empleado (aria)
                anios_en_la_empresa = 0;
            }
            salario_bonus = anios_en_la_empresa * 1000;
            sumar = salario_bonus + empleados[contador].sueldo_basico;

            printf("%s\t\t\t%i", empleados[contador].apellido_y_nombre, sumar);
        }
    }
}

void main(){
    TvecEmpleados empleados;

    CargarDatos(empleados);
    MostrarCumplanierosPorMesYSumarSueldo(empleados);
}
