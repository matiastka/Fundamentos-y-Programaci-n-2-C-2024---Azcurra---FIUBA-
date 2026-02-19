/*
2)
Se tienen datos de empleados de una empresa según la siguiente
estructura:
Apellido, Nombre.
Legajo
Dirección: Calle, N°, Localidad, Provincia, Código Postal.
Fecha de Nacimiento: Día, Mes, Año.
Fecha de Ingreso: Día, Mes, Año.
Se pide hacer un programa que almacene los datos de todos los
empleados en una tabla en memoria y que permita obtener un listado
ordenado por pantalla según distintos ítems, como, por ejemplo, por
Apellido y Nombre, por número de legajo, por edad, por antigüedad, por localidad.
Utilizar un esquema tipo menú. 
*/

# include <stdio.h>
# include <string.h>

# define MAX 100
# define ANIO_ACTUAL 2024

typedef struct {
    char Apellido[30];
    char Nombre[30];
    int Legajo;
    char CalleNombre[30];
    int CalleNumero;
    char Localidad[30];
    char Provincia[30];
    int CodigoPostal;
    int Fecha_nacimiento[3];
    int Fecha_ingreso[3];
} Templeado;

typedef Templeado TvecEmpleados[MAX];

void ValidarSelector(int *numero){
    while (*numero < 1 || *numero > 9){
        printf("Ingrese un numero para ordenar el listado (entre 1 y 9): ");
        scanf("%i", numero);
    }
}

void CargarTabla(TvecEmpleados empleados, int *ML){
    int contador;

    contador = 0;

    printf("Ingrese el legajo del empleado (0 o negativo para finalizar): ");
    scanf("%i", &empleados[contador].Legajo);

    while ((contador < MAX ) && (empleados[contador].Legajo > 0)){
        printf("Ingrese el apellido: ");
        scanf("%s", empleados[contador].Apellido);
        printf("Ingrese el nombre: ");
        scanf("%s", empleados[contador].Nombre);

        printf("Ingrese el nombre de la calle: ");
        scanf("%s", empleados[contador].CalleNombre);
        printf("Ingrese el numero de la calle: ");
        scanf("%i", &empleados[contador].CalleNumero);
        printf("Ingrese la provincia: ");
        scanf("%s", empleados[contador].Provincia);
        printf("Ingrese la localidad: ");
        scanf("%s", empleados[contador].Localidad);
        printf("Ingrese el codigo postal: ");
        scanf("%i", &empleados[contador].CodigoPostal);

        printf("Ingrese su fecha de nacimiento:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleados[contador].Fecha_nacimiento[0]);
        printf("Ingrese el mes: ");
        scanf("%i", &empleados[contador].Fecha_nacimiento[1]);
        printf("Ingrese el anio: ");
        scanf("%i", &empleados[contador].Fecha_nacimiento[2]);
        
        printf("Ingrese su fecha de ingreso:\n");
        printf("Ingrese el dia: ");
        scanf("%i", &empleados[contador].Fecha_ingreso[0]);
        printf("Ingrese el mes: ");
        scanf("%i", &empleados[contador].Fecha_ingreso[1]);
        printf("Ingrese el anio: ");
        scanf("%i", &empleados[contador].Fecha_ingreso[2]);

        contador++;
        
        printf("\nIngrese el legajo (0 o negativo para finalizar): ");
        scanf("%i", &empleados[contador].Legajo);
    }
    *ML = contador;
}

void MostrarEmpleado(Templeado empleado){
    int Edad, Antiguedad;
    Edad = ANIO_ACTUAL - empleado.Fecha_nacimiento[2]; // empleado.Fecha_nacimiento[2] = anio de nacimiento
    Antiguedad = ANIO_ACTUAL - empleado.Fecha_ingreso[2];
    printf(" %i", empleado.Legajo);
    printf(" %s", empleado.Apellido);
    printf(" %s", empleado.Nombre);
    printf(" %s", empleado.CalleNombre);
    printf(" %i", empleado.CalleNumero);
    printf(" %s", empleado.Provincia);
    printf(" %s", empleado.Localidad);
    printf(" %i", empleado.CodigoPostal);
    printf(" %i", Edad);
    printf(" %i\n", Antiguedad);
}

void MostrarTabla(TvecEmpleados empleados, int ML){ //Me piden que muestre la tabla en formato lista:
    int contador;
    
    // Encabezado
    printf(" Legajo");
    printf(" Apellido");
    printf(" Nombre");
    printf(" CalleNombre");
    printf(" CalleNumero");
    printf(" Provincia");
    printf(" Localidad");
    printf(" CodigoPostal");
    printf(" Edad"); // Solamente tomo los años
    printf(" Antiguedad\n"); // Solamente tomo los años

    for (contador = 0; contador < ML; contador++){ // Cuerpo
        MostrarEmpleado(empleados[contador]); // Necesitamos una funcion que analize cada registro en particular (es una funcion de struct)
        printf("\n");
    }
}

void OrdenarporApellidoyNombre(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo para tablas con datos de tipo STRING (uso funciones de este tipo de dato)
    int i,j;
    Templeado aux; // Aux ahora es del tipo de la estructura en la que trabaja la tabla

    // En este caso primero me fijo que el apellido en la posicion analizada sea mayor a la proxima posicion, de serlo ocurre el ordenamiento. Si son iguales hace lo mismo pero con los nombres
    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (strcmp(empleados[j].Apellido, empleados[j+1].Apellido) > 0 || ((strcmp(empleados[j].Apellido, empleados[j+1].Apellido) == 0) && (strcmp(empleados[j].Nombre, empleados[j+1].Nombre) > 0))){
                aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
            }
        }
    }
}

