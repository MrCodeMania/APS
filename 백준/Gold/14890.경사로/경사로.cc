#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;

	int Map[100][100] = { 0, };
	bool Visit[100][100] = { false, };

	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		bool Ok = true;
		
		for (int j = 1; j < N; j++)
		{
			if (!Ok)
				break;

			if (Map[i][j] == Map[i][j - 1])
				continue;

			// 작을 때
			else if (Map[i][j] == Map[i][j - 1] + 1)
			{
				int Count = 0;
				int Index = j - 1;
				int Value = Map[i][j - 1];
				vector<int> IndexList;
				while (++Count <= L && Index >= 0)
				{
					if (Value != Map[i][Index] || Visit[i][Index])
					{
						Ok = false;
						break;
					}
					else if (!Visit[i][Index])
						IndexList.push_back(Index);

					Index--;
				}

				if (Ok && IndexList.size() == L)
				{
					for (int k = 0; k < IndexList.size(); k++)
						Visit[i][IndexList[k]] = true;
				}
				else Ok = false;
			}
			// 클 때
			else if (Map[i][j] == Map[i][j - 1] - 1)
			{
				int Count = 0;
				int Index = j;
				int Value = Map[i][j];
				vector<int> IndexList;
				while (++Count <= L && Index < N)
				{
					if (Value != Map[i][Index] || Visit[i][Index])
					{
						Ok = false;
						break;
					}
					else if (!Visit[i][Index])
						IndexList.push_back(Index);

					Index++;
				}

				if (Ok && IndexList.size() == L)
				{
					for (int k = 0; k < IndexList.size(); k++)
						Visit[i][IndexList[k]] = true;
				}
				else Ok = false;
			}

			else
				Ok = false;
		}

		if (Ok)
			Answer++;
	}

	bool Visit2[100][100] = { false, };

	for (int i = 0; i < N; i++)
	{
		bool Ok = true;

		for (int j = 1; j < N; j++)
		{
			if (!Ok)
				break;

			if (Map[j][i] == Map[j - 1][i])
				continue;

			// 작을 때
			else if (Map[j][i] == Map[j - 1][i] + 1)
			{
				int Count = 0;
				int Index = j - 1;
				int Value = Map[j - 1][i];
				vector<int> IndexList;
				while (++Count <= L && Index >= 0)
				{
					if (Value != Map[Index][i] || Visit2[Index][i])
					{
						Ok = false;
						break;
					}
					else if (!Visit2[Index][i])
						IndexList.push_back(Index);
					
					Index--;
				}

				if (Ok && IndexList.size() == L)
				{
					for (int k = 0; k < IndexList.size(); k++)
						Visit2[IndexList[k]][i] = true;
				}
				else Ok = false;
			}
			// 클 때
			else if (Map[j][i] == Map[j - 1][i] - 1)
			{
				int Count = 0;
				int Index = j;
				int Value = Map[j][i];
				vector<int> IndexList;
				while (++Count <= L && Index < N)
				{
					if (Value != Map[Index][i] || Visit2[Index][i])
					{
						Ok = false;
						break;
					}
					else if (!Visit2[Index][i])
						IndexList.push_back(Index);
					
					Index++;
				}

				if (Ok && IndexList.size() == L) 
				{
					for (int k = 0; k < IndexList.size(); k++)
						Visit2[IndexList[k]][i] = true;
				}
				else Ok = false;
			}

			else
				Ok = false;
		}

		if (Ok)
			Answer++;
	}

	cout << Answer;
}