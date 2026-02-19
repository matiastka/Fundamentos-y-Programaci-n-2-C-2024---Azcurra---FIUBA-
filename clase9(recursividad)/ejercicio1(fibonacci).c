# include <stdio.h>

// forma 1:
int fibonacci_V1(int numero){ // Este es un problema 'complejo' de recursividad, no se va a tomar algo tan dificil
    if (numero == 0){ // caso base
        return 0;
    }
    else{
        if(numero == 1){ // caso base
            return 1;
        }
        else{ // caso recursivo (es igual que la definicion matematica)
            return fibonacci_V1(numero-1) + fibonacci_V1(numero-2);
        }
    }
}
// Forma 2:
int fibonacci_V2(int numero){ 
    if(numero <= 1){ // caso base
        return 1;
    }
    else{ // caso recursivo 
        return fibonacci_V2(numero-1) + fibonacci_V2(numero-2);
    }
}

/* 
Definicion matematica:
f0 = 0
f1 = 1
fn = fn-1 + fn-2
*/