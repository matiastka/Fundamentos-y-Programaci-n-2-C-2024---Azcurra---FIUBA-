/*
4)
Escribir una función que reciba un número y devuelva un valor booleano
indicando si el número recibido es ó no primo. Si desconoce como devolver un
valor booleano, puede devolver 0, en caso de No ser primo; y 1, si lo es.

5)
Tomá la solución del ejercicio anterior y analizá si elegiste el cliclo adecuado, y si
estás evitando realizar ciclos innecesarios.
Por ejemplo, algunas preguntas que te podrías hacer son:
a) Con sólo encontrar un divisor del número a evaluar distinto a uno y a sí
mismo, ya puedo afirmar que el número no es primo, tiene sentido seguir
evaluando más divisores?
b) Teniendo en cuenta que todo número par a excepción del 2, no es primo,
tiene sentido seguir en un ciclo, si al calcular el resto de la división del número a
evaluar por 2, el resultado es cero?
c) Puedo encontrar un divisor del número a evaluar que sea mayor al número a
evaluar dividido 2?
Modificá la función escrita en el punto anterior, para que tenga en cuenta las
situaciones planteadas. 
*/

# include <stdio.h>
# include <stdbool.h>

bool EsPrimo(int numero){ // Ayudado con lo de la clase (copiado de la clase)
    int contador;
    bool resultado;

    resultado = true; 
    contador = 2;

    if (numero <= 1){
        resultado = false;
    }

    if (numero == 2){
        resultado = true;
    }

    if ((numero > 2) && (numero % 2 == 0)){
        resultado = false;
    }
    
    if ((numero > 2) && (numero % 2 != 0)){
        while ((resultado) && (contador <= numero / 2)){ // es contador <= numero / 2 por teorema matematico
            if (numero % contador == 0){
                resultado = false;
            }
            else{
                contador++;
            }
        }
    }
    return resultado;
}

void main(){
    int numero;
    bool resultado;
    printf("Ingrese un numero: ");
    scanf("%i", &numero);

    resultado = EsPrimo(numero);
    printf("El numero %i es primo? %i", numero,  resultado);
}