void OrdenarPorLegajo(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo de una tabla
    int i, j;
    Templeado aux; // Aux ahora es del tipo de la estructura en la que trabaja la tabla

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (empleados[j].Legajo > empleados[j + 1].Legajo){
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorEdad(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo (tabla)
    int i, j, edad_1, edad_2; // Las edades no estan directamente en el registro sino que se calculan haciendo: Anio_Actual menos el anio_nacimiento
    Templeado aux; 

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            edad_1 = ANIO_ACTUAL - empleados[j].Fecha_nacimiento[2]; // Elemento analizado
            edad_2 = ANIO_ACTUAL - empleados[j+1].Fecha_nacimiento[2]; // Elemento Proximo al analizado
            if (edad_1 > edad_2){ 
                aux = empleados[j]; // El ordenamiento siempre es el mismo:
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorAntiguedad(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo (tabla)
    int i, j, antiguedad_1, antiguedad_2; // Las antiguedades no estan directamente en el registro sino que se calculan haciendo: Anio_Actual menos anio_antiguedad
    Templeado aux; 

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            antiguedad_1 = ANIO_ACTUAL - empleados[j].Fecha_ingreso[2]; // Elemento analizado
            antiguedad_2 = ANIO_ACTUAL - empleados[j+1].Fecha_ingreso[2]; // Elemento Proximo al analizado
            if (antiguedad_1 > antiguedad_2){ 
                aux = empleados[j]; // El ordenamiento siempre es el mismo:
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorLocalidad(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo para tablas con datos de tipo STRING (uso funciones de este tipo de dato)
    int i, j;
    Templeado aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (strcmp(empleados[j].Localidad, empleados[j + 1].Localidad) > 0){ // strcmp compara si el 1er string con el 2do (si strcmp > 0 --> 1ro > 2do, si strcmp = 0 --> 1ro = 2do y si strcmp < 0 --> 1ro < 2do)
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorProvincia(TvecEmpleados empleados, int ML){ 
    int i, j;
    Templeado aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (strcmp(empleados[j].Provincia, empleados[j + 1].Provincia) > 0){ 
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorNombreCalle(TvecEmpleados empleados, int ML){ 
    int i, j;
    Templeado aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (strcmp(empleados[j].CalleNombre, empleados[j + 1].CalleNombre) > 0){ 
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorNumeroCalle(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo de una tabla
    int i, j;
    Templeado aux; // Aux ahora es del tipo de la estructura en la que trabaja la tabla

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (empleados[j].CalleNumero > empleados[j + 1].CalleNumero){
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void OrdenarPorCodigoPostal(TvecEmpleados empleados, int ML){ 
    int i, j;
    Templeado aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (empleados[j].CodigoPostal > empleados[j + 1].CodigoPostal){
                aux = empleados[j];
                empleados[j] = empleados[j + 1];
                empleados[j + 1] = aux;
            }
        }
    }
}

void main(){
    TvecEmpleados tabla;
    int ML, selector;

    selector = -1;

    CargarTabla(tabla, &ML);
    MostrarTabla(tabla, ML);

    printf("Ingrese un numero para obtener un listado ordenado por pantalla según el item que escoja.\n1.Ordenado por Apellido y Nombre.\n2.Ordenado por Legajo.\n3.Ordenado por Edad.\n4.Ordenado por Antiguedad.\n5.Ordenado por Localidad.\n6.Ordenado por Provincia.\n7.Ordenado por Nombre de la Calle.\n8.Ordenado por Numero de la Calle\n9.Ordenado por Codigo Postal.\n");
    
    ValidarSelector(&selector);
    
    if (selector == 1){
        printf("Escogio ordenar por Nombre y Apellido\n");
        OrdenarporApellidoyNombre(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 2){
        printf("Escogio ordenar por Legajo\n");
        OrdenarPorLegajo(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 3){
        printf("Escogio ordenar por Edad\n");
        OrdenarPorEdad(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 4){
        printf("Escogio ordenar por Antiguedad\n");
        OrdenarPorAntiguedad(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 5){
        printf("Escogio ordenar por Localidad\n");
        OrdenarPorLocalidad(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 6){
        printf("Escogio ordenar por Provincia\n");
        OrdenarPorProvincia(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 7){
        printf("Escogio ordenar por NombreCalle\n");
        OrdenarPorNombreCalle(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 8){
        printf("Escogio ordenar por NumeroCalle\n");
        OrdenarPorNumeroCalle(tabla, ML);
        MostrarTabla(tabla, ML);
    }
    if (selector == 9){
        printf("Escogio ordenar por CodigoPostal\n");
        OrdenarPorCodigoPostal(tabla, ML);
        MostrarTabla(tabla, ML);
    }
}
