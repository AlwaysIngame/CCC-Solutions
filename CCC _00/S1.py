coins = int(input())
a = int(input())
b = int(input())
c = int(input())

counter = 0
while coins > 0:
    a += 1
    if a % 35 == 0:
        coins += 29
    else:
        coins -= 1
    counter += 1
    if coins == 0:
        break
    b += 1
    if b % 100 == 0:
        coins += 59
    else:
        coins -= 1
    counter += 1
    if coins == 0:
        break
    c += 1
    if c % 10 == 0:
        coins += 8
    else:
        coins -= 1
    counter += 1
print("Martha plays " + str(counter) + " times before going broke.")