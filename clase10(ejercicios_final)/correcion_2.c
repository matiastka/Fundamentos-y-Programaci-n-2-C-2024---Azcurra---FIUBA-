
# include <stdio.h>

int EsBinario_F1(int num){ // Forma 1 (es redundante los else recursivo)
    if (num == 0 || num == 1){ // Caso Base parte 1 (si el numero es 1 o 0)
        return 1;
    }
    else{
        if ((num % 10 != 0) && (num % 10 != 1)){ // Caso Base parte 2 (si el digito es distinto de 0 y 1)
            return 0;
        }
        else{
            return EsBinario_F1(num/10); // Caso recursivo
        }
    }
}