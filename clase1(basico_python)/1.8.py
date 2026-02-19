# 8. Dado un mes escribir la cantidad de dias de dicho mes.

# Programa representar los dias de un mes

validar_mes = True

while validar_mes:
    mes = (input("Ingrese un mes del año: ")).lower()
    if mes == "febrero":
        print("Tiene 29 dias si es biciesto. 28 de no serlo")
        validar_mes = False
    elif mes == "abril" or mes == "junio" or mes == "septiembre" or mes == "noviembre":
        print("Tiene 30 dias")
        validar_mes = False
    elif mes == "enero" or mes == "marzo" or mes == "mayo" or mes == "julio" or mes == "octubre" or mes == "diciembre":
        print("Tiene 31 dias")
        validar_mes = False
    else:
        print("El mes ingresado no existe, vuelva a intentarlo")



# Fin programa