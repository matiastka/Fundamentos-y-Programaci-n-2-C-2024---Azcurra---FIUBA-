/*
Se tiene un archivo con los siguientes datos de los empleados de una
empresa: Apellido y Nombre (35 caracteres), Fecha de Nacimiento (día,
mes y año) ,Fecha de Ingreso (día , mes y año) y Sueldo Básico
Se conoce la fecha de procesamiento.
Se pide:
a) imprimir un listado con los apellidos y nombres de las personas que cumplan años en el mes
b) calcular e informar una suma de regalo equivalente al uno por mil del sueldo por cada año cumplido. 
*/

# include <stdio.h>
# include <string.h>
# define MAX 3
# define dia_procesamiento 30
# define mes_procesamiento 11
# define anio_procesamiento 2024

typedef struct{
    char apellido_nombre[35];
    int fecha_nacimiento[3]; // [dia, mes, anio] el 3 es la #elementos que tiene
    int fecha_ingreso[3];
    int sueldo_basico;
}Templeado;

typedef Templeado TvecEmpleados[MAX]; // Para definir una tabla con los structs de los empleados se le pone un MAX (para que entre en memoria)

void CargarArchivo(FILE *archivo){
    Templeado empleado;
    int cantidad_anotados;

    cantidad_anotados = 0;

    printf("Ingrese el nombre y apellido del empleado (maximo 35 caracteres) (-1 para finalizar): ");
    scanf("%s", empleado.apellido_nombre);
    fflush(stdin);

    while((cantidad_anotados < MAX) && (strcmp(empleado.apellido_nombre,"-1") != 0)){
        printf("Ingrese la fecha de nacimiento del empleado:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleado.fecha_nacimiento[0]); 
        fflush(stdin);
        printf("Ingrese el mes: ");
        scanf("%i", &empleado.fecha_nacimiento[1]); 
        fflush(stdin);
        printf("Ingrese el anio: ");
        scanf("%i", &empleado.fecha_nacimiento[2]); 
        fflush(stdin);

        printf("Ingrese la fecha de ingreso del empleado:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleado.fecha_ingreso[0]); 
        fflush(stdin);
        printf("Ingrese el mes: ");
        scanf("%i", &empleado.fecha_ingreso[1]); 
        fflush(stdin);
        printf("Ingrese el anio: ");
        scanf("%i", &empleado.fecha_ingreso[2]); 
        fflush(stdin);

        printf("Ingrese el sueldo basico del empleado: ");
        scanf("%i", &empleado.sueldo_basico);
        fflush(stdin);

        fwrite(&empleado, sizeof(empleado), 1, archivo);
        
        cantidad_anotados++;

        // Para evitar repreguntar el nombre si ya se agregaron la cant_maxima de empleados:

        if (cantidad_anotados < MAX){
            printf("Ingrese el nombre y apellido del empleado (maximo 35 caracteres) (-1 para finalizar): ");
            scanf("%s", empleado.apellido_nombre);
            fflush(stdin);
        }
    }
}

void MostrarEmpleadoCumpleMesySumarSueldo(FILE *archivo){
    Templeado empleado;

    int sueldo_regalo, anios_en_empresa, nuevo_sueldo;

    fread(&empleado, sizeof(empleado), 1, archivo); // Empezamos leyendo el archivo guardando los datos en la variable struct empleado (incializamos su contador)

    printf("Apellido y Nombre\tNuevo Sueldo\n");

    while (!feof(archivo)){
        if (empleado.fecha_nacimiento[1] == mes_procesamiento){ // Se recorre por posiciones --> fecha_nacimiento[1] va al mes
            anios_en_empresa = anio_procesamiento - empleado.fecha_ingreso[2]; // Se recorre por posiciones --> fecha_nacimiento[2] va al anio

            sueldo_regalo = empleado.sueldo_basico * anios_en_empresa;

            nuevo_sueldo = sueldo_regalo + empleado.sueldo_basico;

            printf("%s\t\t%i\n", empleado.apellido_nombre, nuevo_sueldo);
        }
        fread(&empleado, sizeof(empleado), 1, archivo); // Avanzamos en la lectura del archivo
    }
}

void main(){
    FILE *archivo;
    /* Esto no me lo piden pero lo hice para probar
    archivo = fopen("archivo_eje9.dat", "wb");
    
    if (archivo == NULL){
        printf("El archivo no se pudo abrir");
    }
    else{
        CargarArchivo(archivo);
        fclose(archivo);
    }
    */
    
    archivo = fopen("archivo_eje9.dat", "rb");
    if (archivo == NULL){
        printf("El archivo_eje9.dat no se pudo abrir");
    }
    else{
        MostrarEmpleadoCumpleMesySumarSueldo(archivo);
        fclose(archivo);
    }
}