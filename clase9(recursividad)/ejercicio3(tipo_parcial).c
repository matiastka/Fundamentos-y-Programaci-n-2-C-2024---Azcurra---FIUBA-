// Mostrar X primeros numeros naturales

# include <stdio.h>

void Mostrar_X_Primeros_Naturales_F1(int X){
    
    printf("%i\n", X);

    if (X>1){
        Mostrar_X_Primeros_Naturales_F1(X-1);
    }
}

void Mostrar_X_Primeros_Naturales_F2(int X){
    
    if (X > 1){
        Mostrar_X_Primeros_Naturales_F2(X-1);
    }
    printf("%i\n", X);

}

void main(){
    Mostrar_X_Primeros_Naturales_F1(5); // Imprime del ultimo al primero
    Mostrar_X_Primeros_Naturales_F2(5); // Imprime del primero al ultimo
}