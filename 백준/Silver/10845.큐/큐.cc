#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	cin.ignore();
	queue<string> q;

	for (int i = 0; i < N; i++) {
		
		string s;
		getline(cin, s);

		if (s == "pop") {
			if (q.size() == 0)
				cout << "-1" << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (s == "size")
			cout << q.size() << endl;
		else if (s == "empty")
			cout << (q.size() == 0 ? 1 : 0) << endl;
		else if (s == "front") {
			if (q.size())
				cout << q.front() << endl;
			else
				cout << -1 << endl;
		}
		else if (s == "back") {
			if (q.size())
				cout << q.back() << endl;
			else
				cout << -1 << endl;
		}
		else {
			s = s.substr(5);
			q.push(s);
		}
	}
}