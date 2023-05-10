# Gabriel Rodrigues Marques - 5097
# Alan Araújo dos Reis - 5096
# Marcos Biscotto de Oliveira - 4236
# Luiz César Galvão Lima - 4216

import re
def read_clean_file(src_filename):
    with open(src_filename, 'r') as src_file:
        src_text = src_file.readlines()
        src_text = [src_text.strip("\n") for src_text in src_text]
        for i in range(1, len(src_text)):
            filename = "files/" + src_text[i]
            with open(filename, 'r') as file:
                text = file.read()
                text = re.sub(r'\W+', ' ', text)
                text = text.lower().split()
                with open(filename, 'w') as file:
                    pass
                    for text in text:
                        file.write(text + '\n')
read_clean_file("files/entradas.txt")