import random

cadenota = ""
enota = 17536 * 1000
while enota != 0:
    for x in range(3):
        cadenota += random.choice("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
    cadenota += " "
    enota -= 1

print("IPN aparace " + str(cadenota.count("IPN")))
