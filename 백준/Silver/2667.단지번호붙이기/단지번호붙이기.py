Map = []
Houses = []
Count = 0

def DrawMap(n):
    global Map
    for i in range(n):
        Temp = []
        Temp.append(str(input()))
        Temp2 = []
        for j in range(n):
            Temp2.append(int(Temp[0][j]))
        Map.append(Temp2)

def DFS(i,j,n):
    global Map, Houses,Count

    if Map[i][j] == 0:
        return
    if Map[i][j] == 1:
        Count += 1
        Map[i][j] = 0

    if j < (n - 1) and Map[i][j + 1] == 1:
        DFS(i, j + 1, n)
    if i < (n - 1) and Map[i + 1][j] == 1:
        DFS(i + 1, j, n)
    if i > 0 and Map[i - 1][j] == 1:
        DFS(i - 1, j, n)
    if j > 0 and Map[i][j - 1] == 1:
        DFS(i, j - 1, n)


if __name__ == "__main__":

    N = int(input())
    DrawMap(N)

    for i in range(N):
        for j in range(N):
            DFS(i,j,N)
            if Count != 0 :
                Houses.append(Count)
            Count = 0

    Houses.sort()
    print(len(Houses))
    for i in range(len(Houses)):
        if Houses[i] != 0:
            print(Houses[i])