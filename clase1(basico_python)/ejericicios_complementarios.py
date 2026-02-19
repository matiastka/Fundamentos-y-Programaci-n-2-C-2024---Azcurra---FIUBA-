ejercicio_sin_resolver = True

while ejercicio_sin_resolver:
    elegir_ejercicios = input("Ingrese el ejercicio a resolver: ")

    if (elegir_ejercicios != "1") and (elegir_ejercicios != "2") and (elegir_ejercicios != "3"):
        print("No ingreso correctamente el ejercicio, ingreselo nuevamente.")

    if (elegir_ejercicios == "1"):
        print("1. Escribir un programa Calculadora. Solicite al usuario el ingreso de una operación (+,-,*,/) y 2 números.")
        # 1. Escribir un programa Calculadora. Solicite al usuario el ingreso de una operación (+,-,*,/) y 2 números.

        # Programa Calculadora
        operacion = input("Ingrese una operación (+, -, *, /): ")
        num1 = int(input("Ingrese el 1er número: "))
        num2 = int(input("Ingrese el 2do número: "))

        validador = True
        while validador:
            if (operacion == "+"):
                suma = num1 + num2
                print(f"El resultado de {num1} + {num2} es {suma}")
                validador = False
            elif (operacion == "-"):
                resta = num1 - num2
                print(f"El resultado de {num1} - {num2} es {resta}")
                validador = False
            elif (operacion == "*"):
                multiplicacion = num1 * num2
                print(f"El resultado de {num1} * {num2} es {multiplicacion}")
                validador = False
            elif (operacion == "/"):
                if (num2 == 0):
                    print("El 2do número no puede ser 0.")
                    num2 = int(input("Ingrese otro número: "))
                else: 
                    division = num1 / num2
                    print(f"El resultado de {num1} / {num2} es {division}")
                    validador = False
            else:
                print("No ingreso una operación correcta, por favor ingresela nuevamente")
                operacion = input("Ingrese una operación (+, -, *, /): ")
        
        # Fin Programa
        
        ejercicio_sin_resolver = False

    elif (elegir_ejercicios == "2"):
        print("2. Ingresar una serie de números finalizada con un numero negativo y por cada numero ingresado calular su factorial")
        # 2. Ingresar una serie de números finalizada con un numero negativo y por cada numero ingresado calular su factorial

        # Programa Calcular Factorial
        
        numero = int(input("Ingrese un número (numero negativo para finalizar): "))
        factorial = 1 # El factorial empieza en 1 porque es el neutro multiplicativo.

        if numero < 0:
            print("No existe factorial de un numero negativo")

        while (numero >= 0):
            for i in range(numero, 0,-1): # Forma para hacer un ciclo for en orden inverso: for i in range (numero_max, numero_min, -1)
                factorial = factorial * i
            print(f"El factorial de {numero} es {factorial}")
            factorial = 1 # Reinicio el valor del factorial
            numero = int(input("Ingrese un número (numero negativo para finalizar): "))
        
        # Fin Programa
        
        ejercicio_sin_resolver = False

    elif (elegir_ejercicios == "3"):
        print("3. Solicitar el ingreso de un valor y luego informar si es primo o no lo es.")
        # 3. Solicitar el ingreso de un valor y luego informar si es primo o no lo es.

        # Programa primo/no primo (pseudoayudado para saber si es primo)

        es_primo = True
        Numero = int(input("Ingrese un número: "))
        if (Numero <= 2) or (Numero % 2 == 0):
            print(f"{Numero} no es primo")
        else:
            for i in range(3, Numero):
                if (Numero % i == 0):
                    print(f"No es primo porque es divisible por {i}")
                    es_primo = False
            if es_primo: # ayudado por aria (para salir sin usar un break o return)
                print(f"{Numero} es primo" )
            else: # ayudado por aria (para salir sin usar un break o return)
                print(f"Por lo tanto, {Numero} no es primo")
        
        # Fin Programa

        ejercicio_sin_resolver = False
    


        
