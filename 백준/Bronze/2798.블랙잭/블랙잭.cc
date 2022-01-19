#include <stdio.h>

int main()
{
	int Card[100];
	int N, M;
	int Max = 0;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &Card[i]);

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int Sum = Card[i] + Card[j];
			for (int k = j + 1; k < N; k++)
			{
				if (Max < Sum + Card[k] && Sum + Card[k] <= M)
					Max = Sum + Card[k];
			}
		}
	}

	printf("%d", Max);
}