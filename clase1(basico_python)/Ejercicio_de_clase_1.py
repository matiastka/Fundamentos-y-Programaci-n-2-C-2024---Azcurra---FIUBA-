# Ej 1: # Escribir un programa que le solicite al usuario el ingreso de un numero e indique si el numero ingresado es par o impar
# Inicio programa par/impar
numero = int(input("Ingrese un número: "))
if numero == 0:
    print("El numero es 0")
if (numero%2 == 0):
    print("el numero es par")
else: 
    print("El numero es impar")
# Fin programa par/impar
#Ej2: # Escribir un programa que le solicite al usuario el ingreso de las medidas de los 3 lados de un triangulo y
# muestre por pantalla  que tipo de triangulo es (equilatero, escaleno, isosceles)
# Inicio programa triangulo
lado_1 = int(input("ingrese medida del 1er lado del trangulo: "))
lado_2 = int(input("ingrese medida del 2do lado del trangulo: "))
lado_3 = int(input("ingrese medida del 3er lado del trangulo: "))

if (lado_1 == lado_2) and (lado_1 == lado_3) and (lado_2 == lado_3):
    print("El triangulo es equilatero.")
else: 
    if (lado_1 == lado_2) or (lado_1 == lado_3) or (lado_2 == lado_3):
        print("El triangulo es isosceles.")
    else:
        print("El triangulo es escaleno.")
# Fin programa triangulo