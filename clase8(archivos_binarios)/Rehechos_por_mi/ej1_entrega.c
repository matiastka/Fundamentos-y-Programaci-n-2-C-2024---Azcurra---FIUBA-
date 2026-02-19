/*
Escribir un programa modular en C, que permita listar los datos de los productos que se encuentran en el archivo productos.dat.
La estructura de los registros es la siguiente:

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
}t_regProducto;
El archivo sólo se puede leer una vez.
Informar al final del listado, el total de Productos en Stock.
*/

# include <stdio.h>
# include <string.h>

typedef struct{
	int codigo;
	char descripcion[30];
	float cantidad;
} Tproducto;

void MostrarArchivo(FILE *archivo){
    Tproducto producto;
    float total_productos;

    total_productos = 0;

    fread(&producto, sizeof(producto), 1, archivo); // Leemos el archivo para que inicie el contador del mismo

    printf("Codigo\tDescripcion\tCantidad\n");

    while (!feof(archivo)){ // Mientras no se llegue al fin de linea
        printf("%i\t%s\t%f\n", producto.codigo, producto.descripcion, producto.cantidad); // Imprimimos los datos de struct

        total_productos = total_productos + producto.cantidad; // Guardamos la cantidad total de productos (haicendo la suma de ellos)

        fread(&producto, sizeof(producto), 1, archivo); // Leemos el archivo para que el contador del archivo avance (de a 1)
    }
    printf("El total de productos en stock es: %f", total_productos);
}

void main(){
    FILE *archivo;

    archivo = fopen("productos.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        MostrarArchivo(archivo);
        fclose(archivo);
    }
}