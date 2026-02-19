# include <stdio.h>
# include <string.h>
# define MAX_NOM 50

typedef char String[MAX_NOM];

typedef struct {
    String Nombre; // Ya definimos los string con un Maximo de 50 caracteres
    int Codigo;
    float Importe;
} Treg; // Definimos el tipo de registro llamado TReg (de tipo registro)

void Cargar(Treg *registro){ // Forma de cargar un registro usando la funcion cargar (como es un registro se pasa por referencia el parametro)
    printf("Ingrese el nombre del producto (sin espacios): ");
    scanf("%s", (*registro).Nombre);

    printf("\nIngrese el codigo del producto: ");
    scanf("%i", &((*registro).Codigo)); // El * referencia al registro y el & hace referencia al codigo que es un entero (no va si es un tipo arreglo)

    printf("\nIngrese el importe del producto: ");
    scanf("%f", &((*registro).Importe));
}

void Mostrar(Treg registro){
    printf("Nombre = %s\n", registro.Nombre);

    printf("Codigo = %i\n", registro.Codigo);

    printf("Importe = %f\n", registro.Importe);
}

int main(){
    Treg registro;
    
    Cargar(&registro); // Los registros se pasan por referencia porque es un struct (es diferente a las tablas (vector de structs))

    Mostrar(registro);

    return 0;
}