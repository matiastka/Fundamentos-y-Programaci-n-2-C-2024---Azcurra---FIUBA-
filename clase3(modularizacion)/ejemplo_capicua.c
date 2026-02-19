/*
Leer un numero y mostrar si es capicua. 
Hint: Para saber si un numero es capicua o no hay que hacer lo siguiente:
La division del numero por 10 hasta que el cociente sea menor a 10, haciendo (Inversion + resto) * 10 [hasta que el cociente sea menor a 10 <----> sea menor a 9]
Ejemplo: 
1234 / 10 = 123 con resto 4 --> Inversion: (0 + 4) * 10 = 40
123 / 10 = 12 con resto 3 --> Inversion: (40 + 3) * 10 = 430
12 / 10 = 1 con resto 2 --> Inversion: (430 + 2) * 10
1 / 10 <----> cociente es menor a 10 --> Inversion: (4320 + 1) = 4321 != 1234 
Entonces 1234 no es capicua
Ejemplo 2:
12321 / 10 = 1232 con resto 1 --> Inversion: (0 + 1) * 10 = 10
1232 / 10 = 123 con resto 2 --> Inversion: (10 + 2) * 10 = 120
123 / 10 = 12 con resto 3 --> Inversion: (120 + 3) * 10 = 1230
12 / 10 = 1 con resto 2 --> Inversion: (1230 + 2) * 10 = 12320
1 / 10 (cociente < 10) --> Inversion: (12320 + 1) = 12321 = 12321
Entonces es capicua
*/

# include <stdio.h>

void main(){
    int N, Aux, Inv;

    printf("Ingrese un numero: ");
    scanf("%i", &N);
    
    Aux = N;
    
    Inv = (Aux % 10); 
    
    while (Aux > 9){
        Aux = Aux / 10;
        Inv = (Inv * 10) + (Aux % 10);
    }
    if (N == Inv){
        printf("Es Capicua");
    }
    else{
        printf("No es Capicua");
    }
}