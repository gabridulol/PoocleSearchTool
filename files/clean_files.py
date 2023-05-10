# Gabriel Rodrigues Marques - 5097
# Alan Araújo dos Reis - 5096
# Marcos Biscotto de Oliveira - 4236
# Luiz César Galvão Lima - 4216

import re # Operações com expressões regulares - Disponível em: https://docs.python.org/pt-br/3/library/re.html
def read_clean_file(src_filename): # Declaração da função read_clean_file que recebe como parâmetro o diretório do arquivo de entradas -> "files/entradas.txt"
    with open(src_filename, 'r') as src_file: # Abertura e leitura do arquivo -> "entradas.txt"
        src_text = src_file.readlines() # Armazena o arquivo "entradas.txt" na lists src_text -> ['N\n', 'arquivo1.txt\n', 'arquivo2.txt\n', ... , 'arquivoN.txt']
        src_text = [src_text.strip("\n") for src_text in src_text] # Remove o '\n' de cada item da lista src_text -> ['N', 'arquivo1.txt', 'arquivo2.txt'... 'arquivoN.txt']
        for i in range(1, len(src_text)): # Estrutura de repetição acessar os itens da lista src_text a partir do segundo elemento, acessando o nome dos arquivos
            filename = "files/" + src_text[i] # Atribui o diretório e o nome do arquivo específico a variável filename
            with open(filename, 'r') as file: # Abre o arquivo específico desta iteração, "arquivoN.txt", no modo leitura
                text = file.read() # Armazena tudo o que está escrito no arquivo na lista text
                text = re.sub(r'\W', ' ', text) # Remove qualquer caractere não alfanumérico de cada palavra através de expressões regulares do padrão \W
                text = text.lower().split() # Converte todas as palavavras para minúsculo através da função .lower e as separa com .split
                with open(filename, 'w') as file: # Abertura do mesmo arquivo, só que agora para escrita
                    pass # Limpa o arquivo a ser escrito
                    for text in text: # Estrutura de repetição para acessar cada palavra da lista text
                        file.write(text + '\n') # Escreve no arquivo a palavra no arquivo e salta uma linha
read_clean_file("files/entradas.txt") # Chamada da função read_clean_file passando o diretório do arquivo