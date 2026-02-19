// Forma clase:
#include<stdio.h>

void intercambiarEnteros(int* pnum1, int* pnum2){
	int temporal = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temporal;
}


int main()
{
	int numero1 = 50, numero2 = 85;
	
	printf("Antes de llamar a la funcion, numero1 es %d y numero2 es %d\n", numero1, numero2);

	intercambiarEnteros(&numero1, &numero2);

	printf("Despues de llamar a la funcion, numero1 es %d y numero2 es %d\n", numero1, numero2);
}

// Mi forma:
# include <stdio.h>

void intercambiarEnteros(int *num1, int *num2){
    int temporal;
    temporal = *num1;
    *num1 = *num2;
    *num2 = temporal;
}

int main(){
    int numero1 = 50, numero2 = 85;
    printf("Antes de llamar a la funcion, numero1 es %d y numero2 es %d\n", &numero1, &numero2);
    intercambiarEnteros(&numero1, &numero2);

    return 1;
}