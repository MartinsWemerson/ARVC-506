from flask import Flask, render_template

app = Flask(__name__, template_folder='templateFiles', static_folder='staticFiles')

@app.route('/')
def index():
    # Lê os dados do arquivo
    with open("quedas.txt", "r") as arquivo:
        dados_quedas = arquivo.readlines()
    
    # Processa os dados
    dados_quedas = [linha.strip().split(",") for linha in dados_quedas]
    dados_quedas = [(nome, int(quedas), dataqueda) for nome, quedas, dataqueda in dados_quedas]

    # Renderiza o template HTML e passa os dados
    return render_template('index.html', dados_quedas=dados_quedas)

if __name__ == '__main__':
    app.run(debug=True)

##, template_folder='templateFiles', static_folder='staticFiles')    =