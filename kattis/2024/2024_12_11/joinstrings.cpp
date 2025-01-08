#include <iostream>
#include <algorithm> // sort
#include <map>
#include <numeric> // accumulate
#include <set>
#include <vector>
using namespace std;
using vi = vector<int>;

int main() {
    map<int, vi> m;
    int x;
    cin >> x;
    vector<string> t;
    string y;
    t.push_back("junk");
    for (int i = 0; i < x; i++) {
        cin >> y;
        t.push_back(y); 
    }

    set<int> left;
    for (int i = 0; i < x; i++) {
        left.insert(i + 1);
        m[i + 1] = vector<int>({i + 1});
    }

    for (int i = 0; i < x - 1; i++) {
        int a, b;
        cin >> a >> b;
        left.erase(b);
        m[a].insert(m[a].end(), m[b].begin(), m[b].end());
        m.erase(b);
    }

    for (int i: left) {
        for (int k: m[i]) {
            cout << t[k];
        }
        cout << "\n";
    }
}