N = int(input())

Count = 0
    
for i in range(1,N + 1):
    if (i < 100):
        Count += 1
    elif (i < 1000):
        temp = str(i)
        a, b, c = temp[0], temp[1], temp[2]
        a, b, c = int(a),int(b),int(c) 
        if a - b == b - c: 
            Count += 1
        else:
            pass

print(Count)
