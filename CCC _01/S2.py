import math

x,y = int(input()), int(input())

l = [_ for _ in range(x, y+1)]

length = 99
height = 99

printedlist = [["  " for i in range(length)] for j in range(height)]

startpointX = int(math.ceil(height/2)-1)
startpointY = int(length/2-1)

direction = 'D'
currentL = 1
left = currentL
printedlist[startpointX][startpointY] = l[0]
for i in l[1:]:
    if direction == 'D':
        startpointX += 1
        printedlist[startpointX][startpointY] = i
        left -= 1
        if left == 0:
            direction = 'R'
            left = currentL
    elif direction == 'R':
        startpointY += 1
        printedlist[startpointX][startpointY] = i
        left -= 1
        if left == 0:
            direction = 'U'
            currentL += 1
            left = currentL
    elif direction == 'U':
        startpointX -= 1
        printedlist[startpointX][startpointY] = i
        left -= 1
        if left == 0:
            direction = 'L'
            left = currentL
    elif direction == 'L':
        startpointY -= 1
        printedlist[startpointX][startpointY] = i
        left -= 1
        if left == 0:
            direction = 'D'
            currentL += 1
            left = currentL
        
for i in printedlist:
    print(" ".join([str(_) for _ in i]))
