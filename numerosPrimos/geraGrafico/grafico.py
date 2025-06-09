import matplotlib.pyplot as plt
import csv

n_values = []
tempos = []

with open("numerosPrimos/geraGrafico/resultados.csv", "r") as arquivo:
    leitor = csv.reader(arquivo)
    next(leitor)
    for linha in leitor:
        n = int(linha[0])
        tempo = float(linha[1])

        n_values.append(n)
        tempos.append(tempo)

plt.figure(figsize=(8, 5))
plt.plot(n_values, tempos, marker='o', linestyle='-', color='blue')

plt.title('Tempo de Execução vs Tamanho da Entrada')
plt.xlabel('Tamanho da entrada (n)')
plt.ylabel('Tempo de execução (segundos)')

plt.grid(True)
plt.tight_layout()
plt.ylim(0, 2)

plt.show()