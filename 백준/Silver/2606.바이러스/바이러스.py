CONN = []
Conn_Saved = []


def SetCONN(c, p):
    global CONN, Conn_Saved

    for i in range(c):
        Temp = []
        for j in range(c):
            Temp.append(int(0))
        CONN.append(Temp)
        Conn_Saved.append(int(0))
    for t in range(p):
        i, j = input().split()

        CONN[int(i) - 1][int(j) - 1] = 1
        CONN[int(j) - 1][int(i) - 1] = 1


def DFS(i, j, com):
    global CONN, Conn_Saved

    if CONN[i][j] == 1:
        CONN[i][j] = 0
        Conn_Saved[i - 1] = Conn_Saved[j - 1] = 1
        DFS(j, 0, com)

    if j == 0:
        for t in range(1, com):
            DFS(i, t, com)
    return

if __name__ == "__main__":

    Com = int(input())
    Pair = int(input())

    SetCONN(Com, Pair)
    DFS(0, 0, Com)

    All_Deconn = True
    Count = 0
    for i in range(len(Conn_Saved)):
        if Conn_Saved[i] == 1:
            Count += 1
            All_Deconn = False

    if All_Deconn == False:
        print(Count - 1)
    else:
        print(Count)