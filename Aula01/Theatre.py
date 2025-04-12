import math
entrada = input().split()
n = int(entrada[0])
m = int(entrada[1])
a = int(entrada[2])

qtd_lajes_n = n // a
if n % a != 0:
    qtd_lajes_n += 1

qtd_lajes_m = m // a
if m % a != 0:
    qtd_lajes_m += 1

qtd_total_lajes = qtd_lajes_n * qtd_lajes_m
print(qtd_total_lajes)