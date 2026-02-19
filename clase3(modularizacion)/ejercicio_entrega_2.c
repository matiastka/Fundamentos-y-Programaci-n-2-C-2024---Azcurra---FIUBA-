/*
Escribir una función que reciba dos valores enteros y devuelva la suma de los valores entre el menor y el mayor de dichos números, incluídos.
No debe imprimir el valor, debe solamente devolverlo.

Invocarla para los valores (-2, 2); (5, -10); (0, -4); (10, 15) y (-3, -25); mostrando en cada caso lo que devuelve.

Para la construcción del programa, podés utilizar el editor del intérprete o el ide que prefieras.

Luego copia y pega lo que hayas hecho en la caja de texto de esta actividad y efectuá la entrega de la misma.
*/

# include <stdio.h>

int sumar_valores(int valor1, int valor2){
    int contador, resultado;
    resultado = 0;
    if ( valor1 > valor2){
        for (contador = valor2; valor1 >= contador; contador++){
            resultado = resultado + contador; // Forma alternativa: resulado += contador
        }
    }
    if (valor2 > valor1) {
        for (contador = valor1; valor2 >= contador; contador++){
            resultado = resultado + contador;
        }
    }
    return resultado;
} // Copiar segunda forma del video

void main(){
    int suma1, suma2, suma3, suma4, suma5;
    suma1 = sumar_valores(-2,2);
    suma2 = sumar_valores(5,-10);
    suma3 = sumar_valores(0,-4);
    suma4 = sumar_valores(10,15);
    suma5 = sumar_valores(-3,-25);
    printf("La suma de (-2,2) es: %i\n", suma1);
    printf("La suma de (5,-10) es: %i\n", suma2);
    printf("La suma de (0,-4) es: %i\n", suma3);
    printf("La suma de (10,15) es: %i\n", suma4);
    printf("La suma de (-3,-25) es: %i\n", suma5);
    return;
}