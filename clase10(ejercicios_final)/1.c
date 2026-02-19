/*
Una librería posee un archivo denominado Stock.dat, cuyos registros contienen el código de libro (entero), 
el código de la editorial (entero), el stock actual de dicho libro (entero) y el stock mínimo de dicho libro (entero). 
Dicho archivo no está ordenado y no “entra” en memoria en su totalidad. 

Se pide desarrollar un programa en lenguaje C que procese este archivo y que permita: 
Generar una tabla llamada Pedidos que contenga toda la información de aquellos libros cuyo stock actual está por debajo del stock mínimo.  
Asumir que esta tabla tendrá como máximo 100 registros, razón por la cual “ENTRA” EN MEMORIA.
*/

# include <stdio.h>
# define MAX_registros 100

typedef struct {
    int codigo_libro;
    int codigo_editorial;
    int stock_actual;
    int stock_minimo;
} Tlibro;

typedef Tlibro Tveclibros[MAX_registros]; // Definimos el vector del struct Tlibro (esto define una tabla)

void Cargar_Archivo(FILE *archivo){ // Para probar si anda (NO ME LO PIDEN)
    Tlibro libro;

    printf("Ingrese el codigo del libro (0 para terminar): ");
    scanf("%i", &libro.codigo_libro);

    while (libro.codigo_libro != 0){
        printf("Ingrese el codigo de la editorial: ");
        scanf("%i", &libro.codigo_editorial);

        printf("Ingrese el stock actual: ");
        scanf("%i", &libro.stock_actual);

        printf("Ingrese el stock minimo: ");
        scanf("%i", &libro.stock_minimo);

        fwrite(&libro, sizeof(libro), 1, archivo);

        printf("Ingrese el codigo del libro (0 para terminar): ");
        scanf("%i", &libro.codigo_libro);
    }
}

void Cargar_tabla(FILE *archivo, Tveclibros tabla_pedidos, int *ML){
    Tlibro libro;

    int contador, valor;

    contador = 0;

    fread(&libro, sizeof(libro), 1, archivo);
    
    printf("El valor es: %i\n", 2 * libro.stock_actual);

    while ((!feof(archivo)) && (contador < MAX_registros)){ // El contador < MAX se tiene que hacer en el while para no irse fuera de la tabla y verificamos no llegar al fin de archivo
        if (libro.stock_actual < libro.stock_minimo){ // Consultar si se guarda la tabla como un algoritmo de ordenamiento de tabla o guardado de 1 x 1
            // Forma correcta:
            tabla_pedidos[contador] = libro;
            /* Forma incorrecta
            tabla_pedidos[contador].codigo_libro = libro.codigo_libro; // No es correcto guardar campo por campo el registro sino que se guarda el pedido en la posicion (i) todo el registro
            tabla_pedidos[contador].codigo_editorial = libro.codigo_editorial;
            tabla_pedidos[contador].stock_actual = libro.stock_actual;
            tabla_pedidos[contador].stock_minimo = libro.stock_minimo;
            */
            contador++;
        }
        fread(&libro, sizeof(libro), 1, archivo);
    }
    *ML = contador;
}

void Mostrar_pedido(Tlibro pedido){
    printf("%i\t\t", pedido.codigo_libro);
    printf("%i\t\t\t", pedido.codigo_editorial);
    printf("%i\t\t", pedido.stock_actual);
    printf("%i\n", pedido.stock_minimo);
}

void Mostrar_tabla_pedidos(Tveclibros tabla_pedidos, int ML){
    
    int contador;

    printf("Codigo libro\tCodigo editorial\tStock actual\tStock minimo\n");

    for(contador = 0; contador < ML; contador++){
        Mostrar_pedido(tabla_pedidos[contador]);
        printf("\n");
    }
}

void main(){
    FILE *archivo;
    Tveclibros tabla_pedidos;

    /* Para probar si anda: 
    archivo = fopen("Stock.dat", "wb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        Cargar_Archivo(archivo);
        fclose(archivo);
    }
    */
    int ML;

    archivo = fopen("Stock.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo.");

    }
    else{
        Cargar_tabla(archivo, tabla_pedidos, &ML);
        fclose(archivo);
        Mostrar_tabla_pedidos(tabla_pedidos, ML);
    }
}