/*
Tomando como base el código que está debajo, modificalo para que:
-  los valores del arreglo sean cada uno de los dígitos de tu padrón/legajo 
-  declará un tipo de dato para el arreglo y una constante para su máximo físico.
-  mostrá del último elemento al primer elemento.
*/

# include <stdio.h>

# define MF 6 // Definimos la constante de memoria fisica

typedef int t_vec[MF]; // Definimos el tipo de arreglo entero llamado t_vec que toma el maximo valor fisico + 1

void mostrar_datos(int v[], int ultima_pos) {
    int i;
    for (i = ultima_pos; i >= 0; i--){
        printf("%i", v[i]);
    }
}

void main(){
    int v_nros[] = {1,1,1,5,1,7}; // Definimos el arreglo llamado v_nros

    mostrar_datos(v_nros, MF-1); //Llamamos a la funcion mostrar_datos con parametros v_nros (el arreglo) y MF - 1 que es el ultimo elemento

    return;
}