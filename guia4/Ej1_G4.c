/*
Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada. Informar el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición. 
*/

// Este ejercicio fijas el ML (gracias Aria) que va a ser igual al maximo logico

# include <stdio.h>

void(ValidarIngreso(int *ML)){
    while (*ML <= 0){
        printf("Ingrese el maximo logico que tendra el vector: ");
        scanf("%i", ML);
    }
}

void IngresarValor(float *valor){
    printf("Ingrese un valor a cargar (0 para terminar): ");
    scanf("%f", valor);
}

void CargarDatos(float vector[], int ML){ //Para definir un vector como parametro sin typedef se usa nombre_vector[]
    int contador;
    float valor;
    
    contador = 0;
    
    IngresarValor(&valor);
    
    while ((valor != 0) && (contador < ML)){
        vector[contador] = valor; // Guardamos el valor en cada posicion del vector (empieza desde 0 hasta su Maximo Fisico)
        contador++;
        
        if (contador < ML){
            IngresarValor(&valor);
        }
    }
}

void MostrarDatos(float vector[], int ML){
    int contador;    
    
    // Forma 1:
    for (contador = 0; contador < ML; contador++){  // Para poder mostrar los datos, hay que recorrer hasta la ultima posicion: contador <= ML-1 == contador < ML
        printf("El contenido del vector en la posicion %i es: %f\n", contador, vector[contador]);
    }

    /* Forma 2: 
    ...
    int ultima_posicion;
    ultima_posicion = ML-1;
    for (contador = 0; contador < utltima_posicion; contador++){ 
        printf("El contenido del vector en la posicion %i es: %f\n", contador, vector[contador]);
    }
    ...
    */

}

void main(){
    int ML;

    ValidarIngreso(&ML); // Definimos Maximo Logico (externo)
    
    float vector[ML]; // Definimos al vector sin typedef
    
    CargarDatos(vector, ML);

    MostrarDatos(vector, ML);
}