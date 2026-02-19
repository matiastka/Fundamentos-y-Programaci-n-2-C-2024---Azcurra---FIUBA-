#include <stdio.h>
#define MAX 5
#define APROBO 4

typedef int TvecNotas[MAX];
typedef long TvecPadrones[MAX];

TvecNotas Notas;
TvecPadrones Padrones;

void CargarNotas(TvecNotas Notas, TvecPadrones Padrones, int *ML){
    int i, nota; 
    long padron;
    i = 0;
    printf("Ingrese su padron: ");
    scanf("%i", &padron);
    printf("Ingrese una nota (menor a 0 para terminar): ");
    scanf("%i", &nota);
    
    while ((nota > 0) && (i < MAX)){
        Notas[i] = nota;
        Padrones[i] = padron;
        i++;
        
        printf("Ingrese su padron: ");
        scanf("%i", &padron); // Si se lo escribiera dierctamente como scanf("%l", &Padrones[i]) siempre va con & porque es el elemento y no el arreglo
        
        printf("Ingrese una nota (menor a 0 para terminar): ");
        scanf("%i", &nota);
    }
    *ML = i;
}

void MostrarNotas(TvecNotas Notas, TvecPadrones Padrones, int ML){
    int i;
    for (i = 0; i <= ML; i++){
        if (Notas[i] >= APROBO){
            printf("Padron aprobado: %i\n", Padrones[i]);
        }
    }
}

void main(){
    int ML;
    TvecNotas Notas;
    TvecPadrones Padrones;
    CargarNotas(Notas, Padrones, &ML);
    MostrarNotas(Notas, Padrones, ML);
    return;
}