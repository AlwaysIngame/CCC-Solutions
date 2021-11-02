lis = []
for _ in range(int(input())):
    lis.append(float(input()))

while True:
    inp = int(input())
    if inp == 77:
        break
    elif inp == 99:
        i = int(input())
        p = float(input())
        lis.insert(i, lis[i-1]*((100-p)/100))
        lis[i-1] *= p/100
    elif inp == 88:
        i = int(input())
        lis[i-1] += lis[i]
        lis.pop(i)

st = ""
for y in lis:
    st += str(int(y))
    st += " "
print(st)