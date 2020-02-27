import math

fA = [0, 0, 0, 0, 0]
ff = [math.sin, math.cos, math.tan, math.log, math.sqrt]
i = 1
enota = 30000000

while i < enota:
    for x in range(5):
        fA[x] += ff[x](i)
    i += 1

for x in range(5):
    print(fA[x])