def Line(num):
    cnt = 0
    l = str(input())
    if((num % 2) == 0):
        for i in range (0,8,2):
            if(l[i] == 'F'):
                cnt = cnt + 1
            elif(l[i] == '.'):pass
    elif((num % 2) == 1):
        for i in range (1,8,2):
            if(l[i] == 'F'):
                cnt = cnt + 1
            elif(l[i] == '.'):pass
    return cnt

Count = 0
for i in range (0,8):
    Count = Count + Line(i)
    
print(Count)
