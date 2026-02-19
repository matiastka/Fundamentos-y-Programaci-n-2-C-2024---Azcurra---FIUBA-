/*
3)
Dada la estructura de datos del problema anterior, escribir el algoritmo de
búsqueda binaria para la búsqueda de un dato correspondiente a los
campos de Apellido, Nombre o número de legajo, a elección del usuario. 

Verificar si muestra el apellido buscado y el legajo buscado
*/

# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# define ANIO_ACTUAL 2024
# define MAX 100

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

void OrdenarporApellido(TvecEmpleados empleados, int ML){ // Uso ordenamiento por burbujeo para tablas con datos de tipo STRING (uso funciones de este tipo de dato)
    int i,j;
    Templeado aux; // Aux ahora es del tipo de la estructura en la que trabaja la tabla

    // En este caso primero me fijo que el apellido en la posicion analizada sea mayor a la proxima posicion, de serlo ocurre el ordenamiento. Si son iguales hace lo mismo pero con los nombres
    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (strcmp(empleados[j].Apellido, empleados[j+1].Apellido) > 0){
                aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
            }
        }
    }
}

void OrdenarporNombre(TvecEmpleados empleados, int ML){
    int i,j;
    Templeado aux;

    for (i = 1; i < ML; i++){
        for (j = 0; j < ML - i; j++){
            if (strcmp(empleados[j].Nombre, empleados[j+1].Nombre) > 0){
                aux = empleados[j];
                empleados[j] = empleados[j+1];
                empleados[j+1] = aux;
            }
        }
    }
}

void OrdenarPorLegajo(TvecEmpleados empleados, int ML){ 
    int i, j;
    Templeado aux; 

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

int BusquedaBinariaApellido(TvecEmpleados empleados, int ML, char apellido_buscado[]){ // Como apellido Buscado es arreglo de caracteres se define igual a un arreglo (sino usar como lo vimos en clase)
    int primera_posicion, ultima_posicion, posicion_del_medio, posicion_buscada;
    bool encontrado;

    primera_posicion = 0;
    ultima_posicion = ML - 1;
    posicion_buscada = -1;
    encontrado = false;

    while(encontrado == false){
        // Verifica que este dentro del rango: (si el nombre buscado es menor al primer apellido ó el apellido buscado es mayor al ultimo nombre --> No esta!  )
        if (strcmp(apellido_buscado, empleados[primera_posicion].Apellido) < 0 || strcmp(apellido_buscado, empleados[ultima_posicion].Apellido) > 0){ // Verifica que este dentro del rango
            encontrado = true;
            posicion_buscada = -1;
        }
        else{
            posicion_del_medio = (primera_posicion + ultima_posicion)/2;
            if (strcmp(empleados[posicion_del_medio].Apellido, apellido_buscado) == 0){
                posicion_buscada = posicion_del_medio;
                encontrado = true;
            }
            else{
                if (strcmp(empleados[posicion_del_medio].Apellido, apellido_buscado) < 0){
                    primera_posicion = posicion_del_medio + 1;
                }
                else{
                    ultima_posicion = posicion_del_medio - 1;
                }
            }
        }
    }

    return posicion_buscada;
}

void BuscarApellido(TvecEmpleados empleados, int ML){ // Esta funcion se encarga recibir el apellido buscado y de llamar a la funcion de busqueda binaria para saber si esta o no
    int posicion_buscada;
    char apellido_buscado[30]; //Apellido buscado es un puntero a char (Arreglo de caracteres). Gracias Aria. Sino definir: typedef char TString[MAX_CHAR] y usarlo para apellido_buscado (ver ejercicio grupal)

    printf("Ingrese el apellido a buscar: ");
    scanf("%s", apellido_buscado);

    posicion_buscada = BusquedaBinariaApellido(empleados, ML, apellido_buscado);
    if (posicion_buscada >= 0){
        MostrarEmpleado(empleados[posicion_buscada]);
    }
    else{
        printf("No se encontro el apellido.");
    }

}

int BusquedaBinariaNombre(TvecEmpleados empleados, int ML, char nombre_buscado[]){
    int primera_posicion, ultima_posicion, posicion_del_medio, posicion_buscada;
    bool encontrado;

    primera_posicion = 0;
    ultima_posicion = ML - 1;
    posicion_buscada = -1;
    encontrado = false;

    while(encontrado == false){
        // Verifica que este dentro del rango: (si el nombre buscado es menor al primer nombre ó el nombre buscado es mayor al ultimo nombre --> No esta!  )
        if (strcmp(nombre_buscado, empleados[primera_posicion].Nombre) < 0 || strcmp(nombre_buscado, empleados[ultima_posicion].Nombre) > 0){ // Verifica que este dentro del rango
            encontrado = true;
            posicion_buscada = -1;
        }
        else{
            posicion_del_medio = (primera_posicion + ultima_posicion)/2;
            if (strcmp(empleados[posicion_del_medio].Nombre, nombre_buscado) == 0){
                posicion_buscada = posicion_del_medio;
                encontrado = true;
            }
            else{
                if (strcmp(empleados[posicion_del_medio].Nombre, nombre_buscado) < 0){
                    primera_posicion = posicion_del_medio + 1;
                }
                else{
                    ultima_posicion = posicion_del_medio - 1;
                }
            }
        }
    }

    return posicion_buscada;
}

void BuscarNombre(TvecEmpleados empleados, int ML){
    int posicion_buscada;
    char nombre_buscado[30]; // nombre_buscado esu n arreglo para almacenar el nombre buscad de como maximo 30 caracteres

    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nombre_buscado);

    posicion_buscada = BusquedaBinariaNombre(empleados, ML, nombre_buscado);
    if (posicion_buscada >= 0){
        MostrarEmpleado(empleados[posicion_buscada]);
    }
    else{
        printf("No se encontro el nombre.");
    }
}

