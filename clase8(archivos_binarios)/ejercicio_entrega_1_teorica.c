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

typedef struct{ //Declaramos la estrucutra para definir el tipo de estrucutra que vamos ea leer
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void mostrar_datos(FILE *arProductos){ //Mostrar datos recibe mi archivo
    
    t_regProducto rProducto;

    float suma_cant_de_productos;

    suma_cant_de_productos = 0.00;

    fread(&rProducto, sizeof(rProducto), 1, arProductos); 

    printf("\nCodigo \t Descripcion\t\t\tCantidad");

    while ( !feof(arProductos)){ 
        printf("\n %d \t%-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad); 
        
        suma_cant_de_productos = suma_cant_de_productos + rProducto.cantidad;

        fread(&rProducto, sizeof(rProducto), 1, arProductos);
    }
    printf("\nEl total de productos de stock son: %f\n", suma_cant_de_productos);
    
    return;
}

void main(){
    FILE *arProductos;

    // abrimos el archivo en modo lectura
    arProductos = fopen("C:\\Users\\Matias\\Desktop\\Fundamentos y Programación\\clase8\\output\\productos.dat", "rb");

    if (arProductos == NULL){ //Controlo si la apertura fue exitosa
        printf("\nNose pudo abrir el archivo!\n");
    }
    else{
        mostrar_datos(arProductos);
        fclose(arProductos);
    }
    return;

}