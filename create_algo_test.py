import random

with open("test.inc", "w+", encoding="UTF-8") as f:
    f.write(f"int pole[10][10000] = ")
    f.write("{\n")
    for x in range(10):
        f.write("{")
        for i in range(10_000-1):
            f.write(f"{random.randint(-100000, 1000000)}, ")
        f.write(f"{random.randint(-100000, 1000000)} ")
        f.write("}")
        if x!=9:
            f.write(",\n")
    f.write("\n};\n")
