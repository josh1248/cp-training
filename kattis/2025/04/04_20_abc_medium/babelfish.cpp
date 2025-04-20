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

    string s;
    unordered_map<string, string> f_to_local;
    while (getline(cin, s)) {
        if (sz(s) == 0 || s.find(' ') == string::npos) break;
        string l = s.substr(0, s.find(' ')),
            r = s.substr(s.find(' ') + 1);
        f_to_local[r] = l;
    }

    while (getline(cin, s)) {
        cout << (f_to_local.count(s) == 0 ? "eh" : f_to_local[s]) << "\n";
    }
}