/*
20) Escribir un programa que permita al usuario ingresar los montos de las compras
de un cliente y que al finalizar informe por pantalla el importe total a pagar,
teniendo en cuenta que si éste supera los $1000 se le debe aplicar un 10% de descuento.
Se desconoce la cantidad de datos que se van a ingresar.
La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero).
Se debe validar que no se ingresen montos negativos indicando al usuario monto invalido
*/

int main() {
    int montos_de_compras;
    float descuento, total_a_pagar;
    
    total_a_pagar = 0;
    descuento = 0;

    while (montos_de_compras !=0){ 
        printf("Ingrese el monto a pagar: ");
        scanf("%i", &montos_de_compras);

        if (montos_de_compras < 0){
            printf("Monto invalido, vuelva a ingresarlo: ");
            scanf("%i", &montos_de_compras);
        }
        total_a_pagar = total_a_pagar + montos_de_compras;
    }
    if (total_a_pagar > 1000){
        descuento = total_a_pagar * 0.1; 
        total_a_pagar = total_a_pagar - descuento;
        printf("El total a pagar es: %f", total_a_pagar);
    }
    else{
        printf("El total a pagar es: %f", total_a_pagar);
    }
    return 0;
}