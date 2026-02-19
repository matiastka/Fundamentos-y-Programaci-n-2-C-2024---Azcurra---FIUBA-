// Desarrollar un programa que calcule y muestre por pantalla la división de 2 números mediante restas sucesivas en forma recursiva. Ambos números deben ser ingresados por el usuario

# include <stdio.h>

int division_por_restas_sucesivas(int dividendo, int divisor){
    if (dividendo < divisor){
        return 0;
    }
    else{
        return 1 + division_por_restas_sucesivas(dividendo - divisor, divisor);
    }
}

void main(){
    int resultado, dividendo, divisor;
    
    dividendo = 4;
    divisor = 2;

    resultado = division_por_restas_sucesivas(dividendo, divisor);
    printf("La division entera de %i con %i es: %i", dividendo, divisor, resultado);
}