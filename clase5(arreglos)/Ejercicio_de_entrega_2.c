/*
Escribir una función, que reciba como primer parámetro un arreglo unidimensional (vector) de valores enteros y como segundo parámetro, 
la cantidad de valores a recorrer (ML) ó la última posición en el arreglo; y devuelva el valor más alto que hay en el arreglo.

Suponga que el arreglo como máximo podrá almacenar hasta 10 valores.

Declare un tipo y máximo físico adecuado.

Para probar su función, incluya los siguientes casos de prueba, con la correspondiente invocación, e imprima lo que devuelve la función.

vec_1 = {8, -4, 7, 8, 0}
vec_2 = { -4, -7, -10}
vec_3 = { 425, -70, 500, 2, 43, 12, -1}
*/

# include <stdio.h>

# define ML 9

typedef int t_vec[ML+1]; // Creo un tipo de arreglo que toma como valor ML+1 = MF

int mostrar_datos(t_vec vector, int ultima_posicion){
    int contador, maximo_valor;
    maximo_valor = vector[0];
    for (contador = 0; contador < ultima_posicion; contador++){
        if (vector[contador] > maximo_valor){
            maximo_valor = vector[contador];
        }
    }
    return maximo_valor;

}
int main(){
    t_vec vec_1 = {8, -4, 7, 8, 0};
    t_vec vec_2 = {-4, -7, -10};
    t_vec vec_3 = {425, -70, 500, 2, 43, 12, -1};

    printf("%i\n", mostrar_datos(vec_1, ML));
    printf("%i\n", mostrar_datos(vec_2, ML));
    printf("%i\n", mostrar_datos(vec_3, ML));
    

    return 0;
}
