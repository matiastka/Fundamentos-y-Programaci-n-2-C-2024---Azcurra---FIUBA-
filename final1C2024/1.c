/*
Una libreria posee un archivo denominado Stock.dat cuyos registros contienen el codigo de libro (entero), el titulo (30 caracteres), el stock actual de dicho libro (entero), 
el stock minimo de dicho libro (entero) y el precio unitario (real). Dicho archivo no esta ordenado y "NO ENTRA" en memoria en su totalidad.
Se pide desarrollar un programa modular en lenguaje C que procese este archivo y que permita:
a) genera una tabla llamada Oferas que contenga solo los libros cuyo stock actual esta por encima del doble del stock minimo. Incluir en la tabla los siguiente campos:
- El codigo del libro(entero)
- El titulo del lbro (30 caracteres)
- La cantidad de libros a ofertar (entero, a lo sumo se pueden ofertar la mitad de los libros que estan por sobre el stock minimo)
- El precio unitario de oferta (real, el descuento de la ofera es del 30%)
Asumir que esta tabla tendra como maximo 100 registros y CABE EN MEMORIA

b) Ordenar la tabla Ofertas ascendentemente por titulo del libro
*/

# include <stdio.h>
# include <string.h>
# define MAX_REG 100

typedef struct{
    int codigo;
    char titulo[30];
    int stock_actual;
    int stock_minimo;
    float precio;
} T_libro;

typedef struct{
    int codigo;
    char titulo[30];
    int cant_libro;
    float precio;
} T_oferta;

typedef T_oferta Tvecofertas[MAX_REG];

void generar_tabla(FILE *archivo, Tvecofertas ofertas, int *ML){
    T_libro libro;
    T_oferta oferta;
    int i;
    i = 0;

    fread(&libro, sizeof(libro), 1, archivo);

    while ((!feof(archivo)) && (i < MAX_REG)){
        if (libro.stock_actual > 2 * libro.stock_minimo){
            ofertas[i].codigo = libro.codigo;
            strcpy(ofertas[i].titulo, libro.titulo);
            ofertas[i].cant_libro = libro.stock_minimo / 2;
            ofertas[i].precio = libro.precio * 0.3;
            i++;
        }
        fread(&libro, sizeof(libro), 1, archivo);
    }
    *ML = i;
}

void ordenar_tabla_por_titulo(Tvecofertas ofertas, int ML){
    int i,j;
    T_oferta aux;

    for (i = 0; i < ML; i++){
        for(j = 1; j < ML - i; j++){
            if(strcmp(ofertas[j].titulo, ofertas[j+1].titulo) > 0){
                aux = ofertas[j];
                ofertas[j] = ofertas[j+1];
                ofertas[j+1] = aux;
            }
        }
    }
}

void main(){
    Tvecofertas ofertas;
    int ML;
    FILE *archivo;

    archivo = fopen("Stock.dat", "rb");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo");
    }
    else{
        generar_tabla(archivo, ofertas, &ML);
        fclose(archivo);
        ordenar_tabla_por_titulo(ofertas, ML);
    }
}