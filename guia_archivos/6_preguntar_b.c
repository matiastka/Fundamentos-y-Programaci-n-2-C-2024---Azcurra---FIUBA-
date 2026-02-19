/*
Se tiene un archivo de números telefónicos cuyos registros son de la forma: 
Característica de localidad (4 dígitos)
Característica central (3 dígitos)
Número (4 dígitos)
Dado un número que representa una característica de localidad, listar todos los números telefónicos con dicha característica.
Suponer los siguientes casos:
a) El archivo no cabe en memoria y está desordenado.
b) El archivo no cabe en memoria y está ordenado según números telefónicos crecientes. 
*/

# include <stdio.h>
# include <stdbool.h>
# define MAX 100 // Esto lo hacemos porque no cabe en memoria todo el archivo

typedef struct{
    int localidad;
    int central;
    int numero_tel;
} Ttelefonos;

typedef Ttelefonos TvecTelefonos[MAX];

// a)
void MostrarTelefonosporLocalidad(FILE *archivo, int buscado){
    Ttelefonos telefono;
    bool encontrado;

    encontrado = false;

    fread(&telefono, sizeof(telefono), 1, archivo);

    printf("Nro_tel\n"); // Encabezado

    while (!feof(archivo)){
        if (buscado == telefono.localidad){
            printf("%i\n", telefono.numero_tel);
            encontrado = true;
        }
        fread(&telefono, sizeof(telefono), 1, archivo); // Esto tiene que seguir leyendo hasta terminar el archivo
    }
    if (encontrado == false){
        printf("No se encontraron numeros para esa localidad");
    }
}

// b) preguntar a maru (cortesia de gpt)
void MostrarTelefonosporLocalidadOrdenada(FILE *archivo, int buscado){
    Ttelefonos telefono;
    bool encontrado, continuar;
    continuar = true;
    encontrado = false;

    fread(&telefono, sizeof(telefono), 1, archivo);

    printf("Nro_tel\n"); // Encabezado

    while (!feof(archivo) && (continuar == true)){
        if (buscado > telefono.localidad){
            continuar = false;
        }
        if (buscado == telefono.localidad){
            printf("%i\n", telefono.numero_tel);
            encontrado = true;
        }
        fread(&telefono, sizeof(telefono), 1, archivo); // Esto tiene que seguir leyendo hasta terminar el archivo
    }
    if (encontrado == false){
        printf("No se encontraron numeros para esa localidad");
    }
}

void main(){
    FILE *archivo;
    TvecTelefonos tabla_telefonos;
    int localidad_buscada;

    printf("Ingrese la localidad buscada (4 digitos): ");
    scanf("%i", &localidad_buscada);

    archivo = fopen("archivo_eje6.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarTelefonosporLocalidad(archivo, localidad_buscada);
        fclose(archivo);
    }
}