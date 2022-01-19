#include <stdio.h>

int Safe = 0;

void DFS_Virus(int lab[64], bool init[64], int row, int col, int m)
{
	if (col == m)
	{
		row++;
		col = 0;
	}

	//상하좌우 0인지 1인지
	if (row > 0) // 상
	{
		if (lab[((row - 1) * 8) + col] == 3)
		{
			init[((row - 1) * 8) + col] = 1;
			lab[((row - 1) * 8) + col] = 2;
			DFS_Virus(lab, init, row - 1, col, m);
		}	
	}
	
	if (row < 7) // 하
	{
		if (lab[((row + 1) * 8) + col] == 3)
		{
			init[((row + 1) * 8) + col] = 1;
			lab[((row + 1) * 8) + col] = 2;
			DFS_Virus(lab, init, row + 1, col, m);
		}
	}

	if (col > 0) // 좌
	{
		if (lab[(row * 8) + col - 1] == 3)
		{
			init[(row * 8) + col - 1] = 1;
			lab[(row * 8) + col - 1] = 2;
			DFS_Virus(lab, init, row, col - 1, m);
		}
	}
	
	if (col < 7) // 우
	{
		if (lab[(row * 8) + col + 1] == 3)
		{
			init[(row * 8) + col + 1] = 1;
			lab[(row * 8) + col + 1] = 2;
			DFS_Virus(lab, init, row, col + 1, m);
		}
	}


}

int main()
{
	int Lab[8 * 8] = { 0, };
	int Virus[10][2];
	int V_Count = 0;
	int N, M;
	
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &Lab[(i * 8) + j]);
			
			if (Lab[(i * 8) + j] == 0)
				Lab[(i * 8) + j] = 3;
			
			if (Lab[(i * 8) + j] == 2)
			{
				Virus[V_Count][0] = i;
				Virus[V_Count++][1] = j;
			}
		}
	}
	
	
	for (int i = 0; i < 8 * 8; i++)
	{
		if (Lab[i] == 3)
		{	
			Lab[i] = 1;
		
			for (int j = i + 1; j < 8 * 8; j++)
			{
				if (Lab[j] == 3)
				{
					Lab[j] = 1;

					for (int k = j + 1; k < 8 * 8; k++)
					{
						if (Lab[k] == 3)
						{
							Lab[k] = 1;

							bool Init[8 * 8] = { false, };
							int Safe_Count = 0;
							// 시뮬레이션
							for (int l = 0; l < V_Count; l++)
								DFS_Virus(Lab, Init, Virus[l][0], Virus[l][1], M);

							for (int l = 0; l < 8 * 8; l++)
								if (Lab[l] == 3)
									Safe_Count++;

							if (Safe < Safe_Count)
								Safe = Safe_Count;

							for (int l = 0; l < 8 * 8; l++)
							{
								if (Init[l])
									Lab[l] = 3;
							}

							Lab[k] = 3;
						}
					}
					
					Lab[j] = 3;
				}
			}

			Lab[i] = 3;
		}
	}
	
	printf("%d", Safe);
}