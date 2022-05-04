#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(string p)
{
	int stack = 0;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == '(')
			stack++;
		else
			stack--;

		if (stack < 0)
			return false;
	}

	return true;
}

string DFS(string s)
{
	string u, v;

	// 1. 빈 문자열인지 검사
	if (s.empty())
		return s;

	// 2. u, v 나누기
	int Count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			Count++;
		else
			Count--;

		if (Count == 0)
		{
			u = s.substr(0, i + 1);
            
            v = s.substr(u.size(), s.size() - u.size());
            
			break;
		}
	}

	// 3.
	if (Check(u))
		return u + DFS(v);
	
	//4.
	else
	{
		string temp = "(";
		temp += DFS(v);
		temp += ")";
		
		u = u.substr(1, u.size() - 2);
		for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
		
		temp += u;
        
        return temp;
	}
    
    return s;
}

string solution(string p) {
	
	string answer = DFS(p);

	return answer;
}