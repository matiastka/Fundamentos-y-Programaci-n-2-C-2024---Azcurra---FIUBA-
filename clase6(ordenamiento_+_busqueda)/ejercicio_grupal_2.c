
#include <stdio.h>
#define MAX_INF 150
typedef int Tinfectados[MAX_INF];

int MenosCasos(Tinfectados vInf, int ML, int num){
    int i, menor, indice;
    menor = 0;
    indice = 0;

    for (i = num; i < ML ; i+=7){
        if (menor > vInf[i] ){
            menor = vInf[i];
            indice = i;
        }
    }
    return indice;
}

void main() {
    Tinfectados vInf;
    int ML;
    int Dia;
    
    ML = 0;
    Tinfectados vector = {2,3,5,7,8,9,10,11,12,13,14,15,16,17};
    printf("El domingo con menos caso fue el dia %d\n", MenosCasos(vector, 13,3));
    printf("El Sabado con menos caso fue el dia %d", MenosCasos(vector, 13,2));
}