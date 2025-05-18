def troco_algoritmo_guloso(moedas, valor):
    moedas_usadas = []
    for moeda in moedas:
        while valor >= moeda:
            valor -= moeda  # valor = valor - moeda
            moedas_usadas.append(moeda)
    return moedas_usadas


moedas = [4, 3, 1]
valor = 6
resultado = troco_algoritmo_guloso(moedas, valor)
print(f"Moedas usadas:{resultado}")
print(f"Total moedas:{len(resultado)}")
