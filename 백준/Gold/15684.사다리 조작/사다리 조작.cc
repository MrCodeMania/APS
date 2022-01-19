#include <stdio.h>

int Min = 4;

bool Check(bool visited [300], int n, int h)
{
	// 사다리 타본다 
	bool Normal = true;
	for (int i = 0; i < n; i++)
	{
		int Line = i;
		for (int j = 0; j < h; j++)
		{
			// 오른쪽으로 가는 루트가 있는지만 본다
			if (Line == 0)
			{
				if (visited[j * (n - 1) + Line])
					Line++;
			}
			// 왼쪽으로 가는 루트가 있는지만 본다
			else if (Line == n - 1)
			{
				if (visited[j * (n - 1) + Line - 1])
					Line--;
			}
			// 양쪽 루트가 있는지 본다
			else
			{
				if (visited[j * (n - 1) + Line])
					Line++;
				else if (visited[j * (n - 1) + Line - 1])
					Line--;
			}
		}

		if (Line != i)
		{
			Normal = false;
			break;
		}
	}

	return Normal;
}

int main()
{

	int N, M, H;
	scanf("%d%d%d", &N, &M, &H);

	bool Ladders[300] = { false, };

	for (int i = 0; i < M; i++)
	{
		int r, c;
		scanf("%d%d", &r, &c);

		Ladders[(r - 1) * (N - 1) + (c - 1)] = true;
	}

	bool Normal = Check(Ladders, N, H);

	// 1 -> 2 -> 3 사다리 개수 늘리기
	// for(i = 0; i < 3; i++)
	// true -> Check() -> false;
	// 4중 포문
	// i,j,k
	if (!Normal)
	{
		for (int Time = 1; Time <= 3; Time++)
		{
			for (int i = 0; i < H * (N - 1); i++)
			{
				if (Ladders[i])
					continue;
				else
				{
					if ((i % (N - 1)) == 0 && (i % (N - 1)) == N - 2)
					{
						Ladders[i] = true;

						if (Time == 1)
							Normal = Check(Ladders, N, H);
					}
					else if ((i % (N - 1)) == 0)
					{
						if (!Ladders[i + 1])
						{
							Ladders[i] = true;

							if (Time == 1)
								Normal = Check(Ladders, N, H);
						}
					}
					else if ((i % (N - 1)) == N - 2)
					{
						if (!Ladders[i - 1])
						{
							Ladders[i] = true;

							if (Time == 1)
								Normal = Check(Ladders, N, H);
						}
					}
					else
					{
						if (!Ladders[i + 1] && !Ladders[i - 1])
						{
							Ladders[i] = true;

							if (Time == 1)
								Normal = Check(Ladders, N, H);
						}
					}

					if (Time >= 2 && Ladders[i])
					{
						for (int j = i + 1; j < H * (N - 1); j++)
						{
							if (Ladders[j])
								continue;
							else
							{
								if ((j % (N - 1)) == 0 && (j % (N - 1)) == N - 2)
								{
									Ladders[j] = true;

									if (Time == 2)
										Normal = Check(Ladders, N, H);
								}
								else if ((j % (N - 1)) == 0)
								{
									if (!Ladders[j + 1])
									{
										Ladders[j] = true;

										if (Time == 2)
											Normal = Check(Ladders, N, H);
									}
								}
								else if ((j % (N - 1)) == N - 2)
								{
									if (!Ladders[j - 1])
									{
										Ladders[j] = true;

										if (Time == 2)
											Normal = Check(Ladders, N, H);
									}
								}
								else
								{
									if (!Ladders[j + 1] && !Ladders[j - 1])
									{
										Ladders[j] = true;

										if (Time == 2)
											Normal = Check(Ladders, N, H);
									}
								}
								
								if (Time == 3 && Ladders[j])
								{
									for (int k = j + 1; k < H * (N - 1); k++)
									{
										if (Ladders[k])
											continue;
										else
										{
											if ((k % (N - 1)) == 0 && (k % (N - 1)) == N - 2)
											{
												Ladders[k] = true;

												Normal = Check(Ladders, N, H);
											}
											else if ((k % (N - 1)) == 0)
											{
												if (!Ladders[k + 1])
												{
													Ladders[k] = true;

													Normal = Check(Ladders, N, H);
												}
											}
											else if ((k % (N - 1)) == N - 2)
											{
												if (!Ladders[k - 1])
												{
													Ladders[k] = true;

													Normal = Check(Ladders, N, H);
												}
											}
											else
											{
												if (!Ladders[k + 1] && !Ladders[k - 1])
												{
													Ladders[k] = true;

													Normal = Check(Ladders, N, H);
												}
											}

											if (Normal && Min > Time)
											{
												Min = Time;
												break;
											}
										
											Ladders[k] = false;
										}
									}
								}

								if (Normal && Min > Time)
								{
									Min = Time;
									break;
								}

								Ladders[j] = false;
							}
						}
					}
					
					if (Normal && Min > Time)
					{
						Min = Time;
						break;
					}

					Ladders[i] = false;
				}
			}
		}

		if (Min == 4)
			printf("-1");
		else
			printf("%d", Min);
	}
	else
		printf("0");
}