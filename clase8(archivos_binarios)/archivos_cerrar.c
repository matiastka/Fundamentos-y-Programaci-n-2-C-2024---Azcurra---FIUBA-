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

    archivo = fopen("archivo.dat", "r");
    fread(&registro, sizeof(Tregistro), 1, archivo);
    if (feof(archivo)){
        printf("Fin");
    }
    else{
        printf("Continuar");
    }
    fclose(archivo);
}