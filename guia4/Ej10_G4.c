/*
Escribir un programa que cargue 2 (dos) matrices y sus dimensiones, las
multiplique en caso de ser posible o devuelva una señal si la operación no
puede realizarse.
*/

# include <stdio.h>

# define FILAS_A 2
# define COLUMNAS_A 2
# define FILAS_B 2
# define COLUMNAS_B 2

typedef int Tmat_Resultado[FILAS_A][COLUMNAS_B];
typedef int TmatA[FILAS_A][COLUMNAS_A];
typedef int TmatB[FILAS_B][COLUMNAS_B];

void CargarDatos_A(TmatA Matriz){
    int contador_1, contador_2;

    for(contador_1 = 0; contador_1 < FILAS_A; contador_1++){
        for (contador_2 = 0; contador_2 < COLUMNAS_A; contador_2++){
            printf("\nIngrese un valor entero para cargar a la matriz en la posicion [%i][%i]: ", contador_1, contador_2);
            scanf("%i", &Matriz[contador_1][contador_2]); // Forma 1 de cargar un numero en la matriz
        }
    }

}

void CargarDatos_B(TmatB Matriz){
    int contador_1, contador_2;

    for(contador_1 = 0; contador_1 < FILAS_B; contador_1++){
        for (contador_2 = 0; contador_2 < COLUMNAS_B; contador_2++){
            printf("\nIngrese un valor entero para cargar a la matriz en la posicion [%i][%i]: ", contador_1, contador_2);
            scanf("%i", &Matriz[contador_1][contador_2]);
        }
    }

}

void MostrarDatos(Tmat_Resultado Matriz){
    int contador_1, contador_2;
    
    for (contador_1 = 0; contador_1 < FILAS_A; contador_1++){
        printf("\n| "); // Esto imprime la barra de la izquierda de la matriz, cada vez que se incia una fila
        for (contador_2 = 0; contador_2 < COLUMNAS_B; contador_2++){
            printf("%i ", Matriz[contador_1][contador_2]);
        }
        printf("|"); // Esto imprime la barra de la derecha de la matriz, cada vez que se termina una fila
    }
}

void MultiplicarMatrices(TmatA A, TmatB B, int Fil_A, int Col_A, int Fil_B, int Col_B, Tmat_Resultado Matriz_Resultante){
    int contador_1, contador_2, contador_3;

    // Incializamos toda la matriz en 0 para que no responda basura
    for (contador_1 = 0; contador_1 < Fil_A; contador_1++){
        for (contador_2 = 0; contador_2 < Col_B; contador_2++){
            Matriz_Resultante[contador_1][contador_2] = 0;
        }
    }

    // Multiplicacion de matrices (pueden ser o no cuadradas) (GRACIAS ARIA)
    for (contador_1 = 0; contador_1 < Fil_A; contador_1++) {
        for (contador_2 = 0; contador_2 < Col_B; contador_2++) {
            for (contador_3 = 0; contador_3 < Col_A; contador_3++) {
                Matriz_Resultante[contador_1][contador_2] += A[contador_1][contador_3] * B[contador_3][contador_2];
            }
        }
    }

}

int main(){
    TmatA Matriz_A;
    TmatB Matriz_B;
    Tmat_Resultado Matriz_Resultante;
    int senial;

    CargarDatos_A(Matriz_A);

    CargarDatos_B(Matriz_B);

    if (COLUMNAS_A != FILAS_B){
        senial = -1; 
        printf("No se puede hacer la multiplicacion entre matrices de %ix%i con %ix%i porque %i != %i", FILAS_A, COLUMNAS_A, FILAS_B, COLUMNAS_B, COLUMNAS_A, FILAS_B);
    }
    else{
        MultiplicarMatrices(Matriz_A, Matriz_B, FILAS_A, COLUMNAS_A, FILAS_B, COLUMNAS_B, Matriz_Resultante);
        
        printf("\nEl Resultado de A * B");
        MostrarDatos(Matriz_Resultante);
        
        senial = 0;
    }
    return senial;

}