#include<stdio.h>

void incrementar(int *pnumero){
	//Incrementar en 1
//	*pnumero = *pnumero + 1;
	(*pnumero)++;
}

int main()
{
	int numero = 10;
	printf("Antes de llamar a la funcion, numero es %d\n", numero);
	incrementar(&numero);
	printf("Despues de llamar a la funcion, numero es %d", numero);
}