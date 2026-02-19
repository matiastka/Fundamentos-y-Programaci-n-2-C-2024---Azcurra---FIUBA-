/*
Leer un número N Positivo y luego leer una serie de N números positivos. 
Para los números que sean primos mostrar el Factorial y los que no lo sean mostrar divisores
*/

# include <stdio.h>

# include <stdbool.h>

void Mostrar_Divisores(int numero){ // funcion void y con parametro por valor
    int i;
    printf("Los divi de num: %d son", numero );
    for (i = 1; i <= numero; i++){
        if (numero%i == 0){
            printf("%i \n", i);
        }
    }
    priintf("\n");
}   

int Factorial (int numero) { // funcion con tipo y con parametro por valor
    int i, resultado;
    resultado = 1;
    for (i=1; i<=numero ; i++){
        resultado *= i;
    }
    return resultado;
}

bool Es_Primo(int n){ // funcion con tipo y con parametro por valor
    bool tiene_divisor;
    int i;
    tiene_divisor = false;
    i=2;
    while(i<=(n/2) && !tiene_divisor){
        if (n % i == 0)
            tiene_divisor = true;
        else
          i++;
    }
    return !tiene_divisor;
}
void Leer_Valido(int *num){ // funcion con tipo y con parametro por referencia
    do{
        printf("Ingrese un Numero Positivo: ");
        scanf("%d", num );
    } while(*num < 0);
}
int main(){
    int MAX, N, i;
   
      Es_Valido(&MAX);
      for (i = 1; i <= MAX; i++){
        Leer_Valido(&N);
        if (Es_Primo(N)){
            printf("%d",Factorial(N));
        }
        else{
            Mostrar_Divisores(N);
        }
    }   

    return 0;
}