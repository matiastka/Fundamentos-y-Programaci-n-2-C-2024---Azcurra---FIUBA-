/*
Desarrollar una funcion recursiva en lenguaje C que reciba un arreglo y su maximo logico y devuelva la suma de los elementos que estan en las posiciones pares del arreglo.
*/

int sumar_elementos (int vector[], int ML){
    if (ML <= 0){ // Caso base
        return vector[ML];
    }
    else{
        if (ML % 2 != 0){
            return 0 + sumar_elementos(vector, ML-1);
        }
        else{
            return vector[ML] + sumar_elementos(vector, ML-1);
        }
    }
}