int BusquedaBinariaLegajo(TvecEmpleados empleados, int ML, int legajo_buscado){
    int primera_posicion, ultima_posicion, posicion_del_medio, posicion_buscada;
    bool encontrado;
    
    posicion_buscada = -1;
    encontrado = false;
    primera_posicion = 0;
    ultima_posicion = ML-1;

    while (encontrado == false){
        if (legajo_buscado < empleados[primera_posicion].Legajo || legajo_buscado > empleados[ultima_posicion].Legajo){
            posicion_buscada = -1;
            encontrado = true;
        }
        else{
            posicion_del_medio = (primera_posicion + ultima_posicion) / 2;
            if (legajo_buscado == empleados[posicion_del_medio].Legajo){
                posicion_buscada = posicion_del_medio;
                encontrado = true;
            }
            else{
                if (legajo_buscado > empleados[posicion_del_medio].Legajo){
                    primera_posicion = posicion_del_medio + 1;
                }
                else{
                    ultima_posicion = posicion_del_medio - 1;
                }
            }
        }
    }
    return posicion_buscada;
}

void BuscarLegajo(TvecEmpleados empleados, int ML){
    int posicion_buscada, legajo_buscado;
    
    printf("Ingrese el legajo buscado: ");
    scanf("%i", &legajo_buscado);

    posicion_buscada = BusquedaBinariaLegajo(empleados, ML, legajo_buscado);
    if (posicion_buscada >= 0){
        MostrarEmpleado(empleados[posicion_buscada]);
    }
    else{
        printf("No se encontro el legajo buscado");
    }
}

void main(){
    TvecEmpleados tabla;
    int ML;
    char selector[10];
    bool continuar;

    continuar = true;

    CargarTabla(tabla, &ML);
    MostrarTabla(tabla, ML);  

    while(continuar){
        printf("Ingrese el campo que desea buscar (Apellido, Nombre o Legajo): ");
        scanf("%s", selector);
        if (strcmp(selector, "Legajo") == 0 || strcmp(selector, "legajo") == 0){
            OrdenarPorLegajo(tabla, ML);
            MostrarTabla(tabla, ML);
            BuscarLegajo(tabla, ML);
            continuar = false;
        }
    }
}
