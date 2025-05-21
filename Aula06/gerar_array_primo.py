def crivo_de_eratostenes(limite):
    """
    Implementa o Crivo de Eratóstenes para encontrar todos os números primos até um limite.

    Args:
        limite: O número máximo a ser verificado.

    Returns:
        Uma lista de números primos até o limite.
    """
    # Cria uma lista booleana 'eh_primo' onde eh_primo[i] é True se i é primo.
    # Inicializa todos como True, exceto 0 e 1.
    eh_primo = [True] * (limite + 1)
    eh_primo[0] = False
    eh_primo[1] = False

    # Itera de 2 até a raiz quadrada do limite
    # Qualquer número composto N terá pelo menos um fator primo menor ou igual à raiz quadrada de N.
    for p in range(2, int(limite**0.5) + 1):
        # Se eh_primo[p] ainda é True, então p é um número primo
        if eh_primo[p]:
            # Marca todos os múltiplos de p como não primos (False)
            # Começamos de p*p porque múltiplos menores (p*2, p*3, etc.) já teriam sido marcados
            # por primos menores que p (por exemplo, 2, 3, etc.).
            for multiplo in range(p*p, limite + 1, p):
                eh_primo[multiplo] = False

    # Constrói a lista final de números primos
    primos = [i for i, is_prime in enumerate(eh_primo) if is_prime]
    return primos

# Define o limite
limite_superior = 1500

# Obtém a lista de números primos
vetor_primos = crivo_de_eratostenes(limite_superior)

# Imprime os primeiros 20 primos para verificar (opcional)
print("Os primeiros 20 números primos até", limite_superior, ":", vetor_primos[:])

# Imprime o total de números primos encontrados
print("Total de números primos encontrados até", limite_superior, ":", len(vetor_primos))

# Você pode imprimir o vetor completo se desejar, mas pode ser longo.
# print(vetor_primos)