using System;

class Sudoku
{
    int[,] puzzle = new int[9, 9];
    bool[,] horizontal = new bool[9, 9];
    bool[,] vertical = new bool[9, 9];
    bool[,] square = new bool[9, 9];

    void init()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                puzzle[i, j] = Console.Read() - '0';
                if (puzzle[i, j] > 0)
                {
                    horizontal[i, puzzle[i, j] - 1] = true;
                    vertical[j, puzzle[i, j] - 1] = true;
                    square[(i / 3) * 3 + (j / 3), puzzle[i, j] - 1] = true;
                }
                Console.Read();
            }
        }
    }

    void DFS(int cnt)
    {
        int r = cnt / 9;
        int c = cnt % 9;

        if (cnt == 81)
        {
            // 출력 및 종료
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                    Console.Write("{0} ", puzzle[i, j]);

                Console.Write("\n");
            }

            Environment.Exit(0);
        }

        if (puzzle[r, c] == 0)
        {
            for (int i = 0; i < 9; i++)
            {
                if (!horizontal[r, i] && !vertical[c, i] && !square[(r / 3) * 3 + (c / 3), i])
                {
                    horizontal[r, i] = true;
                    vertical[c, i] = true;
                    square[(r / 3) * 3 + (c / 3), i] = true;
                    puzzle[r, c] = i + 1;

                    DFS(cnt + 1);

                    horizontal[r, i] = false;
                    vertical[c, i] = false;
                    square[(r / 3) * 3 + (c / 3), i] = false;
                    puzzle[r, c] = 0;
                }
            }
        }
        else DFS(cnt + 1);
    }

    static void Main()
    {
        Sudoku S = new Sudoku();

        S.init();

        S.DFS(0);
    }
}