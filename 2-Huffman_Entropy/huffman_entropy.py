from huffman import HuffmanCoding
from entropy import entropyCoding

path = "sql.html"

e = entropyCoding(path)

entropy = e.openfile()

print("Entropia antes de huffman:", entropy)

h = HuffmanCoding(path)

output_path = h.compress()

e = entropyCoding(output_path)

entropy = e.openfile()

print("Entropia depois de huffman:", entropy)
