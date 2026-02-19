/*
Desarrollar una función recursiva que comprube si un numero pasado como parámetro es capicúa (no resuelve el problema)
*/

# include <stdio.h>
# include <stdbool.h>

bool ver_capicua(int numero, int invertido, int original){ // Es una mezcla del codigo de conseguir un numero invertido con si es capicua
    if (numero < 10){ // Caso base
        invertido = (invertido * 10) + numero; // invertido guarda el invertido antes (con todos los digitos menos el primero del numero original) y le sumamos el original (en la posicion faltante)
        if (invertido == original){
            return true;
        }
        else{
            return false;
        }
    }
    else{ // Caso recursivo
        return ver_capicua((numero/10), (invertido * 10) + (numero%10), original);  
    }
}

void main(){
    int numero, invertido;
    bool resultado;

    numero = 11;
    invertido = 0;
    
    resultado = ver_capicua(numero, invertido, numero);

    if (resultado == true){
        printf("El numero %i es capicua.", numero);
    }
    else{
        printf("El numero %i no es capicua.", numero);
    }
}