#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int sum = 0;
    
    for (int i = 0; i < s.size(); i++) {
        string num = "";
        if (s[i] == '-') {
            for (int j = i + 1; j < s.size(); i++,j++) {
                if (s[j] == '-') {
                    i = j - 1;
                    break;
                }
                else if (s[j] == '+') {
                    sum -= stoi(num);
                    num = "";
                }
                else {
                    num += s[j];
                }
            }
            sum -= stoi(num);
        }
        else if (s[i] == '+') {
            string num = "";

            for (int j = i + 1; j < s.size(); i++, j++) {
                if (s[j] == '-' || s[j] == '+') {
                    i = j - 1;
                    break;
                }
                else {
                    num += s[j];
                }
            }

            sum += stoi(num);

        }
        else {
            for (int j = i; j < s.size(); i++, j++) {
                if (s[j] == '-' || s[j] == '+') {
                    i = j - 1;
                    break;
                }
                else {
                    num += s[j];
                }
            }

            sum += stoi(num);
        }
    }

    cout << sum;
}