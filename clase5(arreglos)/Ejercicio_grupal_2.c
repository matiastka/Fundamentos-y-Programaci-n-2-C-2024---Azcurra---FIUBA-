//Ingresar una serie de números, entre 0 y 999,  finalizada con un numero negativo y mostrar la cantidad de veces que aparece cada número en la serie
#include <stdio.h>

#define MAX 1000

typedef int Tvec[MAX];

void Inicializar(Tvec vec){
    int i;
    for (i = 0; i < MAX; i++){
        vec[i] = 0;
    }
}

void LeerValidar(int *num){
    printf("Ingrese un numero positivo: ");
    scanf("%i", num);
    while (*num < 0){
        printf("Ingrese un numero positivo: ");
        scanf("%i", num);
    }
}
void CargarNumeros(Tvec vec){
    int num;
    printf("Ingrese un numero entre 0 y %i: \n", MAX-1);
    LeerValidar(&num);
    while (num >= 0){
        vec[num]++;
        printf("Ingrese un numero para cargar al vector (negativo para finalizar): ");
        scanf("%i", &num);
    }
}

void MostrarNumeros(Tvec vec){
    int i;
    for (i = 0; i< MAX; i++){
        printf("La cantidad de: %i\t %i\n", i, vec[i]);
    }
}

void main(){
    Tvec vec;
    Inicializar(vec);
    CargarNumeros(vec);
    MostrarNumeros(vec);
    return;
}
