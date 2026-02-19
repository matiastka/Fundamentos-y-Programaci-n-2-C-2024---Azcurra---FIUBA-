// En este ejemplo veremos como crear un archivo binario y cargarlo con datos.

# include <stdio.h>

typedef struct{ //Definimosel struct para cargar los datos
    int codigo;
    char descripcion[30];
    float cantidad;
} t_regProducto;

void cargar_datos(FILE *arProductos){ //pasamos el puntero del archivo y hacemos la funcion cargar

    t_regProducto rProducto;

    printf("Codigo de articulo: ");
    scanf("%d", &rProducto.codigo);
    fflush(stdin);

    while (rProducto.codigo != 0){ 
        printf("Descripcion: ");
        scanf("%30{^\n}s", rProducto.descripcion);
        fflush(stdin);

        printf("Cantidad en Stock: ");
        scanf("%f", &rProducto.cantidad);
        fflush(stdin);

        fwrite(&rProducto, sizeof(rProducto), 1 ,arProductos); //Empezamos a grabar los datos en la variable rProducto que es el registro. Lo hacemos de forma secuencial.

        printf("\nCodigo de articulo: ");
        scanf("%d", &rProducto.codigo);
        fflush(stdin);
    }
}
void main(){
    FILE *arProductos;
    arProductos = fopen("productos.dat", "wb"); //Inventamos el nombre del archivo 

    if (arProductos == NULL){ //Si devuelve null es porque no se pudo abrir el archivo. Se chequea contra null porque sino devuelve la direccion del puntero
        printf("\nNo se pudo crear el archivo!\n");
    }
    else{ // Si lo pudo abrir
        cargar_datos(arProductos); //Llama la funcion cargar:datos
        fclose(arProductos);
    }
    return 0;
}
