# include <stdio.h>

# define MAX_NOM 50

typedef char string[MAX_NOM];

typedef struct{ 
    int DNI;
    string Nombre;
} Tregistro;

void main(){
    FILE *archivo;
    Tregistro registro;

    archivo = fopen("archivo.dat", "w");    

    frwite(&registro, sizeof(Tregistro), 1, archivo); // Se pasa la info del struct al archivo

    fclose(archivo);
}