# include <stdio.h>

long superficie_rectangulo(int lado_1, int lado_2){
    long superficie;
    superficie = lado_1 * lado_2;
    return superficie;
}

void main(){
    long sup;
    sup = superficie_rectangulo(10,15);
    printf("La superficie es: %lu ", sup);
    return;
}