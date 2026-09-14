from cs50 import get_float

while True:
    cents = get_float("Cash: ")
    if cents > 0:
        break

coins = 0

cents = round(cents * 100)

if cents >= 25:
    coins += cents // 25
    cents %= 25

if cents >= 10:
    coins += cents // 10
    cents %= 10

if cents >= 5:
    coins += cents // 5
    cents %= 5

if cents >= 1:
    coins += cents // 1
    cents %= 1

print(coins)
