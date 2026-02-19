/*
Una agencia de autos posee un archivo denominado Autos.dat, cuyos registros contienen el código de auto (entero), descripción del auto (string de 1000), precio (float), 
no “entra” en memoria en su totalidad.
Se pide desarrollar un programa en lenguaje C que permita ingresar al usuario un precio y que permita: 
Generar una tabla llamada MasCaros que contenga toda la información (código, precio) de aquellos autos que superen el precio ingresado.
Asumir que esta tabla tendrá como máximo 100
*/

# include <stdio.h>
# include <string.h> // es innecesaria esta libreria

# define MAX 100
# define MAX_STRING 1000

typedef char Tstring[MAX_STRING]; // Para definir un char hay que hacerlo asi (y no char descripcio[1000])

typedef struct{
    int codigo;
    Tstring descripcion;
    float precio;
} Tcoche;

typedef struct{
    int codigo;
    float precio;
} Tcochescaros;

typedef Tcochescaros Tveccochescaros[MAX];

void CargarArchivo(FILE *archivo){ // Para probar si anda (NO ME LO PIDEN)
    Tcoche coche;

    printf("Ingrese el codigo del coche (0 para finalizar): ");
    scanf("%i", &coche.codigo);
    fflush(stdin);

    while(coche.codigo != 0){
        printf("Ingrese la descripcion del coche (maximo 1000 caracteres): ");
        scanf("%s", coche.descripcion);
        fflush(stdin);

        printf("Ingrese el precio del coche: ");
        scanf("%f", &coche.precio);
        fflush(stdin);

        fwrite(&coche, sizeof(coche), 1, archivo);

        printf("Ingrese el codigo del coche (0 para finalizar): ");
        scanf("%i", &coche.codigo);
        fflush(stdin);
    }
}

void CargarTabla(FILE *archivo, float precio_ingresado, Tveccochescaros tabla_coches_caros, int *ML){
    Tcoche coche;

    int contador;

    contador = 0;

    fread(&coche, sizeof(coche), 1, archivo); // Leemos el archivo y guardamos los datos en el struct coche (inicializa el contador del archivo)

    while((!feof(archivo) && (contador < MAX))){
        if (precio_ingresado < coche.precio){ // Si el precio ingresado es superado por el precio del coche: 
            // En este caso como no queremos todo el registro, queremos sacar el campo descripcion, entonces guardamos los 2 campos que necesitamos y aumentamos el contador solo si guarda un auto
            tabla_coches_caros[contador].codigo = coche.codigo;
            tabla_coches_caros[contador].precio = coche.precio;
            contador++;
        }
        fread(&coche, sizeof(coche), 1, archivo); // Avanzamos el contador del archivo y guardamos los nuevos datos del struct en el registro coche
    }
    *ML = contador;
}

void MostrarCochesCaros(Tcochescaros coche){
    printf("%i\t", coche.codigo);
    printf("%f\n", coche.precio);
}

void MostrarTablaCochesCaros(Tveccochescaros tabla, int ML){
    int contador;

    printf("Codigo\tPrecio\n"); // Encabezado de la tabla

    for (contador = 0; contador < ML; contador++){
        MostrarCochesCaros(tabla[contador]); // Imprimimos un coche_caro (struct)
        printf("\n");
    }
}

void main(){
    FILE *archivo;
    Tveccochescaros tabla_de_coches_caros;
    float precio_ingresado;
    int ML;

    /* Para probarlo: 
    archivo = fopen("Autos.dat", "wb");

    if(archivo == NULL){
        printf("No se puede abrir el archivo Autos.dat");
    }
    else{
        CargarArchivo(archivo);
        fclose(archivo);
    }
    */

    printf("Ingrese un precio: ");
    scanf("%f", &precio_ingresado);

    archivo = fopen("Autos.dat", "rb");

    if (archivo == NULL){
        printf("No se puede abrir el archivo Autos.dat");
    }
    else{
        CargarTabla(archivo, precio_ingresado, tabla_de_coches_caros, &ML);
        fclose(archivo);
        MostrarTablaCochesCaros(tabla_de_coches_caros, ML);
    }
}