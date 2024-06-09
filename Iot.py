from flask import Flask, render_template

dados_quedas = [
    ("Macsy", 0, "06/06/2024"),
   
   
]

# Abre um arquivo em modo de escrita
with open("quedas.txt", "w") as arquivo:
    # Escreve cada nome e número de quedas em uma linha do arquivo
    for nome, quedas, dataqueda in dados_quedas:
        arquivo.write(f"{nome},{quedas},{dataqueda}\n")

        

