// Declarando un arreglo undiemensional (vector) de enteros, sin declarar el tipos de datos para los arreglo y la declaracion de la constante

# include <stdio.h>

void mostrar_datos (int v[], int ultima_pos){ // La funcion recibe el arreglo y la ultima_posicion
    int i;
    for (i = 0; i<= ultima_pos; i++){
        printf("%i \n", v[i]);
    }
}

void main(){
    int v_nros[] = {2,4,6,8,10}; // Declaramos por extension el arreglo v_nros de tipo entero

    mostrar_datos(v_nros, 4); // La funcion mostrar_datos toma el arreglo v_nros y la última posicion del arreglo
}