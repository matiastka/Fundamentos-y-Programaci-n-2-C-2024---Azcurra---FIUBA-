/*
Se tiene el archivo stock.dat que tiene productos con los siguiente campos:
codigo del producto (entero)
rubro (char[30])
nombre (char[25])
stock actual (entero)

a) Hacer un programa que le pida al usuario ingresar un rubro y crear una tabla llamada dat_rubro (tiene los mismos campos que el archivo) que guarde solo los productos de ese rubro. 
b) Hacer una funcion mostrar_tabla() que solo muestre los productos que su stock actual supere al promedio. Llamar a la funcion dentro del programa
*/

# include <stdio.h>
# include <string.h>
# define MAX_REG 200

typedef struct{
    int codigo;
    char rubro[30];
    char nombre[25];
    int stock_actual;
} T_producto;

typedef T_producto Tvecproductos[MAX_REG];

void generar_tabla(FILE *archivo, Tvecproductos dat_tabla, char rubro, float *promedio, int *ML){
    T_producto producto;
    int i, sumatoria;
    i = 0;
    sumatoria = 0;

    fread(&producto, sizeof(producto), 1, archivo);

    while ((!feof(archivo)) && (i < MAX_REG)){
        if (strcmp(rubro, producto.rubro) == 0){
            dat_tabla[i] = producto;
            i++;
            sumatoria = sumatoria + producto.stock_actual;
        }
        fread(&producto, sizeof(producto), 1, archivo); // En el final me olvide de ponerlo :c
    }
    *ML = i;
    *promedio = (float) (sumatoria / (i+1));
}

void mostrar_producto(T_producto producto){
    printf("%i\t", producto.codigo);
    printf("%s\t", producto.rubro);
    printf("%s\t", producto.nombre);
    printf("%i\n", producto.stock_actual);
}

void mostrar_tabla(Tvecproductos dat_tabla, float promedio, int ML){
    int i;

    printf("Codigo\tRubro\tNombre\tStock Actual\n"); // encabezado

    for (i = 0; i < ML; i++){
        if (dat_tabla[i].stock_actual > promedio){
            mostrar_producto(dat_tabla[i]);
            printf("\n");
        }
    }
}

void main(){
    Tvecproductos dat_tabla;
    char rubro[30];
    int ML;
    float promedio;
    FILE *archivo;

    printf("Ingrese el rubro (maximo 30 caracteres): ");
    scanf("%s", rubro);

    archivo = fopen("Stock.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo.");
    }
    else{
        generar_tabla(archivo, dat_tabla, rubro, &promedio, &ML);
        fclose(archivo);
        mostrar_tabla(dat_tabla, promedio, ML);
    }
}