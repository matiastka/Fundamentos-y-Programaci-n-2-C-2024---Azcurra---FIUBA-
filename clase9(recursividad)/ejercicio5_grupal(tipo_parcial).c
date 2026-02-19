// Mostrar numeros pares entre 1 y X

# include <stdio.h>

// Forma grupal
void MostrarPares_forma_grupal(int X){
    if ((X > 1) && (X%2 == 0)){
        printf("%i\n", X);
    }
    MostrarPares_forma_grupal(X-1);
}

// Forma corregida
void MostrarPares_forma_corregida(int X){
    if (X > 1){
        if (X % 2 == 0){
            printf("%i\n", X);
            MostrarPares_forma_corregida(X-2); // Si es par ya resta de a 2
        }
    }
    else{
        MostrarPares_forma_corregida(X-1);
    }
}


void main(){
    MostrarPares_forma_grupal(17);
    MostrarPares_forma_corregida(17);
}