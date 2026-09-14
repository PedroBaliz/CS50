from cs50 import get_int

# pedir altura válida
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

# construir pirâmide
for i in range(height):

    # espaços
    for s in range(height - i - 1):
        print(" ", end="")

    # #
    for c in range(i + 1):
        print("#", end="")

    print()
