# include <stdio.h>

# define MAX_NOM 50

typedef char string[MAX_NOM];

typedef struct{ 
    int DNI;
    string Nombre;
} Tregistro;

void main(){
    FILE *archivo;
    Tregistro Registro;

    archivo = fopen("archivo.dat", "r");
}