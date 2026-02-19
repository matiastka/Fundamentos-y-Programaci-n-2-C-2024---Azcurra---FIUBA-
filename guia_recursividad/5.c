// Desarrollar una función recursiva para obtener en mayor valor en un vector de números enteros.

# include <stdio.h>

# define MF 10

typedef int Tvec[MF];

int obtener_mayor_valor(Tvec vector, int ML, int MAX){ // Logica copiada de la clase
    if (ML < 0){ // Caso base
        return MAX;
    }
    else{
        if (vector[ML] > MAX){ // Caso Recursivo parte 1 (si el vector en la posicion final es)
            return obtener_mayor_valor(vector, ML-1, vector[ML]); // Restamos uno al ML para que vaya del final hasta el principio y guardamos como MX la posicion
        }
        else{ // Caso Recursivo parte 2
            return obtener_mayor_valor(vector, ML-1, MAX);
        }
    }
}

void main(){    // 0  1  2  3  --> ML = 3 --> MF = 4 (#elementos que tiene el vector)
    Tvec vector = {21,14,14,17};
    int ML, resultado, mayor_valor; 

    ML = 3; // recordar que son las posiciones que tiene el vector (empieza en 0)
    mayor_valor = vector[0];

    resultado = obtener_mayor_valor(vector, ML, mayor_valor);

    printf("El mayor valor del vector es: %i", resultado);

}