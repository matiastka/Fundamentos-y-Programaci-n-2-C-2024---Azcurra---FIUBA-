/*
Desarollar una funcion que reciba como parametros una matriz cuadrada ya cargada en su maxima capacidad y un numero entero, 
que devuelva al modulo invocante la suma de los valores que se encuentran en el triangulo inferior (por debajo de la diagonal principal)
y sean divisibles por el numero recibido.
Ejemplo
Si la matriz fuera de un cant = 4
El numero recibido = 3
La funcion debe devolver 21
DP TS TS TS
27 DP TS TS
14 -9 DP TS
3  5  16 DP 
Donde DP = Elemento en la Diagonal Principal
Donde TS = Elemento en el Triangulo Superior
*/

# include <stdio.h>

# define CANT 25

typedef int Tmatriz[CANT][CANT];

int SumarValoresDelTrianguloInferior(Tmatriz matriz, int numero){
    int i, j, suma;

    suma = 0;

    for (i = 1; i < CANT; i++){
        for (j = 0; j < CANT; j++){
            if ((i > j) && (matriz[i][j] % numero == 0)){ // Valida que revise los numeros por la diagonal inferior y que el valor en la matriz en esa posicion, sea divisible por el numero
                suma = matriz[i][j] + suma;
            }
        }
    }
    return suma;
}

void main(){
    Tmatriz matriz = {{7,8,9,10}, {27,1,2,3}, {14,-9,4,5}, {3,5,16,6}};
    int numero, resultado;

    printf("Ingrese un numero entero: ");
    scanf("%i", &numero);

    resultado = SumarValoresDelTrianguloInferior(matriz, numero);
    printf("El resultado es: %i", resultado);
}