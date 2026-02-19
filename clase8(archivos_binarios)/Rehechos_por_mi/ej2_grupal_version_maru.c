
# include <stdio.h>
# include <string.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
}t_regProducto;

void producto_existente(FILE *archivo) {
    t_regProducto producto;
    int codigo;

    printf("Ingrese código del producto. (0 para terminar)\n");
    scanf("%i", &codigo);
    fread(&producto, sizeof(producto), 1, archivo);
    
    while(codigo != 0) {
        while (!feof(archivo)) {
            if(codigo == producto.codigo) {
                printf("El producto solicitado es:\n");
                printf("CÓDIGO: %i\tDESCRIPCIÓN: %s\tCANTIDAD: %f\n", producto.codigo, producto.descripcion, producto.cantidad);
            } else {
                printf("CÓDIGO DE PRODUCTO INEXISTENTE");
            }

            printf("Ingrese código del producto (0 para terminar)\n");
            scanf("%i", &codigo);
            fread(&producto, sizeof(producto), 1, archivo);
        }
    }

}

int main() {
    FILE *archivo_productos;
    archivo_productos = fopen("productos.dat", "rb");
    producto_existente(archivo_productos);
    fclose(archivo_productos);
    return 0;
}