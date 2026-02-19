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
# define N 3 // Es la cantidad de empleados, arbritariamente pongo 3

typedef struct { // Definimos la estructura de los empleados
    char apellido_y_nombre[50];
    int fecha_nacimiento[3];
    int fecha_ingreso[3];
    int sueldo_basico;
} TEmpleado;

typedef TEmpleado TvecEmpleados[N]; // TvecEmpleados que toma como Maximo N, es de tipo struct con la estructura de los empelados

void Cargar(TvecEmpleados empleados){ // Como sabemos cuantos empleados hay, que es N, ingresamos hasta esa cantidad (hacemos for)
    int contador;
    
    for (contador = 0; contador < N; contador++){
        printf("Ingrese el apellido y el nombre del empleado (sin espacios): ");
        scanf("%s", empleados[contador].apellido_y_nombre);

        printf("Ingrese la fecha de nacimiento:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleados[contador].fecha_nacimiento[0]);
        printf("Ingrese el mes: ");
        scanf("%i", &empleados[contador].fecha_nacimiento[1]);
        printf("Ingrese el anio: ");
        scanf("%i", &empleados[contador].fecha_nacimiento[2]);

        printf("Ingrese la fecha de ingreso:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleados[contador].fecha_ingreso[0]);
        printf("Ingrese el mes: ");
        scanf("%i", &empleados[contador].fecha_ingreso[1]);
        printf("Ingrese el anio: ");
        scanf("%i", &empleados[contador].fecha_ingreso[2]);

        printf("Ingrese el sueldo: ");
        scanf("%i", &empleados[contador].sueldo_basico);
    }
    
}

void Mostrar_Cumpleanieros_del_Mes(TvecEmpleados empleados, int mes_del_ingreso){
    int contador;

    printf(" Cumpleanieros\n"); // Pide que se muestren un listado de los cumpleanieros

    for (contador = 0; contador < N; contador++){
        if (empleados[contador].fecha_nacimiento[1] == mes_del_ingreso){
            printf(" %s\n", empleados[contador].apellido_y_nombre);
        }
    }
}

void Sumar_Sueldo(TvecEmpleados empleados, int mes_del_ingreso, int anio_del_ingreso){
    int contador, sueldo_regalo, cantidad_anios, suma;
    sueldo_regalo = 0;
    suma = 0;

    for (contador = 0; contador < N; contador++){
        if (empleados[contador].fecha_nacimiento[1] == mes_del_ingreso){
            cantidad_anios = anio_del_ingreso - empleados[contador].fecha_ingreso[2];
            if (cantidad_anios < 0){ // Gracias Aria (si tiene anios negativos entonces no es empleado, por lo tanto no hay sueldo de regalo)
                cantidad_anios = 0;
            }
            else if (cantidad_anios == 0){
                cantidad_anios = 1;
            }
            sueldo_regalo = cantidad_anios * empleados[contador].sueldo_basico;
            suma = sueldo_regalo + empleados[contador].sueldo_basico;
            printf("Por ser su mes de cumpleanios, le damos un sueldo de regalo de %i\n", sueldo_regalo);
            printf("Su sueldo Neto por este mes especial es: %i\n", suma);
        }
    }
}

void main(){
    TvecEmpleados tabla; 
    int dia_procesamiento, mes_procesamiento, anio_procesamiento;

    Cargar(tabla);

    printf("Ingrese la fecha de procesamiento:\n");
    printf("Ingrese el dia: ");
    scanf("%i", &dia_procesamiento);
    printf("Ingrese el mes: ");
    scanf("%i", &mes_procesamiento);
    printf("Ingrese el anio: ");
    scanf("%i", &anio_procesamiento);

    Mostrar_Cumpleanieros_del_Mes(tabla, mes_procesamiento);

    Sumar_Sueldo(tabla, mes_procesamiento, anio_procesamiento);
}