/*
Escribir un programa modular en C, que solicite el ingreso de un código de producto, y luego muestre los datos asociados al mismo, que se encuentran en el archivo productos.dat que está debajo.
Si el código de producto no existe, debe mostrarse el mensaje "Código de Producto Inexistente".
El programa debe continuar solicitando el ingreso de códigos de próducto hasta que se ingrese 0.

La estructura de los registros es la siguiente:

typedef struct{
                int codigo;
                char descripcion[30];
                float cantidad;
}t_regProducto;
*/

# include <stdio.h>
# include <string.h>
# include <stdbool.h>

typedef struct{
    int codigo;
    char descripcion[30];
    float cantidad;
} Tproducto;

int main(){
    FILE *archivo; 
    Tproducto producto;

    int codigo_buscado;
    bool encontrado;
    
    encontrado = false;

    archivo = fopen("productos.dat", "rb");

    if (archivo == NULL){
        printf("El archivo no se pudo abrir");
    }
    else{
        printf("Ingrese el codigo del producto que estas buscando (0 para finalizar): ");
        scanf("%i", &codigo_buscado);

        while (codigo_buscado != 0){

            fread(&producto, sizeof(producto), 1, archivo); // La lectura se tiene que hacer dentro del while del codigo para que no me imprima 2 veces el ultimo elemento. Esto inicia correctamente el contador del archivo
            
            while (!feof(archivo)){
                if (codigo_buscado == producto.codigo){
                    encontrado = true;
                    printf("Del producto buscado\nSu descripcion es: %s\nLa cantidad del mismo es: %f", producto.descripcion, producto.cantidad);
                }
                fread(&producto, sizeof(producto), 1, archivo);
            }
            if (encontrado == false){
                printf("Código de Producto Inexistente\n");
            }

            fclose(archivo);
            
            encontrado = false;  // Reiniciamos el encontrado

            archivo = fopen("productos.dat", "rb"); // Volvemos a abrir el archivo para reiniciar el 'contador' del archivo

            printf("\nIngrese el codigo del producto que estas buscando (0 para finalizar): ");
            scanf("%i", &codigo_buscado);
        }
        fclose(archivo);
    }
    return 0;
}