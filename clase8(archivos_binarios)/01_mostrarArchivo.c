// En este ejemplo veremos como mostrar los datos que fueron guardados.

# include <stdio.h>

typedef struct{ //Declaramos la estrucutra para definir el tipo de estrucutra que vamos ea leer
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void mostrar_datos(FILE *arProductos){ //Mostrar datos recibe mi archivo
    t_regProducto rProducto;

    fread(&rProducto, sizeof(rProducto), 1, arProductos); //Leemos el archivo (arProductos es el archivo) usando la estructura del registro (rProducto es la estructura)

    printf("\nCodigo \t Descripcion\t\t\tCantidad");

    while ( !feof(arProductos)){ //Se fija hasta llegar al final del archivo
        printf("\n %d \t %-30s %8.2f", rProducto.codigo, rProducto.descripcion, rProducto.cantidad); //Va imprimiendo el contenido del archivo a partir del struct
        fread(&rProducto, sizeof(rProducto), 1, arProductos);
    }
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