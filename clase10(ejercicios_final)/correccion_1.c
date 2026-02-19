/*
Una librería posee un archivo denominado Stock.dat, cuyos registros contienen el código de libro (entero), 
el código de la editorial (entero), el stock actual de dicho libro (entero) y el stock mínimo de dicho libro (entero). 
Dicho archivo no está ordenado y no “entra” en memoria en su totalidad. 

Se pide desarrollar un programa en lenguaje C que procese este archivo y que permita: 
Generar una tabla llamada Pedidos que contenga toda la información de aquellos libros cuyo stock actual está por debajo del stock mínimo.  
Asumir que esta tabla tendrá como máximo 100 registros, razón por la cual “ENTRA” EN MEMORIA.
*/

# include <stdio.h>

# define MAX 100

typedef struct {
    int codigo_libro;
    int codigo_editorial;
    int stock_actual;
    int stock_minimo;
} Tlibro;

typedef Tlibro Tpedidos[MAX]; // Esta es la estrucutra de la tabla de los libros

void generar_tabla(FILE *arPedidos, Tpedidos Pedidos, int *ML){
    Tlibro libro;

    *ML = 0;

    fread(&libro, sizeof(libro), 1, arPedidos); // Leemos el archivo guardando los datos en el struct libro, incializamos el contador del archivo 
    
    while (!feof(arPedidos) && (*ML < MAX)){ // Verificamos que no se llegue al fin del archivo y que ML no supere el MAX para no irse fuera de la tabla
        if (libro.stock_actual < libro.stock_minimo){ // Si libro del campo stock actual es menor a camp stock minimo 
            // No es correcto guardar campo por campo el registro sino que se guarda el pedido en la posicion (i) todo el registro
            // Forma correcta para guardar un struct en una tabla (es como algoritmo de ordenamiento de tablas):
            Pedidos[*ML] = libro;  // Guardamos el registro libro en la posicion del ML en la tabla Pedidos.
            (*ML)++; // Incrementamos el ML
        }
        fread(&libro, sizeof(libro), 1, arPedidos); // Avanzamos el contador del archivo 
    }
}

void main(){
    Tpedidos Pedidos; // Es una tabla
    FILE *arPedidos; 

    int ML;

    arPedidos = fopen("stock.dat", "rb");
    if (arPedidos == NULL){
        printf("Error al abrir el archivo Stock.dat\n");
    }
    else{
        generar_tabla(arPedidos, Pedidos, &ML);
        fclose(arPedidos);
        // Faltaria mostar la tabla
    }
}