// Declarando un arreglo bidemnsional de enteros y modificando su contenido

# include <stdio.h>
# define FILAS 2 // Declaro el MF de las filas (MFF)
# define COLUMNAS 3 // Declaro el MF de las columnas (MFC)

typedef int t_mat[FILAS][COLUMNAS]; // Definimos el tipo t_mat que es de tipo entero y que su dimension de filas y columnas esta dado por la ctes FILAS y COLUMNAS respectivamente

void calcular_cuadrados(t_mat mat, int fil, int col){ // Misma funcion que arreglo_vector pero para matriz. 1. El 1er parametro tiene el definido el tipo de dato que es una matriz 2. Necesitamos recorrer la matriz con un for para filas y columnas.
    int i,j;
    for (i = 0; i < fil; i++){ // Recorremos por filas
        for (j = 0; j < col; j++){ // Recorremos por columnas
            mat[i][j] = mat[i][j] * mat[i][j]; // Para acceder al elemento de la matriz y calcular su cuadrado necesito saber su posicion por fila y columna
        printf("\n");
        }
    }
}

void mostrar_datos(t_mat mat, int fil, int col){
    int i, j;
    for (i = 0; i < fil; i++ ){
        for (j = 0; j < col; j++){
            printf("%4i ", mat[i][j]);
        printf("\n");
        }
    }
}

void main(){
    t_mat mat_nros = {{1,2,3}, {4,5,6}};

    mostrar_datos(mat_nros, FILAS, COLUMNAS);
    calcular_cuadrados(mat_nros, FILAS, COLUMNAS);
    printf("\n");
    mostrar_datos(mat_nros, FILAS, COLUMNAS);
}
