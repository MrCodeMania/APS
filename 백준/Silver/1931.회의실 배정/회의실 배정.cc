#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    
    sort(v.begin(), v.end());
    
    int count = 1;
    pair<int, int> last;
    last = v[0];
    
    for (int i = 1; i < v.size(); i++) {
        if (last.first <= v[i].first && last.first <= v[i].second) {
            count++;
            last = v[i];
            continue;
        }

    }
    cout << count << "\n";
}