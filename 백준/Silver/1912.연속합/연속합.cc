#include <iostream>
#include <vector>

using namespace std;

class SequentialSum
{
private:
	vector<int> DP;
	int Max = -10000;
	int Size;
public:
	SequentialSum(int n);
	int getMax();
};

SequentialSum::SequentialSum(int n)
{
	this->Size = n;
	for (int i = 0; i < this->Size; i++)
	{
		int x;
		cin >> x;
        this->DP.push_back(x);
        
		if (this->Max < x)
			this->Max = x;
	}
}

int SequentialSum::getMax()
{
	for (int i = 1; i < this->Size; i++)
	{
        if(this->DP[i-1] > 0)
            this->DP[i] += this->DP[i-1];
        else
            continue;
        if (this->Max < this->DP[i])
	    	this->Max = this->DP[i];
    }
    
    
	return this->Max;
}

int main()
{
	int s;
	cin >> s;

	SequentialSum S(s);

	cout << S.getMax();
	
	return 0;
}