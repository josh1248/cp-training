#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pi;
typedef long long ll;

#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int idx = 0;
    string s;
    while (getline(cin, s)) {
        int t = stoi(s);
        if (t == 0) return 0;
        idx++;
        cout << "List " << idx << ":\n";
        map<string, int> m;
        rep(i, 0, t) {
            string x; getline(cin, x);
            stringstream ss(x);
            string prev;
            while (ss >> prev) {}
            for (char &c: prev) {
                c = tolower(c);
            }
            if (m.count(prev) == 0) m[prev] = 0;
            m[prev]++;
        }
        for (auto& [k, v]: m) {
            cout << k << " | " << v << "\n";
        }
    }
}