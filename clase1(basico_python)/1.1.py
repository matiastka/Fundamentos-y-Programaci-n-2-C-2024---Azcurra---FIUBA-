#1. Ingresar un numero entero y decir: 
# a) es par o impar
# b) es mayor, menor o igual a cero.

# Programa par/impar
numero = int(input("Ingrese un número entero: "))
if numero % 2 == 0:
    print("Es par")
else:
    print("Es impar")
# Fin programa

# Programa mayor, menor o igual a 0
if numero > 0:
    print("El número es mayor a 0")
else:
    if (numero < 0):
        print("El numero es menor a 0")
    else:
        print("El número es 0")
# Fin programa