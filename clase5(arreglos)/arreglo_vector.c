// Declarando un arreglo vector de enteros y modificando su contenido (con todo lo visto)

// Todas las funciones son de tipo void porque no devuelven nada

# include <stdio.h>
# define ULTIMO 4 // ULTIMO juega como ML

typedef int t_vec[ULTIMO + 1]; // ULTIMO + 1 = MF

void calcular_cuadrados(t_vec v_nros, int ult_pos){
    int i;
    for (i = 0; i <= ult_pos; i++){
        v_nros[i] = v_nros[i] * v_nros[i]; // Para calcular el cuadrado: Es el arreglo de esa posicion asignandole el mismo elemento mutliplicado por si mismo.
    }
}

void mostrar_datos(t_vec v_nros, int ult_pos){ // Misma funcion que arreglo_vector_simple pero hecha con typedef
    int i;
    for (i = 0; i<= ult_pos; i++){
        printf("%i \n", v_nros[i]);
    }
}

void main(){
    t_vec v_nros = {2,4,6,8,10};
    printf("\nVector Original\n");
    mostrar_datos(v_nros, ULTIMO);

    calcular_cuadrados(v_nros, ULTIMO);

    printf("\nVector Modificado\n");
    mostrar_datos(v_nros, ULTIMO);

    printf("\n");
    return;
}