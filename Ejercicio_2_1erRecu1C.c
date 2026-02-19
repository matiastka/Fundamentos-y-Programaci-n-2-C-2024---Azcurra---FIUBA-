/*Desarrollar una funcion que reciba como paramertros un vector de tipo Tvector ya cargado y su respecitivo ML,
y devuelva el arreglo invertido y la cantidad de intercambios que fueron relizados pero cumpliendo las siguientes condiciones.
1. La inversion del vector debe ser sobre si mismo, nose puede usar un vector auxiliar.
2. Si las posiciones a invertir contienen el mismo valor, no deben ser interabmiadas.
3. No tiene que definir CargarDatos solamente llamar a la funcion en su programa

Ejemplo: V = (4, 7, 0, 5, 7, 2, ?, ?, ?, ?) con MF 10 y ML 2
Debemos intercambiar el 4 con el 2, el 0 con el 5 pero no el 7 con el 7. Ademas devolver un 2 para indicar la cantidad de cambios realizados
*/

# include <stdio.h>

# define MAX 1000

typedef int Tvector[MAX];

int InvertirVector(Tvector vector, int ML){ // Por Invertir (0 < i < mitad (mitad = ML/2); )
    int i, mitad, aux, cant_intercambios;

    cant_intercambios = 0;
    mitad = ML/2;

    for (i = 0; i < mitad; i++){
        if (vector[i] != vector[ML-1-i]){ // Se fija si las posiciones a invertir no sea iguales 
            aux = vector[i]; // Se guarda en AUX la posicion inicial
            vector[i] = vector[ML-1-i]; // La posicion inicial guarda La posicion a invertir 
            vector[ML-1-i] = aux; // La posicion a invertir guarda la posicion inical
            cant_intercambios++;
        }
    }
    return cant_intercambios;
}

void MostrarDatos(Tvector vector, int ML, int resultado){
    int i;
    printf("\nLa cantidad de intercambios fueron: %i\n(", resultado);
    for (i = 0; i < ML; i++){
        printf("%i ", vector[i]);
    }
    printf(")");
}

void main(){
    int ML, resultado;

    Tvector vector = {4,7,0,5,7,2};
    ML = 6;
    MostrarDatos(vector, ML, 0);

    resultado = InvertirVector(vector, ML);

    MostrarDatos(vector, ML, resultado);
}