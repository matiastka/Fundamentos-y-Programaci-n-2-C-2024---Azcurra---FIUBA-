// Mostrar el promedio de notas del curso
// Mostrar todas las notas superiores al promedio calculado

# include <stdio.h>

#define MAXIMO_FISICO 50

typedef int Tvec[MAXIMO_FISICO];

void CargarNotas (Tvec vec, int *ML){
    int i, nota;
    printf("Ingrese notas (terminar en 0): ");
    scanf("%i", &nota);
    i=0;
    while ((nota > 0) && (i < MAXIMO_FISICO)){
        vec[i]=nota;
        i++;
        printf("Ingrese notas (terminar en 0): ");
        scanf("%i", &nota);
    }
    *ML=i;
}

float CalcularPromedio (Tvec vec, int ML){
    int i, total;
    float promedio; 
    total = 0;
    promedio = 0;

    for (i = 0; i < ML; i++){
        total = total + vec[i];
    }
    if (ML > 0)
        promedio = (float)total/ML;
    return promedio;
}

void MostrarMayores(Tvec vec, int ML, float promedio){
    int i;
    printf("Los mayores al promedio son: ");
    for (i = 0; i < ML; i++)
        if (vec[i] >= promedio)
            printf("%i ", vec[i]);
    printf("\n");
}

int main(){
    Tvec vec;
    int ML;
    float promedio;
    ML = 0;
    
    CargarNotas(vec, &ML);
    promedio = CalcularPromedio(vec, ML);
    MostrarMayores(vec, ML, promedio);
}