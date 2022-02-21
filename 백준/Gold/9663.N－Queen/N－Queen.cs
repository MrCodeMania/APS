using System;
using System.Collections.Generic;

class Problem
{

	public int[,] board = new int[15, 15];
	public int count = 0;

	public bool getPossible(int r, int n)
	{
		for (int i = 0; i < n; i++)
		{
			if (board[r + 1, i] == 0)
				return true;
		}

		return false;
	}


	public void DFS(int q, int n)
	{
		if (q == n - 1)
		{
			count++;
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (board[q, i] == 0)
			{
				// 색칠
				board[q, i] = 1;

				for (int j = -1; j < 2; j++)
				{
					int nR = q + 1;
					int nC = i + j;
					while (true)
					{
						if (nR >= n || nC < 0 || nC >= n)
							break;

						board[nR++, nC] += 1;
						nC += j;
					}
				}

				// 선탐색
				if (getPossible(q, n))
					DFS(q + 1, n);

				// 색칠 취소
				board[q, i] = 0;

				for (int j = -1; j < 2; j++)
				{
					int nR = q + 1;
					int nC = i + j;
					while (true)
					{
						if (nR >= n || nC < 0 || nC >= n)
							break;

						board[nR++, nC] -= 1;
						nC += j;
					}
				}

			}
		}

	}

	public static void Main()
	{
		int N = int.Parse(Console.ReadLine());

		Problem P = new Problem();

		P.DFS(0, N);

		Console.Write(P.count);
	}

}