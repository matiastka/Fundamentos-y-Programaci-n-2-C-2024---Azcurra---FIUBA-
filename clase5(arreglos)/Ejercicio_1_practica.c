
#include <stdio.h>
#define MAX 5
#define APROBO 4
typedef int Tvec[MAX];

void CargarNotas(Tvec Vec, int *ML){
    int i, Nota;
    printf("Ingrese notas (0 para finalizar): ");
    scanf("%i",&Nota);
    i=0;
    while ((Nota>0) && (i<MAX)){ // Con i < MAX hace que el contador sea igual a MAX, porque i se incrementa dentro del ciclo
        Vec[i]=Nota; 
        i++;
        printf("Ingrese notas (0 para finalizar): ");
        scanf("%i",&Nota);
    }
    *ML=i; // Como i = MF entonces ML sera igual a MF
    printf("El contador es: %i\n El MF es: %i\n", i, MAX);
}

void MostrarAprobados(Tvec vec, int ML){
    int i;
    printf("Las notas aprobadas son: ");
    for (i = 0; i < ML; i++){ // Como queremos mostrar las notas dentro del rango del vector y como ML = MF entonces se recorre hasta ML (osea ML - 1 = MF - 1 = Ultimo elemento [solo en casos asi van a ser iguales ML y MF])
        if (vec[i]>= APROBO){
            printf("%i\n", vec[i]);
        }
    }
}

int main(){
    Tvec Vec;
    int ML=0; 
    CargarNotas(Vec, &ML);
    MostrarAprobados(Vec, ML);
    return 0 ;	
}
